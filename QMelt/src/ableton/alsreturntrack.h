#pragma once

// ABLETON
#include "src/ableton/alstrack.h"


M_NAMESPACE_ABLETON_BEGIN


class AlsReturnTrack : public AlsTrack
{
public:
  AlsReturnTrack();
  ~AlsReturnTrack();


  void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);


  /// <summary>
  /// Sets the identifier.
  /// </summary>
  /// <param name="value">The value.</param>
  void setId(const QString &r_value_);


  void idChanged() {}


  Q_PROPERTY(QString id MEMBER Id NOTIFY idChanged)


  int Id;
};


M_NAMESPACE_ABLETON_END
