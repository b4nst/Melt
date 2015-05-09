// ABLETON
#include "src/ableton/alsreturntrack.h"

// IO
#include "src/io/alsfilestreambase.h"

M_NAMESPACE_ABLETON_BEGIN


AlsReturnTrack::AlsReturnTrack()
{
  QHash<QString, QPair<CreateVarLambda, SetVarLambda>> manipulatorConcat =  decltype(_classManipulator){
            { "Id", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsReturnTrack::setId)) },
};

  _classManipulator.unite(manipulatorConcat);

  _tagName = "ReturnTrack";

}

void AlsReturnTrack::setId(const QString &r_value_)
{
  Id = r_value_.toInt();
}

void AlsReturnTrack::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  writeStartTag(p_fos_, _tagName, {{"Id", QString::number(Id)}},r_indentLvl_);
  ++r_indentLvl_;
  AlsTrack::write(p_fos_, r_indentLvl_);
  p_fos_->write(this->_garbage);
  --r_indentLvl_;
  writeEndTag(p_fos_, _tagName, r_indentLvl_);
}

AlsReturnTrack::~AlsReturnTrack()
{

}


M_NAMESPACE_ABLETON_END
