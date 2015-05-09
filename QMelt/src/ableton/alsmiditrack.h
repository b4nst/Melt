#pragma once

// ABLETON
#include "src/ableton/alstrack.h"

M_FORWARD_ABLETON(AlsDeviceChain)

M_NAMESPACE_ABLETON_BEGIN


class AlsMidiTrack : public AlsTrack
{
public:
  AlsMidiTrack();
  ~AlsMidiTrack();


  void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);


  /// <summary>
  /// Sets the identifier.
  /// </summary>
  /// <param name="value">The value.</param>
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
