#pragma once

// APP
#include "src/app/meltapplication.h"

// QT
#include <QMainWindow>
#include <QStandardItemModel>

namespace Ui {
  class MeltUI;
}

class MeltUI : public QMainWindow
{
  Q_OBJECT

public:
  explicit MeltUI(app::MeltApplication& app_, QWidget *parent = 0);
  ~MeltUI();

private:
  Ui::MeltUI *ui;
  app::MeltApplication& _app;
  QSharedPointer<ableton::AlsAbleton> _remote;
  QSharedPointer<ableton::AlsAbleton> _local;
  QSharedPointer<ableton::AlsAbleton> _base;
  QSharedPointer<ableton::AlsAbleton> _merge;
};
