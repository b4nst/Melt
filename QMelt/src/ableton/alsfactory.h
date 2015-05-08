#pragma once


// ableton

#include "src/ableton/abletonobject.h"


namespace ableton {


// Forward declarations
class AlsAbleton;


class AlsFactory : public AbletonObject
{
public:
  AlsFactory();
  ~AlsFactory();

#pragma region CreateVarLambda
  QSharedPointer<QObject> createAbleton();
#pragma endregion

#pragma region Getters
  QSharedPointer<ableton::AlsAbleton> Ableton() { return _ableton; }
#pragma endregion

  virtual void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);


private:
  QSharedPointer<ableton::AlsAbleton> _ableton;
};


} // namespace ableton
