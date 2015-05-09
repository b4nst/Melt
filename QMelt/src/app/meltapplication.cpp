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
, _arguments(MeltCommandLine::parse(*this))
{
  processArguments();
}

MeltApplication::~MeltApplication()
{

}

void MeltApplication::processArguments()
{
  if (!_arguments->isOk)
  {
    return;
  }
  
  if (_arguments->isMerging)
  {
    io::AlsFilesystem::load(_arguments->basePath,
                            _baseAbleton);
    io::AlsFilesystem::load(_arguments->remotePath,
                            _remoteAbleton);
    io::AlsFilesystem::load(_arguments->localPath,
                            _localAbleton);
  }
  else
  { 
    io::AlsFilesystem::load(_arguments->remotePath,
                            _remoteAbleton);
    io::AlsFilesystem::load(_arguments->localPath,
                            _localAbleton);
  }
}


M_NAMESPACE_APP_END
