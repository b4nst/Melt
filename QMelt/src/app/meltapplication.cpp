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

// UI
#include "src/ui/meltui.h"


M_NAMESPACE_APP_BEGIN


MeltApplication::MeltApplication(int argc, char* argv[])
: QApplication(argc, argv)
, Arguments(MeltCommandLine::parse(*this))
{
  //test::MeltTestCore::testParser();
  processArguments();
}

MeltApplication::~MeltApplication()
{

}

void MeltApplication::processArguments()
{
  if (!Arguments->isOk)
  {
    return;
  }
  
  if (Arguments->isMerging)
  {
    io::AlsFilesystem::load(Arguments->basePath,
                            _baseAbleton);
    io::AlsFilesystem::load(Arguments->remotePath,
                            _remoteAbleton);
    io::AlsFilesystem::load(Arguments->localPath,
                            _localAbleton);
  }
  else
  { 
    io::AlsFilesystem::load(Arguments->remotePath,
                            _remoteAbleton);
    io::AlsFilesystem::load(Arguments->localPath,
                            _localAbleton);
  }
}


M_NAMESPACE_APP_END
