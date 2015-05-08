#include "src/test/melttestcore.h"

#include "src/io/alsfilesystem.h"

#ifdef Q_OS_OSX
#define EXAMPLE_DIR "../../../../Example/"
#elif Q_OS_WIN
#define EXAMPLE_DIR "../Example/"
#endif



namespace test {
MeltTestCore::MeltTestCore(QObject *parent) : QObject(parent)
{

}

void MeltTestCore::testParser()
{
  QString filePath(EXAMPLE_DIR + QString("als-xml/sample_project_01.xml"));
  io::AlsFilesystem::load(filePath);

}

}//namespace test

