#pragma once


// Melt
#include "src/io/alsfilestreambase.h"


// QT
#include <QTextStream>
#include <QFile>


namespace io
{


class AlsTextStream : public AlsFileStreamBase
{
public:
  AlsTextStream(const QString &path_, QObject *parent = 0);
  ~AlsTextStream();

  virtual bool isExhausted();
  virtual bool isOk();

  virtual QString readNextLine();

  virtual void write(const QString & string_);

private:
  QFile _file;
  QTextStream _stream;
};


} // namespace io
