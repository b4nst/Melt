#pragma once

// ABLETON
#include "src/ableton/alstrack.h"


M_NAMESPACE_ABLETON_BEGIN


class AlsGroupTrack : public AlsTrack
{
  Q_OBJECT
public:
  AlsGroupTrack(QObject *parent);
  ~AlsGroupTrack();


  void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);


  /*!
   * \brief Sets the identifier.
   * \param The value.
   */
  void setId(const QString &r_value_);


  int Id;


  Q_PROPERTY(int Id MEMBER Id NOTIFY idChanged)


signals:
  void idChanged();
};


M_NAMESPACE_ABLETON_END
