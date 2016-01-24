#pragma once

#include "src/common/common.h"

// ABLETON
#include "src/ableton/abletonobject.h"

#include <QVector>

M_FORWARD_ABLETON(AlsClipSlot)

M_NAMESPACE_ABLETON_BEGIN

class AlsMainSequencer : public AbletonObject
{
Q_OBJECT
public:
  AlsMainSequencer(QObject *parent);
  ~AlsMainSequencer();

  QSharedPointer<QObject> createClipSlot();
  QSharedPointer<QObject> createClipSlotList();

  virtual void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);

  Q_PROPERTY(QVector<QSharedPointer<AlsClipSlot>> clipSlotList MEMBER ClipSlotList NOTIFY clipSlotChanged)

  QVector<QSharedPointer<AlsClipSlot>> ClipSlotList;

signals:
  void clipSlotChanged();
};

M_NAMESPACE_ABLETON_END


