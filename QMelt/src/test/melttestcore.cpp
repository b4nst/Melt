// ABLETON
#include "src/ableton/alsableton.h"

// IO
#include "src/io/alsfilesystem.h"

// TEST
#include "src/test/melttestcore.h"


#if defined (Q_OS_WIN)
#define M_EXAMPLE_DIR "../Example/"
#elif defined (Q_OS_OSX)
#define M_EXAMPLE_DIR "../../../../Example/"
#endif


#define M_PATH_ALS_KENYA QString(M_EXAMPLE_DIR) + QString("als-xml/sample_project_01.xml")
#define M_PATH_ALS_KENYA_OUTPUT QString(M_EXAMPLE_DIR) + QString("als-xml/sample_project_01_output.xml")
#define M_PATH_ALS_ELATION QString(M_EXAMPLE_DIR) + QString("als-xml/sample_project_02.xml")


M_NAMESPACE_TEST_BEGIN


void MeltTestCore::testParser()
{
  QString filePath(M_PATH_ALS_KENYA);
  QSharedPointer<ableton::AlsAbleton> ableton;
  io::AlsFilesystem::load(filePath, ableton);
  io::AlsFilesystem::save(QString(M_PATH_ALS_KENYA_OUTPUT), ableton);
}


M_NAMESPACE_TEST_END
