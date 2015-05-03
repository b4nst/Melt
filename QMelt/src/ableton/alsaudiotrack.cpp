#include "src/ableton/alsaudiotrack.h"

//io
#include "src/io/alsfilestreambase.h"

namespace ableton {
  AlsAudioTrack::AlsAudioTrack() : AlsTrack()
  {

  }

  void AlsAudioTrack::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
  {
    //TODO implement method write
  }

  AlsAudioTrack::~AlsAudioTrack()
  {

  }
}
