// APP
#include "src/app/meltapplication.h"

// UI
#include "src/ui/meltui.h"


int main(int argc, char *argv[])
{
    app::MeltApplication a(argc, argv);
    MeltUI ui(a);
  
    ui.show();
    return a.exec();
}
