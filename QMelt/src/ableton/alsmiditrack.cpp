// ABLETON
#include "src/ableton/alsmiditrack.h"


M_NAMESPACE_ABLETON_BEGIN


AlsMidiTrack::AlsMidiTrack() : AlsTrack()
{
  _tagName = "MidiTrack";
}

void AlsMidiTrack::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  //TODO implement method write
}

AlsMidiTrack::~AlsMidiTrack()
{

}


M_NAMESPACE_ABLETON_END
