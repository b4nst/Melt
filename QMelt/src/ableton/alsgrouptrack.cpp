// ABLETON
#include "src/ableton/AlsGroupTrack.h"


M_NAMESPACE_ABLETON_BEGIN


AlsGroupTrack::AlsGroupTrack(QObject *parent)
: AlsTrack(parent)
, Id(0)
{
  QHash<QString, QPair<CreateVarLambda, SetVarLambda>> manipulatorConcat =  decltype(_classManipulator){
            { "Id", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsGroupTrack::setId)) }
};

  _classManipulator.unite(manipulatorConcat);

  _tagName = "GroupTrack";
}

void AlsGroupTrack::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  writeStartTag(p_fos_, _tagName, {{"Id", QString::number(Id)}},r_indentLvl_);
  ++r_indentLvl_;
  AlsTrack::write(p_fos_, r_indentLvl_);
  writeGarbage(p_fos_);
  --r_indentLvl_;
  writeEndTag(p_fos_, _tagName, r_indentLvl_);
}

void AlsGroupTrack::setId(const QString &r_value_)
{
  Id = r_value_.toInt();
}

AlsGroupTrack::~AlsGroupTrack()
{

}


M_NAMESPACE_ABLETON_END
