// IO
#include "src/io/alszipstream.h"

// UTILS
#include "src/utils/zlibhelper.h"

#include <QDebug>


M_NAMESPACE_IO_BEGIN


AlsZipStream::AlsZipStream(QFile &file_, QObject *parent)
: AlsFileStreamBase(parent)
{
  file_.open(QIODevice::ReadOnly);
  utils::ZLibHelper::uncompress(file_.readAll(), _array);
  file_.close();
  _it = _array.begin();
}


AlsZipStream::~AlsZipStream()
{

}


bool AlsZipStream::isExhausted()
{
  return _it == _array.end();
}


bool AlsZipStream::isOk()
{
  return _it != _array.end();
}


QString AlsZipStream::readNextLine()
{
  QString string;
  while (_it != _array.end())
  {
    if (*_it != '\n')
    {
      string.append(*_it);
    }
    else
    {
      ++_it;
      return string;
    }
    ++_it;
  }
  return string;
}


void AlsZipStream::write(const QString &/*dataToWrite_*/)
{
  //_stream << dataToWrite_;
}


M_NAMESPACE_IO_END
