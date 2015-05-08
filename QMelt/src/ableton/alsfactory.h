#pragma once

// ABLETON
#include "src/ableton/abletonobject.h"


M_FORWARD_ABLETON(AlsAbleton)


M_NAMESPACE_ABLETON_BEGIN


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


M_NAMESPACE_ABLETON_END
