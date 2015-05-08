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

  /// <summary>
  /// Init _tracks and return nullptr.
  /// </summary>
  /// <returns></returns>
  QSharedPointer<QObject> createTracks();


private:
  int _lomId;
  int _lomIdView;
  QVector<QSharedPointer<AlsTrack>> _tracks;
  QSharedPointer<AlsTrack> _masterTrack;
  bool _overdub;
};


M_NAMESPACE_ABLETON_END
