#pragma once


//ableton

#include "src/ableton/alstrack.h"


namespace ableton {


class AlsAudioTrack : public AlsTrack
{
public:
  AlsAudioTrack();
  ~AlsAudioTrack();


  void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);


private:
};


} // namespace ableton
