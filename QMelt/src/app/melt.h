#pragma once
#include "src/common/common.h"

// QT
#include <QDebug>
#include <QFileInfo>
#include <QObject>
#include <QQmlApplicationEngine>


M_NAMESPACE_APP_BEGIN


class Melt : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QString aFile READ aFile WRITE openA NOTIFY aFileOpened)
public:
  explicit Melt(QObject *parent = 0);
  ~Melt();

  void openA(const QString &a);
  QString aFile();

signals:
    void aFileOpened();
private:
  QFileInfo _aFile;
  QQmlApplicationEngine _engine;
};


M_NAMESPACE_APP_END
