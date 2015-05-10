#include "alsmidiclip.h"


M_NAMESPACE_ABLETON_BEGIN


AlsMidiClip::AlsMidiClip(QObject *parent)
  : AbletonObject(parent)
  , Name("")
  , ColorIndex(0)
{
  _classManipulator = decltype(_classManipulator){
      { "Name", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsMidiClip::setName)) },
      { "ColorIndex", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsMidiClip::setColorIndex)) }
  };

  _tagName = "MidiClip";

}

void AlsMidiClip::setColorIndex(const QString &r_value_)
{
  ColorIndex = r_value_.toInt();
}

void AlsMidiClip::setName(const QString &r_value_)
{
  Name = r_value_;
}

void AlsMidiClip::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int &r_indentLvl_)
{
  writeStartTag(p_fos_,_tagName,QList<QPair<QString, QString>>(),r_indentLvl_);
  ++r_indentLvl_;
  writeInlineTag(p_fos_,"Name",{{"Value",Name}},r_indentLvl_);
  writeInlineTag(p_fos_,"ColorIndex",{{"Value",QString::number(ColorIndex)}},r_indentLvl_);
  writeGarbage(p_fos_);
  --r_indentLvl_;
  writeEndTag(p_fos_,_tagName,r_indentLvl_);
}

AlsMidiClip::~AlsMidiClip()
{

}


M_NAMESPACE_ABLETON_END
