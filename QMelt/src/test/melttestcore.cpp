#include "src/test/melttestcore.h"

#include "src/io/alstextstream.h"
#include "src/parser/alsxmlcontenthandler.h"
#include "src/parser/xmlcontenthandler.h"
#include "src/parser/corexmlparser.h"
#include "src/ableton/alsfactory.h"

#define EXAMPLE_DIR QString("../Example/als-xml")

namespace test {
MeltTestCore::MeltTestCore(QObject *parent) : QObject(parent)
{

}

void MeltTestCore::testParser()
{
  QFile file(EXAMPLE_DIR + QString("/sample_project_01.xml"));
  if (!file.exists()) {
    throw QString("TOTO");
  }

  QSharedPointer<ableton::AlsFactory> alsFact;
  QSharedPointer<io::AlsTextStream> fs = QSharedPointer<io::AlsTextStream>(new io::AlsTextStream(file));
  parser::AlsXMLContentHandler ch;
  parser::XMLContext ctx;
  ctx.pushToStack(alsFact.staticCast<QObject>());

  parser::CoreXMLParser parser;

  parser.parse(fs,ch,ctx);

}

}//namespace test

