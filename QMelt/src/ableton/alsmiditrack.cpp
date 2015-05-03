#include "src/ableton/alsmiditrack.h"

//io
#include "src/io/alsfilestreambase.h"

namespace ableton
{
  AlsMidiTrack::AlsMidiTrack() : AlsTrack()
  {

  }

  void AlsMidiTrack::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
  {
    //TODO implement method write
  }

  AlsMidiTrack::~AlsMidiTrack()
  {

  }
}
