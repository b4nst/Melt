#pragma once
#include "src/common/common.h"

// QT
#include <QApplication>

// app
#include "src/app/melt.h"
#include "src/app/meltcommandline.h"


M_NAMESPACE_APP_BEGIN

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
    MeltCommandLine _arguments;
    Melt _melt;
};


M_NAMESPACE_APP_END
