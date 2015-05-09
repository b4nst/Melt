#pragma once

// ABLETON
#include "src/ableton/alstrack.h"


M_FORWARD_ABLETON(AlsDeviceChain)


M_NAMESPACE_ABLETON_BEGIN


class AlsReturnTrack : public AlsTrack
{
  Q_OBJECT
public:
  AlsReturnTrack(QObject *parent);
  ~AlsReturnTrack();


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


  int Id;  
  QSharedPointer<AlsDeviceChain> DeviceChain;


  Q_PROPERTY(int Id MEMBER Id NOTIFY idChanged)

signals:
  void idChanged();
};


M_NAMESPACE_ABLETON_END
