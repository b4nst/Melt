// ABLETON
#include "src/ableton/alsdevicechain.h"
#include "src/ableton/alsmainsequencer.h"

M_NAMESPACE_ABLETON_BEGIN


AlsDeviceChain::AlsDeviceChain(QObject *parent)
: AbletonObject(parent)
, MainSequencer(nullptr)
{
  _classManipulator = decltype(_classManipulator){
      { "MainSequencer", qMakePair(static_cast<CreateVarLambda>(&AlsDeviceChain::createMainSequencer),nullptr) }
  };

  _tagName = "DeviceChain";
}

QSharedPointer<QObject> AlsDeviceChain::createMainSequencer()
{
  MainSequencer = QSharedPointer<AlsMainSequencer>(new AlsMainSequencer(this));
  return MainSequencer.staticCast<QObject>();
}

void AlsDeviceChain::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  writeStartTag(p_fos_, _tagName, QList<QPair<QString,QString>>(), r_indentLvl_);
  ++ r_indentLvl_;
  if (MainSequencer != nullptr) {
    MainSequencer->write(p_fos_, r_indentLvl_);
  }
  writeGarbage(p_fos_);
  -- r_indentLvl_;
  writeEndTag(p_fos_, _tagName, r_indentLvl_);
}

AlsDeviceChain::~AlsDeviceChain()
{

}


M_NAMESPACE_ABLETON_END
