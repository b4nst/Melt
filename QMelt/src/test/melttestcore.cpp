#include "src/test/melttestcore.h"
#include "src/ableton/alsableton.h"

#include "src/io/alsfilesystem.h"

#if defined (Q_OS_WIN)
#define EXAMPLE_DIR "../Example/"
#elif defined (Q_OS_OSX)
#define EXAMPLE_DIR "../../../../Example/"
#endif



namespace test {
MeltTestCore::MeltTestCore(QObject *parent) : QObject(parent)
{

}

void MeltTestCore::testParser()
{
  QString filePath(EXAMPLE_DIR + QString("als-xml/sample_project_01.xml"));
  QSharedPointer<ableton::AlsAbleton> ableton_;
  io::AlsFilesystem::load(filePath, ableton_);

}

}//namespace test

