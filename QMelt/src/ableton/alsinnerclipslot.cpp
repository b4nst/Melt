#include "src/ableton/alsinnerclipslot.h"

// ABLETON
#include "src/ableton/alsclipslotvalue.h"

M_NAMESPACE_ABLETON_BEGIN

AlsInnerClipSlot::AlsInnerClipSlot(QObject *parent):
  AbletonObject(parent)
{
  _classManipulator = decltype(_classManipulator){
      { "Value", qMakePair(static_cast<CreateVarLambda>(&AlsInnerClipSlot::createValue),nullptr) }
  };

  _tagName = "ClipSlot";
}

QSharedPointer<QObject> AlsInnerClipSlot::createValue()
{
  Value = QSharedPointer<AlsClipSlotValue>(new AlsClipSlotValue(this));
  return Value.staticCast<QObject>();
}

void AlsInnerClipSlot::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int &r_indentLvl_)
{
  writeStartTag(p_fos_,_tagName,QList<QPair<QString, QString>>(),r_indentLvl_);
  ++r_indentLvl_;
  if (Value == nullptr) {
    writeInlineTag(p_fos_,"Value",QList<QPair<QString, QString>>(),r_indentLvl_);
  }
  else {
    Value->write(p_fos_,r_indentLvl_);
  }
  writeGarbage(p_fos_);
  --r_indentLvl_;
  writeEndTag(p_fos_,_tagName,r_indentLvl_);
}

AlsInnerClipSlot::~AlsInnerClipSlot()
{

}

M_NAMESPACE_ABLETON_END
