// APP
#include "src/app/meltapplication.h"


// UI
#include "src/ui/mainwindow.h"


int main(int argc, char *argv[])
{
    app::MeltApplication a(argc, argv);
    ui::MainWindow w;
    w.show();

    return a.exec();
}
