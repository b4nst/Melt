#pragma once


// ableton

#include "src/ableton/ableton_object.h"


namespace ableton {


class AlsTrackDelay : public AbletonObject
{
public:
  AlsTrackDelay();
  ~AlsTrackDelay();


  void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int &r_indentLvl_);


#pragma region SetVarLambda
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
#pragma endregion


private:
  int _value;
  bool _isValueSampleBased;
};


}//namespace ableton
