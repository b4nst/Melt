#pragma once

// ABLETON
#include "src/ableton/abletonobject.h"


M_FORWARD_ABLETON(AlsMainSequencer)


M_NAMESPACE_ABLETON_BEGIN


class AlsDeviceChain : public AbletonObject
{
  Q_OBJECT
public:
  AlsDeviceChain(QObject *parent);
  ~AlsDeviceChain();

  QSharedPointer<QObject> createMainSequencer();

  void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int &r_indentLvl_);

  Q_PROPERTY(QSharedPointer<AlsMainSequencer> mainSequencer MEMBER MainSequencer NOTIFY mainSequencerChanged)

  QSharedPointer<AlsMainSequencer> MainSequencer;

signals:
  void mainSequencerChanged();
};


M_NAMESPACE_ABLETON_END
