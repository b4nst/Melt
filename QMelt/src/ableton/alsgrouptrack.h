#pragma once

// ABLETON
#include "src/ableton/alstrack.h"


M_NAMESPACE_ABLETON_BEGIN


class AlsGroupTrack : public AlsTrack
{
public:
  AlsGroupTrack();
  ~AlsGroupTrack();


  void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);


  /*!
   * \brief Sets the identifier.
   * \param The value.
   */
  void setId(const QString &r_value_);


  void idChanged() {}


  Q_PROPERTY(int id MEMBER Id NOTIFY idChanged)


  int Id;
};


M_NAMESPACE_ABLETON_END
