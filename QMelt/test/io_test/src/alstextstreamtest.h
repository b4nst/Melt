#ifndef ALSTEXTSTREAMTEST_H
#define ALSTEXTSTREAMTEST_H

#include <QObject>

#include "common.h"

#include "src/io/alstextstream.h"

class AlsTextStreamTest : public QObject
{
  Q_OBJECT
private:
   io::AlsTextStream *_textStream;
public:
  explicit AlsTextStreamTest(QObject *parent = 0);

private slots:
  void initTestCase();
  void cleanupTestCase();
};

#endif // ALSTEXTSTREAMTEST_H
