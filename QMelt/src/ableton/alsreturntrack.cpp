//ableton
#include "src/ableton/alsreturntrack.h"

//io
#include "src/io/alsfilestreambase.h"

namespace ableton{
  AlsReturnTrack::AlsReturnTrack() : AlsTrack()
  {
    _tagName = "ReturnTrack";

  }

  void AlsReturnTrack::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
  {
    //TODO implement method write
  }

  AlsReturnTrack::~AlsReturnTrack()
  {

  }
}
