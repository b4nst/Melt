#pragma once


// ABLETON

#include "src/ableton/alstrack.h"


M_NAMESPACE_ABLETON_BEGIN


class AlsMidiTrack : public AlsTrack
{
public:
  AlsMidiTrack();
  ~AlsMidiTrack();


  void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);


private:
};


M_NAMESPACE_ABLETON_END
