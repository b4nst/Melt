// APP
#include "src/app/meltcommandline.h"

// QT
#include <QCommandLineParser>
#include <QStringList>
#include <QDebug>


M_NAMESPACE_APP_BEGIN


QSharedPointer<MeltCommandLine> MeltCommandLine::parse(const MeltApplication& app)
{
  QSharedPointer<MeltCommandLine> arguments (new MeltCommandLine());
  
  QCommandLineParser parser;
  QCommandLineOption diffOption ("d", "Diff mode");
  QCommandLineOption mergeOption ("m", "Merge mode");
  QCommandLineOption basePathOption (QStringList() << "base" << "base-path", "Path to the base <file>.", "file");
  QCommandLineOption localPathOption (QStringList() << "local" << "local-path", "Path to the local <file>.", "file");
  QCommandLineOption remotePathOption (QStringList() << "remote" << "remote-path", "Path to the remote <file>.", "file");
  QCommandLineOption mergePathOption (QStringList() << "merge" << "merge-path", "Path to the merge <file>.", "file");


  parser.addOption(diffOption);
  parser.addOption(mergeOption);
  parser.addOption(basePathOption);
  parser.addOption(localPathOption);
  parser.addOption(remotePathOption);
  parser.addOption(mergePathOption);


  parser.process(app);


  arguments->isOk = parser.isSet(mergeOption) ^ parser.isSet(diffOption);
  arguments->isMerging = parser.isSet(mergeOption);
  arguments->basePath = parser.value(basePathOption);
  arguments->localPath = parser.value(localPathOption);
  arguments->remotePath = parser.value(remotePathOption);
  arguments->mergePath = parser.value(mergePathOption);

  if (arguments->isOk && arguments->isMerging)
  {
    arguments->isOk = !arguments->basePath.isEmpty() &&
                      !arguments->localPath.isEmpty() &&
                      !arguments->remotePath.isEmpty() &&
                      !arguments->mergePath.isEmpty();
  }
  else if (arguments->isOk)
  {
    arguments->isOk = !arguments->localPath.isEmpty() &&
                      !arguments->remotePath.isEmpty() &&
                      arguments->basePath.isEmpty() &&
                      arguments->mergePath.isEmpty();
  }

  return arguments;
}


M_NAMESPACE_APP_END
