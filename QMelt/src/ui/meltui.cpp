#include "src/ui/meltui.h"
#include "ui_meltui.h"
#include "src/app/meltcommandline.h"
#include "src/ableton/alsableton.h"
#include "src/ableton/alsliveset.h"
#include "src/ableton/alsname.h"
#include "src/ableton/alsmiditrack.h"
#include "src/ableton/alsdevicechain.h"
#include "src/ableton/alsclipslot.h"
#include "src/ableton/alsclipslotvalue.h"
#include "src/ableton/alsinnerclipslot.h"
#include "src/ableton/alsmidiclip.h"
#include "src/ableton/alsmainsequencer.h"
#include "src/utils/colormap.h"
#include "src/diff/matchengine.h"
#include "src/diff/matchresult.h"
#include "src/diff/match.h"
#include "src/diff/depthfirsttraversal.h"

MeltUI::MeltUI(app::MeltApplication& app_, QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MeltUI)
, _app(app_)

{       
  ui->setupUi(this);
  this->setWindowTitle("Melt");
  this->setStyleSheet("background-color: rgb(127,127,127);");
  ui->tabWidget->tabBar()->setTabTextColor(0,Qt::white);
  ui->tabWidget->tabBar()->setTabTextColor(1,Qt::white);
  ui->tabWidget->tabBar()->setTabTextColor(2,Qt::white);

  if (_app.Arguments->isOk)
  {
    _remote = _app.getRemote();
    _local = _app.getLocal();
    _base= _app.getBase();
    _merge= _app.getMerge();

    ui->localCreatorValue->setText(_local->Creator);
    ui->localMinorValue->setText(_local->MinorVersion);
    ui->localMajorValue->setText(_local->MajorVersion);
    ui->localSchemaCCValue->setText(QString::number(_local->SchemaChangeCount));

    ui->remoteCreatorValue->setText(_remote->Creator);
    ui->remoteMinorValue->setText(_remote->MinorVersion);
    ui->remoteMajorValue->setText(_remote->MajorVersion);
    ui->remoteSchemaCCValue->setText(QString::number(_remote->SchemaChangeCount));

    _p_localClipsModel = new QStandardItemModel(8,_local->LiveSet->Tracks.size());
    _p_remoteClipsModel = new QStandardItemModel(8,_remote->LiveSet->Tracks.size());

    diff::DepthFirstTraversal dft;
    QVector<QObject*> leftVector (dft.traverse(_local->LiveSet.data()));
    QVector<QObject*> rightVector (dft.traverse(_remote->LiveSet.data()));
    diff::MatchEngine me;
    QSharedPointer<diff::MatchResult> matchResult = me.match(leftVector, rightVector);
    // TODO: use the match result for drawing clips
    initModel(_p_localClipsModel,_local->LiveSet, matchResult);
    initModel(_p_remoteClipsModel,_remote->LiveSet, matchResult);

    ui->tableView->setModel(_p_localClipsModel);
  }
}

void MeltUI::initModel(QStandardItemModel *p_model_, QSharedPointer<ableton::AlsLiveSet> liveSet_,
                       QSharedPointer<diff::MatchResult> matchResult_)
{
  for (int i = 0; i < liveSet_->Tracks.size(); ++i)
  {
    p_model_->setHorizontalHeaderItem(i,new QStandardItem(liveSet_->Tracks.at(i)->Name->EffectiveName));
    QSharedPointer<ableton::AlsMidiTrack> mt;
    if ((mt = liveSet_->Tracks.at(i).dynamicCast<ableton::AlsMidiTrack>()) != nullptr) {
      for (int j = 0; j < mt->DeviceChain->MainSequencer->ClipSlotList.size(); ++j) {
        QSharedPointer<ableton::AlsClipSlotValue> csv = mt->DeviceChain->MainSequencer->ClipSlotList.at(j)->InnerClipSlot->Value;
        if (csv != nullptr && csv->MidiClip != nullptr)
        {
          QStandardItem *clipItem = new QStandardItem(csv->MidiClip->Name);
          clipItem->setBackground(QBrush(utils::colors[csv->MidiClip->ColorIndex]));
          p_model_->setItem(j,i,clipItem);
        }
      }
    }
  }
}

void MeltUI::loadLocal()
{
  ui->tableView->setModel(_p_localClipsModel);
}

void MeltUI::loadRemote()
{
  ui->tableView->setModel(_p_remoteClipsModel);
}

MeltUI::~MeltUI()
{
  delete ui;
}
