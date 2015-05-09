#pragma once

// ABLETON
#include "src/ableton/abletonobject.h"


M_NAMESPACE_ABLETON_BEGIN


class AlsDeviceChain : public AbletonObject
{
public:
  AlsDeviceChain();
  ~AlsDeviceChain();


  void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int &r_indentLvl_);
};


M_NAMESPACE_ABLETON_END
