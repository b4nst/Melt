#include "alsclipslot.h"

M_NAMESPACE_ABLETON_BEGIN

AlsClipSlot::AlsClipSlot(QObject * parent) :
  AbletonObject(parent)
{

}

AlsClipSlot::~AlsClipSlot()
{

}

void AlsClipSlot::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{

}

M_NAMESPACE_ABLETON_END
