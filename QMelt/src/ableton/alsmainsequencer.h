#pragma once

#include "common.h"

// ABLETON
#include "src/ableton/abletonobject.h"

M_FORWARD_ABLETON(AlsClipSlot)

M_NAMESPACE_ABLETON_BEGIN


class AlsMainSequencer : public AbletonObject
{
public:
  AlsMainSequencer(QObject *parent);
  ~AlsMainSequencer();

  QSharedPointer<QObject> createClipSlot();

  virtual void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);

  void clipSlotChanged(){}

  Q_PROPERTY(QVector<QSharedPointer<AlsClipSlot>> clipSlotList MEMBER ClipSlotList NOTIFY clipSlotChanged)

  QVector<QSharedPointer<AlsClipSlot>> ClipSlotList;

};

M_NAMESPACE_ABLETON_END


