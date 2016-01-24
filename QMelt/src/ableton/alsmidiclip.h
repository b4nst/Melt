#pragma once

#include "src/common/common.h"

// ABLETON
#include "src/ableton/abletonobject.h"


M_NAMESPACE_ABLETON_BEGIN

class AlsMidiClip : public AbletonObject
{
Q_OBJECT
public:
  AlsMidiClip(QObject *parent);
  ~AlsMidiClip();

  QSharedPointer<QObject> createValue();

  virtual void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);

  void setName(const QString &r_value_);
  void setColorIndex(const QString &r_value_);

  Q_PROPERTY(QString name MEMBER Name NOTIFY nameChanged)
  Q_PROPERTY(int colorIndex MEMBER ColorIndex NOTIFY colorIndexChanged)

  QString Name;
  int ColorIndex;

signals:
  void nameChanged();
  void colorIndexChanged();

};

M_NAMESPACE_ABLETON_END


