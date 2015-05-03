#pragma once


//ableton

#include "src/ableton/alstrack.h"


namespace ableton {


class AlsMasterTrack : public AlsTrack
{
public:
  AlsMasterTrack();
  ~AlsMasterTrack();


  void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);


private:
};


} // namespace ableton
