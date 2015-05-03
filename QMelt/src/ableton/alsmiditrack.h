#pragma once


// ableton

#include "src/ableton/alstrack.h"


namespace ableton {


class AlsMidiTrack : public AlsTrack
{
public:
  AlsMidiTrack();
  ~AlsMidiTrack();


  void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);


private:
};


} // namespace ableton
