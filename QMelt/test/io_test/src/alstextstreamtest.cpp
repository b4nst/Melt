#include "src/alstextstreamtest.h"

#define TEST_FILE "../sample.xml"

AlsTextStreamTest::AlsTextStreamTest(QObject *parent) : QObject(parent)
{

}

void AlsTextStreamTest::initTestCase()
{
  _textStream = new io::AlsTextStream(QFile(TEST_FILE),this);
}

void AlsTextStreamTest::cleanupTestCase()
{
  delete _textStream;
}
