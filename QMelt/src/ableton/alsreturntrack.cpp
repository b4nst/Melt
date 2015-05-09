// ABLETON
#include "src/ableton/alsreturntrack.h"


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
  //TODO implement method write
}

AlsReturnTrack::~AlsReturnTrack()
{

}


M_NAMESPACE_ABLETON_END
