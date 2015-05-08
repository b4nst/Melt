// ABLETON
#include "src/ableton/alsmastertrack.h"


M_NAMESPACE_ABLETON_BEGIN


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


M_NAMESPACE_ABLETON_END
