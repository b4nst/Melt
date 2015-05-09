#pragma once

#include "common.h"

// ABLETON
#include "src/ableton/abletonobject.h"

M_FORWARD_ABLETON(AlsInnerClipSlot)

M_NAMESPACE_ABLETON_BEGIN


class AlsInnerClipSlot : public AbletonObject
{
public:
  AlsInnerClipSlot(QObject *parent);
  ~AlsInnerClipSlot();

  QSharedPointer<QObject> createInnerClipSlot();

  virtual void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);

  void innerClipSlotChanged(){}

  Q_PROPERTY(QSharedPointer<AlsInnerClipSlot> innerClipSlot MEMBER InnerClipSlot NOTIFY innerClipSlotChanged)

  QSharedPointer<AlsInnerClipSlot> InnerClipSlot;

};

M_NAMESPACE_ABLETON_END


