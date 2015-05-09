// ABLETON
#include "src/ableton/alsname.h"


M_NAMESPACE_ABLETON_BEGIN


AlsName::AlsName(QObject *parent)
: AbletonObject(parent)
, EffectiveName("")
, UserName("")
, Annotation("")
{
  _classManipulator = decltype(_classManipulator){
      { "EffectiveName", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsName::setEffectiveName)) },
      { "UserName", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsName::setUserName)) },
      { "Annotation", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsName::setAnnotation)) }
  };

  _tagName = "Name";
}

void AlsName::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  writeStartTag(p_fos_, _tagName, QList<QPair<QString,QString>>(), r_indentLvl_);
  ++r_indentLvl_;
  writeInlineTag(p_fos_,"EffectiveName", {{"Value",EffectiveName}}, r_indentLvl_);
  writeInlineTag(p_fos_,"UserName", {{"Value",UserName}}, r_indentLvl_);
  writeInlineTag(p_fos_,"Annotation", {{"Value",Annotation}}, r_indentLvl_);
  writeGarbage(p_fos_);
  --r_indentLvl_;
  writeEndTag(p_fos_, _tagName,r_indentLvl_);
}

void AlsName::setAnnotation(const QString& r_value_)
{
  Annotation = r_value_;
}

void AlsName::setEffectiveName(const QString& r_value_)
{
  EffectiveName = r_value_;
}

void AlsName::setUserName(const QString& r_value_)
{
  UserName = r_value_;
}

AlsName::~AlsName()
{

}


M_NAMESPACE_ABLETON_END
