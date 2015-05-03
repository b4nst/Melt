#pragma once

#include <QSharedPointer>

#include "src/parser/xmlobject.h"

namespace ableton {
class AbletonObject : public parser::XMLObject
{
public:
  virtual ~AbletonObject() {}

  virtual void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_) = 0;


  protected:
    AbletonObject() : parser::XMLObject() {}

};
}//namespace ableton


