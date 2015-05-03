//ableton
#include "src/ableton/alsname.h"

namespace ableton {
  AlsName::AlsName() : AbletonObject()
  {
    _classManipulator = decltype(_classManipulator){
        { "EffectiveName", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsName::setEffectiveName)) },
        { "UserName", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsName::setUserName)) },
        { "Annotation", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsName::setAnnotation)) }
    };
  }

  void AlsName::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
  {
    //TODO implement method write
  }

  void AlsName::setAnnotation(const QString& r_value_)
  {
    _annotation = r_value_;
  }

  void AlsName::setEffectiveName(const QString& r_value_)
  {
    _effectiveName = r_value_;
  }

  void AlsName::setUserName(const QString& r_value_)
  {
    _userName = r_value_;
  }

  AlsName::~AlsName()
  {

  }
}
