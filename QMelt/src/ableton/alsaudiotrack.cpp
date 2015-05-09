// ABLETON
#include "src/ableton/alsaudiotrack.h"
#include "src/ableton/alsdevicechain.h"


M_NAMESPACE_ABLETON_BEGIN


AlsAudioTrack::AlsAudioTrack(QObject *parent)
: AlsTrack(parent)
, Id(0)
, DeviceChain(QSharedPointer<AlsDeviceChain>())
{
  QHash<QString, QPair<CreateVarLambda, SetVarLambda>> manipulatorConcat =  decltype(_classManipulator){
    { "Id", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsAudioTrack::setId)) },
    { "DeviceChain", qMakePair(static_cast<CreateVarLambda>(&AlsAudioTrack::createDeviceChain), nullptr) }
  };

  _classManipulator.unite(manipulatorConcat);

  _tagName = "AudioTrack";
}

void AlsAudioTrack::setId(const QString &r_value_)
{
  Id = r_value_.toInt();
}

QSharedPointer<QObject> AlsAudioTrack::createDeviceChain()
{
  DeviceChain = QSharedPointer<AlsDeviceChain>(new AlsDeviceChain(this));
  return DeviceChain.staticCast<QObject>();
}

void AlsAudioTrack::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  writeStartTag(p_fos_, _tagName, {{"Id", QString::number(Id)}},r_indentLvl_);
  ++r_indentLvl_;
  AlsTrack::write(p_fos_, r_indentLvl_);
  DeviceChain->write(p_fos_, r_indentLvl_);
  writeGarbage(p_fos_);
  --r_indentLvl_;
  writeEndTag(p_fos_, _tagName, r_indentLvl_);
}

AlsAudioTrack::~AlsAudioTrack()
{  
  DeviceChain.clear();
}


M_NAMESPACE_ABLETON_END
