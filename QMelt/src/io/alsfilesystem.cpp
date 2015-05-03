#include "src/io/alsfilesystem.h"
#include "src/io/alsfilestreambase.h"
#include "src/io/alstextstream.h"

#include <QString>
#include <QSharedPointer>

namespace io
{


bool AlsFilesystem::load(const QFileInfo &fileInfo_)
{
  const QString extension = fileInfo_.completeSuffix();
  if (extension != "xml")
  {
    return false;
  }

  auto stream = QSharedPointer<io::AlsFileStreamBase>(new io::AlsTextStream(fileInfo_.absoluteFilePath()));

  // PARSE

  return true;
}


bool AlsFilesystem::save(const QFileInfo &fileInfo_)
{
  const QString extension = fileInfo_.completeSuffix();
  if (extension != "xml")
  {
    return false;
  }

  auto stream = QSharedPointer<io::AlsFileStreamBase>(new io::AlsTextStream(fileInfo_.absoluteFilePath()));

  // PARSE

  return true;
}


} // namespace io
