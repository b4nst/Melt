#pragma once

// ABLETON
#include "src/ableton/abletonobject.h"


M_FORWARD_ABLETON(AlsName)
M_FORWARD_ABLETON(AlsTrackDelay)


M_NAMESPACE_ABLETON_BEGIN


class AlsTrack : public AbletonObject
{
  Q_OBJECT
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


  int LomId;
  int LomIdView;
  bool EnvelopeModePreferred;
  int ColorIndex;
  int TrackGroupId;
  QSharedPointer<AlsName> Name;
  QSharedPointer<AlsTrackDelay> TrackDelay;


  Q_PROPERTY(int LomId MEMBER LomId NOTIFY lomIdChanged)
  Q_PROPERTY(int LomIdView MEMBER LomIdView NOTIFY lomIdViewChanged)
  Q_PROPERTY(bool EnvelopeModePreferred MEMBER EnvelopeModePreferred NOTIFY envelopeModePreferredChanged)
  Q_PROPERTY(int ColorIndex MEMBER ColorIndex NOTIFY colorIndexChanged)
  Q_PROPERTY(int TrackGroupId MEMBER TrackGroupId NOTIFY trackGroupIdChanged)
  Q_PROPERTY(QSharedPointer<AlsName> Name MEMBER Name NOTIFY nameChanged)
  Q_PROPERTY(QSharedPointer<AlsTrackDelay> TrackDelay MEMBER TrackDelay NOTIFY trackDelayChanged)


signals:
  void lomIdChanged();
  void lomIdViewChanged();
  void envelopeModePreferredChanged();
  void colorIndexChanged();
  void trackGroupIdChanged();
  void nameChanged();
  void trackDelayChanged();
};


M_NAMESPACE_ABLETON_END
