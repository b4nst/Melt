#include "meltui.h"
#include "ui_meltui.h"

MeltUI::MeltUI(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MeltUI)
{
  ui->setupUi(this);


}

MeltUI::~MeltUI()
{
  delete ui;
}
