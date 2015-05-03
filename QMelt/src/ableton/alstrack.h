#pragma once


// std

#include <QSharedPointer>


// ableton

#include "src/ableton/abletonobject.h"


namespace ableton {


//Forward declaration
class AlsName;
class AlsDeviceChain;
class AlsTrackDelay;


class AlsTrack : public AbletonObject
{
public:
  AlsTrack();
  ~AlsTrack();


  void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);


#pragma region SetVarLambda
  /// <summary>
  /// Sets the identifier.
  /// </summary>
  /// <param name="value">The value.</param>
  void setId(const QString &r_value_);


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
#pragma endregion


#pragma region CreateVarLambda
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


  /// <summary>
  /// Creates the device chain.
  /// </summary>
  /// <returns></returns>
  QSharedPointer<QObject> createDeviceChain();
#pragma endregion


protected:
    int _id;
    int _lomId;
    int _lomIdView;
    bool _envelopeModePreferred;
    QSharedPointer<AlsName> _name;
    QSharedPointer<AlsTrackDelay> _trackDelay;
    int _colorIndex;
    int _trackGroupId;
    QSharedPointer<AlsDeviceChain> _deviceChain;

};

} // namespace ableton
