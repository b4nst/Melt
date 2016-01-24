// APP
#include "src/app/meltapplication.h"

int main(int argc, char *argv[])
{
    app::MeltApplication meltApplication (argc, argv);
    return meltApplication.exec();
}
