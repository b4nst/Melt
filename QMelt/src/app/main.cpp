// APP
#include "src/app/melt.h"
#include "src/app/meltcommandline.h"

// UI
#include "src/ui/meltui.h"

// QT
#include <QDebug>
#include <QApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QApplication a (argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    app::MeltCommandLine cmd = app::MeltCommandLine::parse(a.arguments());

    app::Melt melt (cmd);
    return a.exec();
}
