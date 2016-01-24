// APP
#include "src/app/meltapplication.h"
#include "src/app/meltcommandline.h"

// IO
#include "src/io/alsfilesystem.h"

// TEST
#include "src/test/melttestcore.h"

// QT
#include <QFile>
#include <QDebug>


M_NAMESPACE_APP_BEGIN


MeltApplication::MeltApplication(int argc, char* argv[])
: QApplication(argc, argv)
{
  //test::MeltTestCore::testQObjectToString();
  //test::MeltTestCore::testDepthFirstTraversal();
  //test::MeltTestCore::testMatch();
  //processArguments();
}

MeltApplication::~MeltApplication()
{

}
/*
bool MeltApplication::processArguments()
{
  bool result = false;
  if (!Arguments->isOk)
  {
    return result;
  }
  
  if (Arguments->isMerging)
  {
    result = io::AlsFilesystem::load(Arguments->basePath, _baseAbleton) &&
             io::AlsFilesystem::load(Arguments->remotePath, _remoteAbleton) &&
             io::AlsFilesystem::load(Arguments->localPath, _localAbleton);
  }

  else
  { 
    result = io::AlsFilesystem::load(Arguments->remotePath, _remoteAbleton) &&
             io::AlsFilesystem::load(Arguments->localPath, _localAbleton);
  }

  return result;
}
*/

M_NAMESPACE_APP_END
