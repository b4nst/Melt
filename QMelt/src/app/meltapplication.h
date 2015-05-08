#pragma once
#include "src/app/meltcommon.h"


// QT

#include <QApplication>
#include <QSharedPointer>


M_NAMESPACE_APP_BEGIN

class MeltCommandLine;
/*!
 * \brief The MeltApplication class
 */
class MeltApplication : public QApplication
{
public:
    explicit MeltApplication(int argc, char* argv[]);
    ~MeltApplication();

private:
  /*!
   * \brief Command line arguments
   */
  QSharedPointer<const MeltCommandLine> _arguments;
};


M_NAMESPACE_APP_END
