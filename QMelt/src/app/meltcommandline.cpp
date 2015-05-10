// APP
#include "src/app/meltcommandline.h"

// QT
#include <QCommandLineParser>
#include <QDebug>


M_NAMESPACE_APP_BEGIN


void MeltCommandLine::parse(const QStringList& args_)
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


  parser.process(args_);
  qDebug() << "Parse ok";

  isOk = parser.isSet(mergeOption) ^ parser.isSet(diffOption);
  isMerging = parser.isSet(mergeOption);
  basePath = parser.value(basePathOption);
  localPath = parser.value(localPathOption);
  remotePath = parser.value(remotePathOption);
  arguments->mergePath = parser.value(mergePathOption);

  if (isOk && isMerging)
  {
    isOk = !basePath.isEmpty() &&
                      !localPath.isEmpty() &&
                      !remotePath.isEmpty() &&
                      !mergePath.isEmpty();
  }
  else if (isOk)
  {
    isOk = !localPath.isEmpty() &&
                      !remotePath.isEmpty() &&
                      basePath.isEmpty() &&
                      mergePath.isEmpty();
  }
}


M_NAMESPACE_APP_END
