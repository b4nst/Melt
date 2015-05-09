#ifndef MELTUI_H
#define MELTUI_H

#include <QMainWindow>

namespace Ui {
  class MeltUI;
}

class MeltUI : public QMainWindow
{
  Q_OBJECT

public:
  explicit MeltUI(QWidget *parent = 0);
  ~MeltUI();

private:
  Ui::MeltUI *ui;
};

#endif // MELTUI_H
