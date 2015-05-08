#pragma once


// ABLETON

#include "src/ableton/abletonobject.h"


M_NAMESPACE_ABLETON_BEGIN


class AlsTrackDelay : public AbletonObject
{
public:
  AlsTrackDelay();
  ~AlsTrackDelay();


  void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int &r_indentLvl_);


  /*!
   * \brief setValue
   * Set the value_.
   * \param r_value_
   */
  void setValue(const QString &r_value_);


  /*!
   * \brief setIsValueSampleBased
   * \param value_
   */
  void setIsValueSampleBased(const QString &r_value_);


private:
  int _value;
  bool _isValueSampleBased;
};


M_NAMESPACE_ABLETON_END
