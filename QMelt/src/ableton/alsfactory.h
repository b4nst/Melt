#pragma once
#include "src/common/common.h"

// ABLETON
#include "src/parser/xmlobject.h"


M_FORWARD_ABLETON(AlsAbleton)


M_NAMESPACE_ABLETON_BEGIN


class AlsFactory : public parser::XMLObject
{
  Q_OBJECT
public:
  AlsFactory(QObject *parent = 0);
  ~AlsFactory();


  QSharedPointer<QObject> createAbleton();


  virtual void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);


  QSharedPointer<ableton::AlsAbleton> Ableton;
};


M_NAMESPACE_ABLETON_END
