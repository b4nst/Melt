#pragma once

// ABLETON
#include "src/ableton/abletonobject.h"


M_NAMESPACE_ABLETON_BEGIN


class AlsName:public AbletonObject
{
  Q_OBJECT
public:
  AlsName(QObject *parent);
  ~AlsName();


  void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int &r_indentLvl_);


  /// <summary>
  /// Sets the effective name.
  /// </summary>
  /// <param name="value">The value.</param>
  void setEffectiveName(const QString &r_value_);


  /// <summary>
  /// Sets the name of the user.
  /// </summary>
  /// <param name="value">The value.</param>
  void setUserName(const QString &r_value_);


  /// <summary>
  /// Sets the annotation.
  /// </summary>
  /// <param name="value">The value.</param>
  void setAnnotation(const QString &r_value_);


  QString EffectiveName;
  QString UserName;
  QString Annotation;


  Q_PROPERTY(QString EffectiveName MEMBER EffectiveName NOTIFY effectiveNameChanged)
  Q_PROPERTY(QString UserName MEMBER UserName NOTIFY userNameChanged)
  Q_PROPERTY(QString Annotation MEMBER Annotation NOTIFY annotationChanged)


signals:
  void effectiveNameChanged();
  void userNameChanged();
  void annotationChanged();
};


M_NAMESPACE_ABLETON_END
