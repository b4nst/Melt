// ABLETON
#include "src/ableton/alsdevicechain.h"

M_NAMESPACE_ABLETON_BEGIN


AlsDeviceChain::AlsDeviceChain(QObject *parent)
: AbletonObject(parent)
{
  _tagName = "DeviceChain";
}

void AlsDeviceChain::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  writeStartTag(p_fos_, _tagName, QList<QPair<QString,QString>>(), r_indentLvl_);
  writeGarbage(p_fos_);
  writeEndTag(p_fos_, _tagName, r_indentLvl_);
}

AlsDeviceChain::~AlsDeviceChain()
{

}


M_NAMESPACE_ABLETON_END
