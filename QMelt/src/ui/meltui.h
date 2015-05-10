#pragma once

// APP
#include "src/app/meltapplication.h"

// QT
#include <QMainWindow>
#include <QStandardItemModel>

#include "common.h"

M_FORWARD_ABLETON(AlsLiveSet)

namespace Ui {
  class MeltUI;
}

class MeltUI : public QMainWindow
{
  Q_OBJECT

public:
  explicit MeltUI(app::MeltApplication& app_, QWidget *parent = 0);
  ~MeltUI();

public slots:
  void loadLocal();
  void loadRemote();

private:
  Ui::MeltUI *ui;
  app::MeltApplication& _app;
  QSharedPointer<ableton::AlsAbleton> _remote;
  QSharedPointer<ableton::AlsAbleton> _local;
  QSharedPointer<ableton::AlsAbleton> _base;
  QSharedPointer<ableton::AlsAbleton> _merge;
  QStandardItemModel *_p_localClipsModel;
  QStandardItemModel *_p_remoteClipsModel;
  void initModel(QStandardItemModel* p_model_, QSharedPointer<ableton::AlsLiveSet> liveSet_);
};
