// ABLETON
#include "src/ableton/alsaudiotrack.h"


M_NAMESPACE_ABLETON_BEGIN


AlsAudioTrack::AlsAudioTrack()
{
  _tagName = "AudioTrack";
}

void AlsAudioTrack::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  //TODO implement method write
}

AlsAudioTrack::~AlsAudioTrack()
{

}


M_NAMESPACE_ABLETON_END
