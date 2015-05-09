// ABLETON
#include "src/ableton/alstrack.h"
#include "src/ableton/alsname.h"
#include "src/ableton/alsdevicechain.h"
#include "src/ableton/alstrackdelay.h"

// IO
#include "src/io/alsfilestreambase.h"

M_NAMESPACE_ABLETON_BEGIN


AlsTrack::AlsTrack()
: LomId(0)
, LomIdView(0)
, EnvelopeModePreferred(false)
, TrackDelay(QSharedPointer<AlsTrackDelay>())
, Name(QSharedPointer<AlsName>())
, ColorIndex(0)
, TrackGroupId(0)
, DeviceChain(QSharedPointer<AlsDeviceChain>())
{
  _classManipulator = decltype(_classManipulator){
      { "LomId", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsTrack::setLomId)) },
      { "LomIdView", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsTrack::setLomIdView)) },
      { "EnvelopeModePreferred", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsTrack::setEnvelopeModePreferred)) },
      { "TrackDelay", qMakePair(static_cast<CreateVarLambda>(&AlsTrack::createTrackDelay), nullptr) },
      { "Name", qMakePair(static_cast<CreateVarLambda>(&AlsTrack::createName), nullptr) },
      { "ColorIndex", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsTrack::setColorIndex)) },
      { "TrackGroupId", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsTrack::setTrackGroupId)) },
      { "DeviceChain", qMakePair(static_cast<CreateVarLambda>(&AlsTrack::createDeviceChain), nullptr) }
  };
}

void AlsTrack::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{  
  writeInlineTag(p_fos_,"LomId", {{"Value",QString::number(LomId)}}, r_indentLvl_);
  writeInlineTag(p_fos_,"LomIdView", {{"Value",QString::number(LomIdView)}}, r_indentLvl_);
  writeInlineTag(p_fos_,"EnvelopeModePreferred", {{"Value",EnvelopeModePreferred ? "true" : "false"}}, r_indentLvl_);
  writeInlineTag(p_fos_,"ColorIndex", {{"Value",QString::number(ColorIndex)}}, r_indentLvl_);
  writeInlineTag(p_fos_,"TrackGroupId", {{"Value",QString::number(TrackGroupId)}}, r_indentLvl_);
  Name->write(p_fos_,r_indentLvl_);
  TrackDelay->write(p_fos_,r_indentLvl_);
  DeviceChain->write(p_fos_,r_indentLvl_);
}

void AlsTrack::setColorIndex(const QString &r_value_)
{
  ColorIndex = r_value_.toInt();
}

void AlsTrack::setEnvelopeModePreferred(const QString &r_value_)
{
  QString valueToTest = r_value_.toLower().trimmed();
  EnvelopeModePreferred = (valueToTest == "true" ? true : false);
}

void AlsTrack::setLomId(const QString &r_value_)
{
  LomId = r_value_.toInt();
}

void AlsTrack::setLomIdView(const QString &r_value_)
{
  LomIdView = r_value_.toInt();
}

void AlsTrack::setTrackGroupId(const QString &r_value_)
{
  TrackGroupId = r_value_.toInt();
}

QSharedPointer<QObject> AlsTrack::createDeviceChain()
{
  DeviceChain = QSharedPointer<AlsDeviceChain>(new AlsDeviceChain());
  return DeviceChain.staticCast<QObject>();
}

QSharedPointer<QObject> AlsTrack::createName()
{
  Name = QSharedPointer<AlsName>(new AlsName());
  return Name.staticCast<QObject>();
}

QSharedPointer<QObject> AlsTrack::createTrackDelay()
{
  TrackDelay = QSharedPointer<AlsTrackDelay>(new AlsTrackDelay());
  return TrackDelay.staticCast<QObject>();
}

AlsTrack::~AlsTrack()
{
  TrackDelay.clear();
  DeviceChain.clear();
  Name.clear();
}


M_NAMESPACE_ABLETON_END
