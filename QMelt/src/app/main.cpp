// APP
#include "src/app/meltapplication.h"

// UI
#include "src/ui/meltui.h"

// ABLETON
#include "src/ableton/alsname.h"
#include "src/ableton/alstrackdelay.h"
#include "src/ableton/alsclipslot.h"
#include "src/ableton/alsclipslotvalue.h"
#include "src/ableton/alsinnerclipslot.h"
#include "src/ableton/alsmainsequencer.h"
#include "src/ableton/alsmidiclip.h"

#include "src/test/melttestcore.h"

int main(int argc, char *argv[])
{
    qRegisterMetaType<QSharedPointer<ableton::AlsName>>("QSharedPointer<AlsName>");
    qRegisterMetaType<QSharedPointer<ableton::AlsTrackDelay>>("QSharedPointer<AlsTrackDelay>");
    qRegisterMetaType<QSharedPointer<ableton::AlsClipSlot>>("QSharedPointer<AlsClipSlot>");
    qRegisterMetaType<QVector<QSharedPointer<ableton::AlsClipSlot>>>("QVector<QSharedPointer<AlsClipSlot>>");
    qRegisterMetaType<QSharedPointer<ableton::AlsClipSlotValue>>("QSharedPointer<AlsClipSlotValue>");
    qRegisterMetaType<QSharedPointer<ableton::AlsInnerClipSlot>>("QSharedPointer<AlsInnerClipSlot>");
    qRegisterMetaType<QSharedPointer<ableton::AlsMainSequencer>>("QSharedPointer<AlsMainSequencer>");
    qRegisterMetaType<QSharedPointer<ableton::AlsMidiClip>>("QSharedPointer<AlsMidiClip>");

    app::MeltApplication a(argc, argv);
    test::MeltTestCore::testParser();
    MeltUI ui(a);
  
    ui.showMaximized();
    return a.exec();
}
