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
  const QFileInfo fileInfo (filePath_);
  if (fileInfo.completeSuffix() != "xml" || !fileInfo.exists() || !fileInfo.isFile())
  {
    return false;
  }

  QFile file (fileInfo.absoluteFilePath());
  if (!file.open(QFile::ReadOnly))
  {
    return false;
  }

  auto stream = QSharedPointer<io::AlsFileStreamBase>(new io::AlsTextStream(file));

  // PARSE

  file.close();
  return true;
}


bool AlsFilesystem::save(const QString &filePath_)
{
  const QFileInfo fileInfo (filePath_);
  if (fileInfo.completeSuffix() != "xml" || fileInfo.exists())
  {
    return false;
  }

  QFile file (fileInfo.absoluteFilePath());
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
