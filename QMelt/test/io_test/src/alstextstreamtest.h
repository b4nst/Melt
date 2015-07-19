#ifndef ALSTEXTSTREAMTEST_H
#define ALSTEXTSTREAMTEST_H

#include <QObject>
#include <QTest>

#include "common.h"

#include "src/io/alstextstream.h"

class AlsTextStreamTest : public QObject
{
  Q_OBJECT
private:
   io::AlsTextStream *_inputStream;
   io::AlsTextStream *_outputStream;
   QFile _inputFile;
   QFile _outputFile;
public:
  explicit AlsTextStreamTest(QObject *parent = 0);

private slots:
  void initTestCase();
  void init();
  void cleanup();
  void testIsOk();
  void testReadNextLine();
  void testIsExhausted();
  void testWrite();
};

#endif // ALSTEXTSTREAMTEST_H
