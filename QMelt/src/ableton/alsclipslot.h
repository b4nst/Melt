#pragma once


// ABLETON
#include "src/ableton/abletonobject.h"


M_FORWARD_ABLETON(AlsInnerClipSlot)


M_NAMESPACE_ABLETON_BEGIN


class AlsClipSlot : public AbletonObject
{
Q_OBJECT
public:
  AlsClipSlot(QObject *parent);
  ~AlsClipSlot();

  QSharedPointer<QObject> createInnerClipSlot();

  virtual void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);


  Q_PROPERTY(QSharedPointer<AlsInnerClipSlot> innerClipSlot MEMBER InnerClipSlot NOTIFY innerClipSlotChanged)

  QSharedPointer<AlsInnerClipSlot> InnerClipSlot;

signals:
  void innerClipSlotChanged();

};


M_NAMESPACE_ABLETON_END
