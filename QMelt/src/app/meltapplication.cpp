// APP
#include "src/app/meltapplication.h"
#include "src/app/meltcommandline.h"


// TEST
#include "src/test/melttestcore.h"


namespace app
{


MeltApplication::MeltApplication(int argc, char* argv[])
: QApplication(argc, argv)
, _arguments(MeltCommandLine::parse(*this))
{
  test::MeltTestCore::testParser();
}

MeltApplication::~MeltApplication()
{

}


} // namespace app
