// APP
#include "src/app/meltcommandline.h"

// QT
#include <QCommandLineParser>
#include <QDebug>


M_NAMESPACE_APP_BEGIN


MeltCommandLine MeltCommandLine::parse(const QStringList& args_)
{
  MeltCommandLine aCommandLine;
  QCommandLineParser parser;
  QCommandLineOption diffOption ("d", "Diff mode");
  QCommandLineOption mergeOption ("m", "Merge mode");

  QCommandLineOption testPathOption (QStringList() << "t" << "test", "Path to the test <file>.", "file");
  QCommandLineOption basePathOption (QStringList() << "base", "Path to the base <file>.", "file");
  QCommandLineOption localPathOption (QStringList() << "local", "Path to the local <file>.", "file");
  QCommandLineOption remotePathOption (QStringList() << "remote", "Path to the remote <file>.", "file");
  QCommandLineOption mergePathOption (QStringList() << "merge", "Path to the merge <file>.", "file");

  parser.addOption(diffOption);
  parser.addOption(mergeOption);
  parser.addOption(testPathOption);
  parser.addOption(basePathOption);
  parser.addOption(localPathOption);
  parser.addOption(remotePathOption);
  parser.addOption(mergePathOption);

  parser.process(args_);

  if (parser.isSet(diffOption) && !parser.isSet(mergeOption) && !parser.isSet(testPathOption))
  {
    aCommandLine._mode = kDIFF_MODE;
  }
  else if (!parser.isSet(diffOption) && parser.isSet(mergeOption) && !parser.isSet(testPathOption))
  {
    aCommandLine._mode = kMERGE_MODE;
  }
  else if (!parser.isSet(diffOption) && !parser.isSet(mergeOption) && parser.isSet(testPathOption))
  {
    aCommandLine._mode = kTEST_MODE;
  }
  else
  {
    aCommandLine._mode = kERROR;
    return aCommandLine;
  }

  aCommandLine._basePath = aCommandLine._mode == kTEST_MODE ? parser.value(testPathOption) : parser.value(basePathOption);
  aCommandLine._localPath = parser.value(localPathOption);
  aCommandLine._remotePath = parser.value(remotePathOption);
  aCommandLine._mergePath = parser.value(mergePathOption);

  return aCommandLine;
}


M_NAMESPACE_APP_END
