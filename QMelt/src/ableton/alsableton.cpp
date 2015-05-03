// ableton

#include "src/ableton/alsableton.h"
#include "src/ableton/alsliveset.h"


namespace ableton {


AlsAbleton::AlsAbleton()
  : _liveSet(nullptr), AbletonObject()
{
  _classManipulator = {
      { "LiveSet", qMakePair(static_cast<CreateVarLambda>(&AlsAbleton::createLiveSet), nullptr) }
  };
}

QSharedPointer<QObject> AlsAbleton::createLiveSet()
{
  _liveSet = QSharedPointer<AlsLiveSet>(new AlsLiveSet());
  return _liveSet.staticCast<QObject>();
}

void AlsAbleton::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  //TODO implements method write
}

AlsAbleton::~AlsAbleton()
{
  _liveSet.clear();
}

} //namespace ableton
