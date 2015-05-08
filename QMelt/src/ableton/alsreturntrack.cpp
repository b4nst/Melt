// ABLETON
#include "src/ableton/alsreturntrack.h"


M_NAMESPACE_ABLETON_BEGIN


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


M_NAMESPACE_ABLETON_END
