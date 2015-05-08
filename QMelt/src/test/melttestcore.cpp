// ABLETON
#include "src/ableton/alsableton.h"

// IO
#include "src/io/alsfilesystem.h"

// TEST
#include "src/test/melttestcore.h"


#if defined (Q_OS_WIN)
#define EXAMPLE_DIR "../Example/"
#elif defined (Q_OS_OSX)
#define EXAMPLE_DIR "../../../../Example/"
#endif


M_NAMESPACE_TEST_BEGIN


void MeltTestCore::testParser()
{
  QString filePath(EXAMPLE_DIR + QString("als-xml/sample_project_01.xml"));
  QSharedPointer<ableton::AlsAbleton> ableton_;
  io::AlsFilesystem::load(filePath, ableton_);

}


M_NAMESPACE_TEST_END
