#pragma once


// QT
#include <QObject>
#include <QString>
#include <QFile>
#include <QScopedPointer>


namespace io
{


class AlsFileStreamBase : public QObject
{
public:
  virtual ~AlsFileStreamBase() {}

  virtual bool isExhausted() = 0;
  virtual bool isOk() = 0;

  virtual QString readNextLine() = 0;
  virtual void write(const QString &) = 0;

protected:
  AlsFileStreamBase(QObject *parent = 0) : QObject(parent) {}

private:
};


} // namespace io
