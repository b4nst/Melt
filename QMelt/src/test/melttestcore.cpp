// ABLETON
#include "src/ableton/alsableton.h"
#include "src/ableton/alsliveset.h"

// IO
#include "src/io/alsfilesystem.h"

// TEST
#include "src/test/melttestcore.h"

// QT
#include <QSharedPointer>
#include <QString>
#include <QDebug>

#if defined (Q_OS_WIN)
#define M_EXAMPLE_DIR "../Example/"
#elif defined (Q_OS_OSX)
#define M_EXAMPLE_DIR "../../../../Example/"
#elif defined (Q_OS_LINUX)
#define M_EXAMPLE_DIR "../../../../Example/"
#endif


#define M_PATH_ALS_KENYA QString(M_EXAMPLE_DIR) + QString("als-xml/sample_project_01.xml")
#define M_PATH_ALS_KENYA_OUTPUT QString(M_EXAMPLE_DIR) + QString("als-xml/sample_project_01_output.xml")
#define M_PATH_ALS_ELATION QString(M_EXAMPLE_DIR) + QString("als-xml/sample_project_02.xml")
#define M_PATH_ALS_EMPTY QString(M_EXAMPLE_DIR) + QString("als-xml/sample_project_03.xml")
#define M_PATH_ALS_EMPTY2 QString(M_EXAMPLE_DIR) + QString("als-xml/sample_project_04.xml")
#define M_PATH_ALS_EMPTY3 QString(M_EXAMPLE_DIR) + QString("als-xml/sample_project_05.xml")
#define M_PATH_ALS_DRUMS QString(M_EXAMPLE_DIR) + QString("als-xml/sample_project_06.xml")
#define M_PATH_ALS_DRUMS_RENAMED_TRACK QString(M_EXAMPLE_DIR) + QString("als-xml/sample_project_06_renamed_track.xml")
#define M_PATH_ALS_DRUMS_REMOVED_TRACK QString(M_EXAMPLE_DIR) + QString("als-xml/sample_project_06_removed_track.xml")
#define M_PATH_ALS_DRUMS_REMOVED_CLIP QString(M_EXAMPLE_DIR) + QString("als-xml/sample_project_06_removed_clip.xml")


M_NAMESPACE_TEST_BEGIN


void MeltTestCore::testParser()
{
  QString filePath(M_PATH_ALS_KENYA);
  QSharedPointer<ableton::AlsAbleton> ableton;
  io::AlsFilesystem::load(filePath, ableton);
  io::AlsFilesystem::save(QString(M_PATH_ALS_KENYA_OUTPUT), ableton);
}

M_NAMESPACE_TEST_END
