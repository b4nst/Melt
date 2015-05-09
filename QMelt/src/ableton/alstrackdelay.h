#pragma once

// ABLETON
#include "src/ableton/abletonobject.h"


M_NAMESPACE_ABLETON_BEGIN


class AlsTrackDelay : public AbletonObject
{
  Q_OBJECT
public:
  AlsTrackDelay(QObject *parent);
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
  
  
  int Value;
  bool IsValueSampleBased;


  Q_PROPERTY(int Value MEMBER Value NOTIFY valueChanged)
  Q_PROPERTY(bool IsValueSampleBased MEMBER IsValueSampleBased NOTIFY isValueSampleBasedChanged)

signals:
  void valueChanged();
  void isValueSampleBasedChanged();
};


M_NAMESPACE_ABLETON_END
