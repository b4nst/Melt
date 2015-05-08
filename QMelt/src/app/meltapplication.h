#pragma once
#include "src/app/meltcommon.h"


// QT

#include <QApplication>


M_NAMESPACE_APP_BEGIN


class MeltApplication : public QApplication
{
public:
    MeltApplication(int argc, char* argv[]);
    ~MeltApplication();
};


M_NAMESPACE_APP_END
