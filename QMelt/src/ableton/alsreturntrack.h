#pragma once


//ableton

#include "src/ableton/alstrack.h"


namespace ableton {


class AlsReturnTrack : public AlsTrack
{
public:
  AlsReturnTrack();
  ~AlsReturnTrack();


  void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);


private:
};


} // namespace ableton
