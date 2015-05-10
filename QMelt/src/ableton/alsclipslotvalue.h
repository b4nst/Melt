#pragma once


// ABLETON
#include "src/ableton/abletonobject.h"


M_FORWARD_ABLETON(AlsMidiClip)


M_NAMESPACE_ABLETON_BEGIN


class AlsClipSlotValue : public AbletonObject
{
Q_OBJECT
public:
  AlsClipSlotValue(QObject *parent);
  ~AlsClipSlotValue();

  QSharedPointer<QObject> createMidiClip();

  virtual void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);

  Q_PROPERTY(QSharedPointer<AlsMidiClip> midiClip MEMBER MidiClip NOTIFY midiClipChanged)

  QSharedPointer<AlsMidiClip> MidiClip;

signals:
  void midiClipChanged();

};


M_NAMESPACE_ABLETON_END
