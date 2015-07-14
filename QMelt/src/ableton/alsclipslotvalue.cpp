#include "src/ableton/alsclipslotvalue.h"

// ABLETON
#include "src/ableton/alsmidiclip.h"


M_NAMESPACE_ABLETON_BEGIN


AlsClipSlotValue::AlsClipSlotValue(QObject *parent)
  : AbletonObject(parent)
  , MidiClip(nullptr)
{
  _classManipulator = decltype(_classManipulator){
      { "MidiClip", qMakePair(static_cast<CreateVarLambda>(&AlsClipSlotValue::createMidiClip), nullptr) }
  };

  _tagName = "Value";
}

QSharedPointer<QObject> AlsClipSlotValue::createMidiClip()
{
  MidiClip = QSharedPointer<AlsMidiClip>(new AlsMidiClip(this));
  return MidiClip.staticCast<QObject>();
}

void AlsClipSlotValue::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int &r_indentLvl_)
{
  writeStartTag(p_fos_, _tagName, QList<QPair<QString, QString>>(),r_indentLvl_);
  ++r_indentLvl_;
  if (MidiClip != nullptr) {
    MidiClip->write(p_fos_,r_indentLvl_);
  }
  writeGarbage(p_fos_);
  --r_indentLvl_;
  writeEndTag(p_fos_,_tagName,r_indentLvl_);
}

AlsClipSlotValue::~AlsClipSlotValue()
{

}


M_NAMESPACE_ABLETON_END
