#pragma once

// ABLETON
#include "src/ableton/abletonobject.h"
#include "src/ableton/alstrack.h"

// QT
#include <QVector>


M_NAMESPACE_ABLETON_BEGIN


class AlsLiveSet : public AbletonObject
{
public:
  AlsLiveSet();
  ~AlsLiveSet();


  void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);


  /// <summary>
  /// Sets the lom identifier.
  /// </summary>
  /// <param name="value_">The value_.</param>
  void setLomId(const QString& value_);


  /// <summary>
  /// Sets the lom identifier view.
  /// </summary>
  /// <param name="value_">The value_.</param>
  void setLomIdView(const QString& value_);


  /// <summary>
  /// Sets the overdub.
  /// </summary>
  /// <param name="value_">The value_.</param>
  void setOverdub(const QString& value_);


  /// <summary>
  /// Creates the master track.
  /// </summary>
  /// <returns></returns>
  QSharedPointer<QObject> createMasterTrack();


  /// <summary>
  /// Creates the midi track and add it to <see cref="_tracks"/>.
  /// </summary>
  /// <returns></returns>
  QSharedPointer<QObject> createMidiTrack();


  /// <summary>
  /// Creates the audio track and add it to <see cref="_tracks"/>.
  /// </summary>
  /// <returns></returns>
  QSharedPointer<QObject> createAudioTrack();


  /// <summary>
  /// Creates the return track and add it to <see cref="_tracks"/>.
  /// </summary>
  /// <returns></returns>
  QSharedPointer<QObject> createReturnTrack();


  /*!
   * \brief Create and add a GroupTrack to Tracks
   * \return
   */
  QSharedPointer<QObject> createGroupTrack();


  /// <summary>
  /// Init _tracks and return nullptr.
  /// </summary>
  /// <returns></returns>
  QSharedPointer<QObject> createTracks();


  void lomIdChanged() {}
  void lomIdViewChanged() {}
  void tracksChanged() {}
  void masterTrackChanged() {}
  void overdubChanged() {}


  Q_PROPERTY(int lomId MEMBER LomId NOTIFY lomIdChanged)
  Q_PROPERTY(int lomIdView MEMBER LomIdView NOTIFY LomIdViewChanged)
  Q_PROPERTY(QVector<QSharedPointer<AlsTrack>> tracks MEMBER Tracks NOTIFY tracksChanged)
  Q_PROPERTY(QSharedPointer<AlsTrack> masterTrack MEMBER MasterTrack NOTIFY masterTrackChanged)
  Q_PROPERTY(bool overdub MEMBER Overdub NOTIFY overdubChanged)


  int LomId;
  int LomIdView;
  QVector<QSharedPointer<AlsTrack>> Tracks;
  QSharedPointer<AlsTrack> MasterTrack;
  bool Overdub;
};


M_NAMESPACE_ABLETON_END
