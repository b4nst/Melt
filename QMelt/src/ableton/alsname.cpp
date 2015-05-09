// ABLETON
#include "src/ableton/alsname.h"


M_NAMESPACE_ABLETON_BEGIN


AlsName::AlsName()
: EffectiveName("")
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
  //TODO implement method write
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
