#include "src/app/melt.h"

// IO
#include "src/io/alsfilesystem.h"

// QT
#include <QDebug>


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
  if (Arguments.mode() == MeltCommandLine::kERROR)
  {
    return false;
  }

  bool result = false;

  if (Arguments.mode() == MeltCommandLine::kMERGE_MODE)
  {
    result = io::AlsFilesystem::load(Arguments.base(), _baseAbleton) &&
             io::AlsFilesystem::load(Arguments.remote(), _remoteAbleton) &&
             io::AlsFilesystem::load(Arguments.local(), _localAbleton);
  }
  else if (Arguments.mode() == MeltCommandLine::kDIFF_MODE)
  {
    result = io::AlsFilesystem::load(Arguments.remote(), _remoteAbleton) &&
             io::AlsFilesystem::load(Arguments.local(), _localAbleton);
  }
  else if (Arguments.mode() == MeltCommandLine::kTEST_MODE)
  {
    _baseAbleton = io::AlsFilesystem::loadAls(Arguments.base());
  }

  if (!result)
  {
    qDebug() << "load fail";
    _baseAbleton.clear();
    _localAbleton.clear();
    _remoteAbleton.clear();
    _mergeAbleton.clear();
  }
  else
  {
    qDebug() << "load ok";
  }

  return result;
}


M_NAMESPACE_APP_END
