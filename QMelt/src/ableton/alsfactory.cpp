// ABLETON
#include "src/ableton/alsableton.h"
#include "src/ableton/alsfactory.h"


M_NAMESPACE_ABLETON_BEGIN


AlsFactory::AlsFactory(QObject *parent)
: XMLObject(parent)
{
  _classManipulator = decltype(_classManipulator){
      { "Ableton", qMakePair(static_cast<CreateVarLambda>(&AlsFactory::createAbleton), nullptr) }
  };
}

QSharedPointer<QObject> AlsFactory::createAbleton()
{
  Ableton = QSharedPointer<AlsAbleton>(new AlsAbleton(0));
  return Ableton.staticCast<QObject>();
}

void AlsFactory::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  //TODO implements method write
}

AlsFactory::~AlsFactory()
{

}


M_NAMESPACE_ABLETON_END
