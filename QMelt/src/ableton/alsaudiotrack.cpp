// ABLETON
#include "src/ableton/alsaudiotrack.h"


M_NAMESPACE_ABLETON_BEGIN


AlsAudioTrack::AlsAudioTrack()
: Id(0)
{
  QHash<QString, QPair<CreateVarLambda, SetVarLambda>> manipulatorConcat =  decltype(_classManipulator){
            { "Id", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsAudioTrack::setId)) }
};

  _classManipulator.unite(manipulatorConcat);

  _tagName = "AudioTrack";
}

void AlsAudioTrack::setId(const QString &r_value_)
{
  Id = r_value_.toInt();
}

void AlsAudioTrack::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  //TODO implement method write
}

AlsAudioTrack::~AlsAudioTrack()
{

}


M_NAMESPACE_ABLETON_END
