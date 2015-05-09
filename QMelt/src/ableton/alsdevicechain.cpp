// ABLETON
#include "src/ableton/alsdevicechain.h"
#include "src/io/alsfilestreambase.h"

M_NAMESPACE_ABLETON_BEGIN


AlsDeviceChain::AlsDeviceChain()
{
  _tagName = "DeviceChain";
}

void AlsDeviceChain::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  writeStartTag(p_fos_, _tagName, QHash<QString, QString>(), r_indentLvl_);
  p_fos_->write(_garbage);
  writeEndTag(p_fos_, _tagName, r_indentLvl_);
}

AlsDeviceChain::~AlsDeviceChain()
{

}


M_NAMESPACE_ABLETON_END
