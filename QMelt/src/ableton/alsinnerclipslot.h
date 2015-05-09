#pragma once

#include "common.h"

// ABLETON
#include "src/ableton/abletonobject.h"

M_FORWARD_ABLETON(AlsClipSlotValue)

M_NAMESPACE_ABLETON_BEGIN

class AlsInnerClipSlot : public AbletonObject
{
Q_OBJECT
public:
  AlsInnerClipSlot(QObject *parent);
  ~AlsInnerClipSlot();

  QSharedPointer<QObject> createValue();

  virtual void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);

  Q_PROPERTY(QSharedPointer<AlsClipSlotValue> value MEMBER Value NOTIFY valueChanged)

  QSharedPointer<AlsClipSlotValue> Value;

signals:
  void valueChanged();

};

M_NAMESPACE_ABLETON_END


