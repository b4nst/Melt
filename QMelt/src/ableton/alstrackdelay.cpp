// ABLETON
#include "src/ableton/alstrackdelay.h"


M_NAMESPACE_ABLETON_BEGIN


AlsTrackDelay::AlsTrackDelay()
{
  _classManipulator = decltype(_classManipulator){
      { "Value", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsTrackDelay::setValue)) },
      { "IsValueSampleBased", qMakePair(nullptr,static_cast<SetVarLambda>(&AlsTrackDelay::setIsValueSampleBased)) }
  };

  _tagName = "TrackDelay";

}

void AlsTrackDelay::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  //TODO implement method write
}

void AlsTrackDelay::setValue(const QString &r_value_)
{
  _value = r_value_.toInt();
}

void AlsTrackDelay::setIsValueSampleBased(const QString& r_value_)
{
  QString valueToTest = r_value_.toLower().trimmed();
  _isValueSampleBased = (valueToTest == "true" ? true : false);
}

AlsTrackDelay::~AlsTrackDelay()
{

}


M_NAMESPACE_ABLETON_END
