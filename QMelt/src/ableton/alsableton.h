#pragma once

// ABLETON
#include "src/ableton/abletonobject.h"


M_FORWARD_ABLETON(AlsLiveSet)


M_NAMESPACE_ABLETON_BEGIN


class AlsAbleton : public AbletonObject
{
public:
  AlsAbleton(QObject *parent);
  ~AlsAbleton();


  QSharedPointer<QObject> createLiveSet();


  void setMajorVersion(const QString &r_value);
  void setMinorVersion(const QString &r_value);
  void setSchemaChangeCount(const QString &r_value);
  void setCreator(const QString &r_value);


  virtual void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);


  void liveSetChanged() {}
  void majorVersionChanged() {}
  void minorVersionChanged() {}
  void schemaChangeCountChanged() {}
  void creatorChanged() {}


  Q_PROPERTY(QSharedPointer<ableton::AlsLiveSet> liveSet MEMBER LiveSet NOTIFY liveSetChanged)
  Q_PROPERTY(QString majorVersion MEMBER MajorVersion NOTIFY majorVersionChanged)
  Q_PROPERTY(QString minorVersion MEMBER MinorVersion NOTIFY minorVersionChanged)
  Q_PROPERTY(int schemaChangedCount MEMBER SchemaChangeCount NOTIFY schemaChangeCountChanged)
  Q_PROPERTY(QString creator MEMBER Creator NOTIFY creatorChanged)


  QSharedPointer<ableton::AlsLiveSet> LiveSet;
  QString MajorVersion;
  QString MinorVersion;
  int SchemaChangeCount;
  QString Creator;
};


M_NAMESPACE_ABLETON_END
