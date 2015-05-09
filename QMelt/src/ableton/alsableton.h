#pragma once

// ABLETON
#include "src/ableton/abletonobject.h"


M_FORWARD_ABLETON(AlsLiveSet)


M_NAMESPACE_ABLETON_BEGIN


class AlsAbleton : public AbletonObject
{
public:
  AlsAbleton();
  ~AlsAbleton();

  QSharedPointer<QObject> createLiveSet();

  void setMajorVersion(const QString &r_value);
  void setMinorVersion(const QString &r_value);
  void setSchemaChangeCount(const QString &r_value);
  void setCreator(const QString &r_value);

  virtual void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);

  QSharedPointer<ableton::AlsLiveSet> LiveSet;
  QString MajorVersion;
  QString MinorVersion;
  int SchemaChangeCount;
  QString Creator;

};


M_NAMESPACE_ABLETON_END
