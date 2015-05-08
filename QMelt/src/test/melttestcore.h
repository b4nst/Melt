#pragma once
#include "common.h"

// QT
#include <QObject>


M_NAMESPACE_TEST_BEGIN


class MeltTestCore : public QObject
{
  Q_OBJECT
public:
  ~MeltTestCore() {}

  static void testParser();

protected:
  explicit MeltTestCore(QObject *parent = 0) {}
};


M_NAMESPACE_TEST_END
