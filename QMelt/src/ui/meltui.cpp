#include "meltui.h"
#include "ui_meltui.h"

MeltUI::MeltUI(app::MeltApplication& app_, QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MeltUI)
, _app(app_)
{       
  ui->setupUi(this);
  this->setWindowTitle("Melt");

}

MeltUI::~MeltUI()
{
  delete ui;
}
