// ABLETON
#include "src/ableton/alsmastertrack.h"

// IO
#include "src/io/alsfilestreambase.h"


M_NAMESPACE_ABLETON_BEGIN


AlsMasterTrack::AlsMasterTrack()
{
  _tagName = "MasterTrack";

}

void AlsMasterTrack::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  writeStartTag(p_fos_, _tagName, QHash<QString, QString>(), r_indentLvl_);
  ++r_indentLvl_;
  AlsTrack::write(p_fos_, r_indentLvl_);
  p_fos_->write(this->_garbage);
  --r_indentLvl_;
  writeEndTag(p_fos_, _tagName, r_indentLvl_);
}

AlsMasterTrack::~AlsMasterTrack()
{

}


M_NAMESPACE_ABLETON_END
