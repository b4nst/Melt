// UI
#include "src/ui/mainwindow.h"

#include "src/test/melttestcore.h"

namespace ui
{


MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
{
  test::MeltTestCore::testParser();
}

MainWindow::~MainWindow()
{
}


} // namespace ui
