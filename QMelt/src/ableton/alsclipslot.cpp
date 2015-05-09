// ABLETON
#include "src/ableton/alsclipslot.h"
#include "src/ableton/alsinnerclipslot.h"

M_NAMESPACE_ABLETON_BEGIN

AlsClipSlot::AlsClipSlot(QObject * parent) :
  AbletonObject(parent)
{
  _classManipulator = decltype(_classManipulator){
      { "ClipSlot", qMakePair(static_cast<CreateVarLambda>(&AlsClipSlot::createInnerClipSlot),nullptr) }
  };

  _tagName = "ClipSlot";
}


void AlsClipSlot::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  writeStartTag(p_fos_,_tagName,QList<QPair<QString, QString>>(),r_indentLvl_);
  ++r_indentLvl_;
  InnerClipSlot->write(p_fos_, r_indentLvl_);
  writeGarbage(p_fos_);
  --r_indentLvl_;
  writeEndTag(p_fos_,_tagName,r_indentLvl_);
}

QSharedPointer<QObject> AlsClipSlot::createInnerClipSlot()
{
  InnerClipSlot = QSharedPointer<AlsInnerClipSlot>(new AlsInnerClipSlot(this));
  return InnerClipSlot.staticCast<QObject>();
}

AlsClipSlot::~AlsClipSlot()
{

}
M_NAMESPACE_ABLETON_END
