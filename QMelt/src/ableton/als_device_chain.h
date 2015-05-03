#pragma once

#include <QSharedPointer>

//ableton
#include "src/ableton/ableton_object.h"

namespace ableton {

class AlsDeviceChain : public AbletonObject
{
public:
  AlsDeviceChain();
  ~AlsDeviceChain();

  void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int &r_indentLvl_);
};

}//namespace ableton

