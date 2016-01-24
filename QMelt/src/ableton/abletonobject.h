#pragma once
#include "src/common/common.h"

// QT
#include <QSharedPointer>

// PARSER
#include "src/parser/xmlobject.h"


M_NAMESPACE_ABLETON_BEGIN


class AbletonObject : public parser::XMLObject
{
  Q_OBJECT
public:
  virtual ~AbletonObject() {}


  virtual void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_) = 0;


  protected:
    explicit AbletonObject(QObject *parent) : XMLObject(parent) {}

};


M_NAMESPACE_ABLETON_END
