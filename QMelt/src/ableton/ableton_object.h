#pragma once

#include "src/parser/xml_object.h"

namespace ableton {
class AbletonObject : public parser::XMLObject
{
public:
  virtual ~AbletonObject() {}

  virtual void write(std::shared_ptr<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_) = 0;


  protected:
    AbletonObject() {}

};
}//namespace ableton


