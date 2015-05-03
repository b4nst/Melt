// IO
#include "src/io/alsfilesystem.h"
#include "src/io/alstextstream.h"

// QT
#include <QFileInfo>
#include <QString>


namespace io
{


bool AlsFilesystem::load(const QString &filePath_)
{
  const QString fileInfo (filePath_);
  if (fileInfo.completeSuffix() != "xml" || !fileInfo_.exists() || !fileInfo_.isFile())
  {
    return false;
  }

  QFile file (fileInfo_.absoluteFilePath());
  if (!file.open(QFile::ReadOnly))
  {
    return false;
  }

  auto stream = QSharedPointer<io::AlsFileStreamBase>(new io::AlsTextStream(file));

  // PARSE

  file.close();
  return true;
}


bool AlsFilesystem::save(const QFileInfo &filePath_)
{
  const QString fileInfo (filePath_);
  if (fileInfo.completeSuffix() != "xml" || fileInfo_.exists())
  {
    return false;
  }

  QFile file (fileInfo_.absoluteFilePath());
  if (!file.open(QFile::WriteOnly))
  {
    return false;
  }

  auto stream = QSharedPointer<io::AlsFileStreamBase>(new io::AlsTextStream(file));

  // PARSE

  file.close();
  return true;
}


} // namespace io
