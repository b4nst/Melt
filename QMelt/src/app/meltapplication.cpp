// APP
#include "src/app/meltapplication.h"


M_NAMESPACE_APP_BEGIN


MeltApplication::MeltApplication(int argc, char* argv[])
: QApplication(argc, argv)
, _arguments(MeltCommandLine::parse(arguments()))
{

}

MeltApplication::~MeltApplication()
{

}

M_NAMESPACE_APP_END
