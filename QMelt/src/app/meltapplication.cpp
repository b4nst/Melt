// APP
#include "src/app/meltapplication.h"
#include "src/app/meltcommandline.h"

#include "src/io/alsfilesystem.h"


namespace app
{


MeltApplication::MeltApplication(int argc, char* argv[])
: QApplication(argc, argv)
, _arguments(MeltCommandLine::parse(*this))
{

}

MeltApplication::~MeltApplication()
{

}


} // namespace app
