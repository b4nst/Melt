#pragma once

// ABLETON
#include "src/ableton/alstrack.h"

M_FORWARD_ABLETON(AlsDeviceChain)

M_NAMESPACE_ABLETON_BEGIN


class AlsAudioTrack : public AlsTrack
{
  Q_OBJECT
public:
  AlsAudioTrack(QObject *parent);
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


  int Id;
  QSharedPointer<AlsDeviceChain> DeviceChain;


  Q_PROPERTY(int Id MEMBER Id NOTIFY idChanged)

signals:
  void idChanged();
};


M_NAMESPACE_ABLETON_END
