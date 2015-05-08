#include "common.h"

// APP
#include "src/app/meltapplication.h"
#include "src/app/meltcommandline.h"

// TEST
#include "src/test/melttestcore.h"


M_NAMESPACE_APP_BEGIN


MeltApplication::MeltApplication(int argc, char* argv[])
: QApplication(argc, argv)
, _arguments(MeltCommandLine::parse(*this))
{
  test::MeltTestCore::testParser();
}

MeltApplication::~MeltApplication()
{

}


M_NAMESPACE_APP_END
