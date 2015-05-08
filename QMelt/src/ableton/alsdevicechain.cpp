// ABLETON
#include "src/ableton/alsdevicechain.h"


M_NAMESPACE_ABLETON_BEGIN


AlsDeviceChain::AlsDeviceChain() : AbletonObject()
{
  _tagName = "DeviceChain";
}

void AlsDeviceChain::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  //TODO implement method write
}

AlsDeviceChain::~AlsDeviceChain()
{

}


M_NAMESPACE_ABLETON_END
