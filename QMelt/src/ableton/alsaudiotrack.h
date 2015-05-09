#pragma once

// ABLETON
#include "src/ableton/alstrack.h"

M_FORWARD_ABLETON(AlsDeviceChain)

M_NAMESPACE_ABLETON_BEGIN


class AlsAudioTrack : public AlsTrack
{
public:
  AlsAudioTrack();
  ~AlsAudioTrack();


  void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);


  /*!
   * \brief Sets the identifier.
   * \param The value.
   */
  void setId(const QString &r_value_);

  /// <summary>
  /// Creates the device chain.
  /// </summary>
  /// <returns></returns>
  QSharedPointer<QObject> createDeviceChain();


  void idChanged() {}


  Q_PROPERTY(int id MEMBER Id NOTIFY idChanged)


  int Id;
  QSharedPointer<AlsDeviceChain> DeviceChain;
};


M_NAMESPACE_ABLETON_END
