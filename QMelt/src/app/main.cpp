// APP
#include "src/app/meltapplication.h"

// UI
#include "src/ui/meltui.h"

#include "src/test/melttestcore.h"

int main(int argc, char *argv[])
{
    app::MeltApplication a(argc, argv);
    test::MeltTestCore::testParser();
    MeltUI ui(a);
  
    ui.show();
    return a.exec();
}
