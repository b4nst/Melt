#include "src/alstextstreamtest.h"

#include <QDir>

#define M_RESOURCES_DIR "../../resources/"
#define M_PATH_INPUT QString(M_RESOURCES_DIR) + QString("input.txt")
#define M_PATH_OUTPUT QString(M_RESOURCES_DIR) + QString("output.txt")

AlsTextStreamTest::AlsTextStreamTest(QObject *parent) : QObject(parent)
{

}

void AlsTextStreamTest::initTestCase()
{
  _inputFile.setFileName(M_PATH_INPUT);
  _outputFile.setFileName(M_PATH_OUTPUT);
  _inputFile.open(QIODevice::ReadOnly);
  _outputFile.open(QIODevice::WriteOnly);
}

void AlsTextStreamTest::init()
{
  _inputStream = new io::AlsTextStream(_inputFile,this);
  _outputStream = new io::AlsTextStream(_outputFile,this);
}

void AlsTextStreamTest::cleanup()
{
  delete _inputStream;
  delete _outputStream;
}

void AlsTextStreamTest::testIsOk()
{
  QVERIFY2(_inputStream->isOk(),"Bad input !");
  QVERIFY2(_outputStream->isOk(),"Bad output !");
}

void AlsTextStreamTest::testIsExhausted()
{
  for (int i = 0; i < 5; ++i) {
    _inputStream->readNextLine();
  }
  QVERIFY2(_inputStream->isExhausted(),"Input file is not exhausted !");
}

void AlsTextStreamTest::testReadNextLine()
{
  QCOMPARE(_inputStream->readNextLine(),QString("line1"));
  QCOMPARE(_inputStream->readNextLine(),QString("line2"));
  QCOMPARE(_inputStream->readNextLine(),QString("line3"));
  QCOMPARE(_inputStream->readNextLine(),QString("line4"));
  QCOMPARE(_inputStream->readNextLine(),QString("line5"));
}

void AlsTextStreamTest::testWrite()
{
  _outputStream->write("dummy data");
  delete _outputStream;
  _outputFile.close();
  _outputFile.open(QIODevice::ReadOnly);
  _outputStream = new io::AlsTextStream(_outputFile,this);
  QCOMPARE(_outputStream->readNextLine(),QString("dummy data"));
  QVERIFY(_outputStream->isExhausted());
  _outputFile.close();
  _outputFile.open(QIODevice::WriteOnly);
}
