#include "alsmainsequencer.h"

M_NAMESPACE_ABLETON_BEGIN


AlsMainSequencer::AlsMainSequencer(QObject *parent) :
  AbletonObject(parent)
{

}

AlsMainSequencer::~AlsMainSequencer()
{

}


void AlsMainSequencer::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{

}

M_NAMESPACE_ABLETON_END

