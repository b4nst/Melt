#include "meltui.h"
#include "ui_meltui.h"

MeltUI::MeltUI(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MeltUI)
{       
  ui->setupUi(this);
  this->setWindowTitle("Melt");

  // Get the information about tracks (number, name, etc)


  QStandardItemModel* clipsModel = new QStandardItemModel(10,20);
  ui->tableView->setModel(clipsModel);

}

MeltUI::~MeltUI()
{
  delete ui;
}
