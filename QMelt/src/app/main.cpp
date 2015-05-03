#include "src/ui/mainwindow.h"
#include "src/app/meltapplication.h"

int main(int argc, char *argv[])
{
    MeltApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
