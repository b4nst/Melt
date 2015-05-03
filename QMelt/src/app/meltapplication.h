#pragma once


// QT
#include <QApplication>


namespace app
{


class MeltApplication : public QApplication
{
public:
    MeltApplication(int argc, char* argv[]);
    ~MeltApplication();
};


} // namespace app
