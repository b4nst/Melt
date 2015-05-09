// ABLETON
#include "src/ableton/alsmiditrack.h"


M_NAMESPACE_ABLETON_BEGIN


AlsMidiTrack::AlsMidiTrack()
: Id(0)
{
  QHash<QString, QPair<CreateVarLambda, SetVarLambda>> manipulatorConcat =  decltype(_classManipulator){
            { "Id", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsMidiTrack::setId)) }
};

  _classManipulator.unite(manipulatorConcat);

  _tagName = "MidiTrack";
}

void AlsMidiTrack::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  //TODO implement method write
}

void AlsMidiTrack::setId(const QString &r_value_)
{
  Id = r_value_.toInt();
}

AlsMidiTrack::~AlsMidiTrack()
{

}


M_NAMESPACE_ABLETON_END
