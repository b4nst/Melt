#include <QTest>

#include "src/alstextstreamtest.h"


int main(int argc, char *argv[])
{
   int status = 0;

   {
     AlsTextStreamTest testATST;
     status |= QTest::qExec(&testATST,argc,argv);
   }

   return status;
}
