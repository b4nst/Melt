#include "src/ableton/alsmastertrack.h"

//io
#include "src/io/alsfilestreambase.h"

namespace ableton {
  AlsMasterTrack::AlsMasterTrack() : AlsTrack()
  {
    _tagName = "MasterTrack";

  }

  void AlsMasterTrack::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
  {
    //TODO implement method write
  }

  AlsMasterTrack::~AlsMasterTrack()
  {

  }
}
