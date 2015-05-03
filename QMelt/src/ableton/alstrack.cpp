// ableton
#include "src/ableton/alstrack.h"
#include "src/ableton/alsname.h"
#include "src/ableton/alsdevicechain.h"
#include "src/ableton/alstrackdelay.h"

//io
#include "src/io/alsfilestreambase.h"

namespace ableton
{
  AlsTrack::AlsTrack() : AbletonObject()
  {
    _classManipulator = decltype(_classManipulator){
        { "Id", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsTrack::setId)) },
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
    //TODO implement method write
  }

  void AlsTrack::setColorIndex(const QString &r_value_)
  {
    _colorIndex = r_value_.toInt();
  }

  void AlsTrack::setEnvelopeModePreferred(const QString &r_value_)
  {
    QString valueToTest = r_value_.toLower().trimmed();
    _envelopeModePreferred = (valueToTest == "true" ? true : false);
  }

  void AlsTrack::setId(const QString &r_value_)
  {
    _id = r_value_.toInt();
  }

  void AlsTrack::setLomId(const QString &r_value_)
  {
    _lomId = r_value_.toInt();
  }

  void AlsTrack::setLomIdView(const QString &r_value_)
  {
    _lomIdView = r_value_.toInt();
  }

  void AlsTrack::setTrackGroupId(const QString &r_value_)
  {
    _trackGroupId = r_value_.toInt();
  }

  QSharedPointer<QObject> AlsTrack::createDeviceChain()
  {
    _deviceChain = QSharedPointer<AlsDeviceChain>(new AlsDeviceChain());
    return _deviceChain.staticCast<QObject>();
  }

  QSharedPointer<QObject> AlsTrack::createName()
  {
    _name = QSharedPointer<AlsName>(new AlsName());
    return _name.staticCast<QObject>();
  }

  QSharedPointer<QObject> AlsTrack::createTrackDelay()
  {
    _trackDelay = QSharedPointer<AlsTrackDelay>(new AlsTrackDelay());
    return _trackDelay.staticCast<QObject>();
  }

  AlsTrack::~AlsTrack()
  {
    _trackDelay.reset();
    _deviceChain.reset();
    _name.reset();
  }
}
