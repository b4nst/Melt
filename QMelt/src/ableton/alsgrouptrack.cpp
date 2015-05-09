// ABLETON
#include "src/ableton/AlsGroupTrack.h"


M_NAMESPACE_ABLETON_BEGIN


AlsGroupTrack::AlsGroupTrack()
: Id(0)
{
  QHash<QString, QPair<CreateVarLambda, SetVarLambda>> manipulatorConcat =  decltype(_classManipulator){
            { "Id", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsGroupTrack::setId)) }
};

  _classManipulator.unite(manipulatorConcat);

  _tagName = "GroupTrack";
}

void AlsGroupTrack::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  //TODO implement method write
}

void AlsGroupTrack::setId(const QString &r_value_)
{
  Id = r_value_.toInt();
}

AlsGroupTrack::~AlsGroupTrack()
{

}


M_NAMESPACE_ABLETON_END
