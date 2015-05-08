// IO
#include "src/io/alstextstream.h"


M_NAMESPACE_IO_BEGIN


AlsTextStream::AlsTextStream(QFile &file_, QObject *parent)
: AlsFileStreamBase(parent)
, _stream(&file_)
{

}


AlsTextStream::~AlsTextStream()
{

}


bool AlsTextStream::isExhausted()
{
  return _stream.atEnd();
}


bool AlsTextStream::isOk()
{
  return _stream.status() == QTextStream::Ok;
}


QString AlsTextStream::readNextLine()
{
  return _stream.readLine();
}


void AlsTextStream::write(const QString &dataToWrite_)
{
  _stream << dataToWrite_;
}


M_NAMESPACE_IO_END
