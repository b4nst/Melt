#include "src/app/melt.h"

// IO
#include "src/io/alsfilesystem.h"


M_NAMESPACE_APP_BEGIN


Melt::Melt(const MeltCommandLine& arguments_, QObject *parent)
: QObject(parent)
, Arguments(arguments_)
, _baseAbleton(nullptr)
, _localAbleton(nullptr)
, _remoteAbleton(nullptr)
, _mergeAbleton(nullptr)
{

}

bool Melt::loadArguments()
{
  if (!Arguments.isOk)
  {
    return false;
  }

  bool result = false;

  if (Arguments.isMerging)
  {
    result = io::AlsFilesystem::load(Arguments.basePath, _baseAbleton) &&
             io::AlsFilesystem::load(Arguments.remotePath, _remoteAbleton) &&
             io::AlsFilesystem::load(Arguments.localPath, _localAbleton);
  }

  else
  {
    result = io::AlsFilesystem::load(Arguments.remotePath, _remoteAbleton) &&
             io::AlsFilesystem::load(Arguments.localPath, _localAbleton);
  }

  if (!result)
  {
    _baseAbleton.clear();
    _localAbleton.clear();
    _remoteAbleton.clear();
    _mergeAbleton.clear();
  }

  return result;
}


M_NAMESPACE_APP_END
