#include "src/io/alstextstream.h"


namespace io {


AlsTextStream::AlsTextStream(const QString &path_, QObject *parent)
: AlsFileStreamBase(parent)
, _file(path_)
, _stream(&_file)
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


void AlsTextStream::write(const QString &string_)
{
  _stream << string_;
}

} // namespace io
