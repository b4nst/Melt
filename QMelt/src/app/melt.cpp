#include "src/app/melt.h"

#include <QQmlContext>


M_NAMESPACE_APP_BEGIN


Melt::Melt(QObject *parent)
: QObject(parent)
, _engine(QUrl(QStringLiteral("qrc:/main.qml")))
{
  _engine.rootContext()->setContextProperty("melt", this);
}

Melt::~Melt()
{

}

void Melt::openA(const QString &a)
{
  qDebug() << a;
  emit aFileOpened();
}

QString Melt::aFile()
{
  return _aFile.absoluteFilePath();
}

M_NAMESPACE_APP_END
