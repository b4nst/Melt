#ifndef MELTTESTCORE_H
#define MELTTESTCORE_H

#include <QObject>

namespace test {
class MeltTestCore : public QObject
{
  Q_OBJECT
public:
  explicit MeltTestCore(QObject *parent = 0);

  static void testParser();

signals:

public slots:
};
}//namespace test


#endif // MELTTESTCORE_H
