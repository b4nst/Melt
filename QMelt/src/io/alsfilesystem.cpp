// IO
#include "src/io/alsfilesystem.h"
#include "src/io/alstextstream.h"

// QT
#include <QFileInfo>
#include <QString>

// PARSER
#include "src/parser/alsxmlcontenthandler.h"
#include "src/parser/xmlcontenthandler.h"
#include "src/parser/corexmlparser.h"

// ABLETON
#include "src/ableton/alsfactory.h"
#include "src/ableton/alsableton.h"


M_NAMESPACE_IO_BEGIN


bool AlsFilesystem::load(const QString &filePath_,
                         QSharedPointer<ableton::AlsAbleton> &r_ableton_)
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
  auto alsFact = QSharedPointer<ableton::AlsFactory>(new ableton::AlsFactory());

  parser::AlsXMLContentHandler ch;
  parser::XMLContext ctx;
  parser::CoreXMLParser parser;

  ctx.pushToStack(alsFact.staticCast<QObject>());

  parser.parse(stream,ch,ctx);
  // Verify if the parsing process went well

  file.close();

  r_ableton_ = alsFact->Ableton;
  return true;
}


bool AlsFilesystem::save(const QString &filePath_, const QSharedPointer<ableton::AlsAbleton> &r_ableton_)
{
  const QFileInfo fileInfo (filePath_);
  if (fileInfo.completeSuffix() != "xml")
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
  int lvl = 0;
  r_ableton_->write(stream,lvl);

  file.close();
  return true;
}


M_NAMESPACE_IO_END
