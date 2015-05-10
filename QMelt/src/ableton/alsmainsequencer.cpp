// ABLETON
#include "src/ableton/alsmainsequencer.h"
#include "src/ableton/alsclipslot.h"


M_NAMESPACE_ABLETON_BEGIN


AlsMainSequencer::AlsMainSequencer(QObject *parent) :
  AbletonObject(parent)
{
  _classManipulator = decltype(_classManipulator){
      { "ClipSlot", qMakePair(static_cast<CreateVarLambda>(&AlsMainSequencer::createClipSlot), nullptr) },
      { "ClipSlotList", qMakePair(static_cast<CreateVarLambda>(&AlsMainSequencer::createClipSlotList), nullptr) }
  };

  _tagName = "MainSequencer";
}

QSharedPointer<QObject> AlsMainSequencer::createClipSlotList()
{
  ClipSlotList.clear();
  return QSharedPointer<QObject>();
}

QSharedPointer<QObject> AlsMainSequencer::createClipSlot()
{
  QSharedPointer<AlsClipSlot> cs = QSharedPointer<AlsClipSlot>(new AlsClipSlot(this));
  ClipSlotList.append(cs);
  return cs.staticCast<QObject>();
}

void AlsMainSequencer::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  writeStartTag(p_fos_,_tagName,QList<QPair<QString, QString>>(),r_indentLvl_);
  ++r_indentLvl_;
  writeStartTag(p_fos_,"ClipSlotList",QList<QPair<QString, QString>>(),r_indentLvl_);
  ++r_indentLvl_;
  foreach (auto cs, ClipSlotList) {
    cs->write(p_fos_,r_indentLvl_);
  }
  --r_indentLvl_;
  writeEndTag(p_fos_,"ClipSlotList",r_indentLvl_);
  writeGarbage(p_fos_);
  --r_indentLvl_;
  writeEndTag(p_fos_,_tagName,r_indentLvl_);
}


AlsMainSequencer::~AlsMainSequencer()
{

}


M_NAMESPACE_ABLETON_END
