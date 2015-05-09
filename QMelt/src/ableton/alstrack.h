#pragma once

// ABLETON
#include "src/ableton/abletonobject.h"


M_FORWARD_ABLETON(AlsName)
M_FORWARD_ABLETON(AlsTrackDelay)


M_NAMESPACE_ABLETON_BEGIN


class AlsTrack : public AbletonObject
{
public:
  AlsTrack(QObject *parent);
  ~AlsTrack();


  void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);


  /// <summary>
  /// Sets the lom identifier.
  /// </summary>
  /// <param name="value">The value.</param>
  void setLomId(const QString &r_value_);


  /// <summary>
  /// Sets the lom identifier view.
  /// </summary>
  /// <param name="value">The value.</param>
  void setLomIdView(const QString &r_value_);


  /// <summary>
  /// Sets the envelope mode preferred.
  /// </summary>
  /// <param name="value">The value.</param>
  void setEnvelopeModePreferred(const QString &r_value_);


  /// <summary>
  /// Sets the index of the color.
  /// </summary>
  /// <param name="value">The value.</param>
  void setColorIndex(const QString &r_value_);


  /// <summary>
  /// Sets the track group identifier.
  /// </summary>
  /// <param name="value">The value.</param>
  void setTrackGroupId(const QString &r_value_);


  /// <summary>
  /// Creates the name.
  /// </summary>
  /// <returns></returns>
  QSharedPointer<QObject> createName();


  /// <summary>
  /// Creates the track delay.
  /// </summary>
  /// <returns></returns>
  QSharedPointer<QObject> createTrackDelay();


  void lomIdChanged() {}
  void lomIdViewChanged() {}
  void envelopeModePreferredChanged() {}
  void colorIndexChanged() {}
  void trackGroupIdChanged() {}
  void nameChanged() {}
  void trackDelayChanged() {}


  Q_PROPERTY(int lomId MEMBER LomId NOTIFY lomIdChanged)
  Q_PROPERTY(int lomIdView MEMBER LomIdView NOTIFY lomIdViewChanged)
  Q_PROPERTY(bool envelopeModePreferred MEMBER EnvelopeModePreferred NOTIFY envelopeModePreferredChanged)
  Q_PROPERTY(int colorIndex MEMBER ColorIndex NOTIFY colorIndexChanged)
  Q_PROPERTY(int trackGroupId MEMBER TrackGroupId NOTIFY trackGroupIdChanged)
  Q_PROPERTY(QSharedPointer<AlsName> name MEMBER Name NOTIFY nameChanged)
  Q_PROPERTY(QSharedPointer<AlsTrackDelay> trackDelay MEMBER TrackDelay NOTIFY trackDelayChanged)


  int LomId;
  int LomIdView;
  bool EnvelopeModePreferred;
  int ColorIndex;
  int TrackGroupId;
  QSharedPointer<AlsName> Name;
  QSharedPointer<AlsTrackDelay> TrackDelay;

};


M_NAMESPACE_ABLETON_END
