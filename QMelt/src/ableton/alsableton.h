#pragma once


// ableton

#include "src/ableton/abletonobject.h"


namespace ableton {


// Forward declarations
class AlsLiveSet;


class AlsAbleton : public AbletonObject
{
public:
  AlsAbleton();
  ~AlsAbleton();

#pragma region CreateVarLambda
  QSharedPointer<QObject> createLiveSet();
#pragma endregion

#pragma region Getters
  QSharedPointer<ableton::AlsLiveSet> LiveSet() { return _liveSet; }
#pragma endregion

  virtual void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);


private:
  QSharedPointer<ableton::AlsLiveSet> _liveSet;
};


} // namespace ableton
