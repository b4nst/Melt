// APP
#include "src/app/melt.h"
#include "src/app/meltcommandline.h"

// UI
#include "src/ui/meltui.h"

int main(int argc, char *argv[])
{
    /*
    qRegisterMetaType<QSharedPointer<ableton::AlsName>>("QSharedPointer<AlsName>");
    qRegisterMetaType<QSharedPointer<ableton::AlsTrackDelay>>("QSharedPointer<AlsTrackDelay>");
    qRegisterMetaType<QSharedPointer<ableton::AlsClipSlot>>("QSharedPointer<AlsClipSlot>");
    qRegisterMetaType<QVector<QSharedPointer<ableton::AlsClipSlot>>>("QVector<QSharedPointer<AlsClipSlot>>");
    qRegisterMetaType<QSharedPointer<ableton::AlsClipSlotValue>>("QSharedPointer<AlsClipSlotValue>");
    qRegisterMetaType<QSharedPointer<ableton::AlsInnerClipSlot>>("QSharedPointer<AlsInnerClipSlot>");
    qRegisterMetaType<QSharedPointer<ableton::AlsMainSequencer>>("QSharedPointer<AlsMainSequencer>");
    qRegisterMetaType<QSharedPointer<ableton::AlsMidiClip>>("QSharedPointer<AlsMidiClip>");
    */
    QApplication a (argc, argv);
    app::MeltCommandLine cmd;
    cmd.parse(a.arguments());

    app::Melt melt (cmd);
    MeltUI ui(melt);
  
    ui.showMaximized();
    return a.exec();
}
