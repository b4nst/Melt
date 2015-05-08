#include "src/test/melttestcore.h"

#include "src/io/alsfilesystem.h"

#define EXAMPLE_DIR QString("../Example/als-xml")

namespace test {
MeltTestCore::MeltTestCore(QObject *parent) : QObject(parent)
{

}

void MeltTestCore::testParser()
{
  QString filePath(EXAMPLE_DIR + QString("/sample_project_01.xml"));
  io::AlsFilesystem::load(filePath);

}

}//namespace test

