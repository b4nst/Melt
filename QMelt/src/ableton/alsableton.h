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

  QSharedPointer<ableton::AlsLiveSet> LiveSet() { return _liveSet; }

  virtual void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);


private:
  QSharedPointer<ableton::AlsLiveSet> _liveSet;
  QString _majorVersion;
  QString _minorVersion;
  int _schemaChangeCount;
  QString _creator;

};


M_NAMESPACE_ABLETON_END
