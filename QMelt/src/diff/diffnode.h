#pragma once
#include "src/common/common.h"


// QT
#include <QObject>


M_NAMESPACE_DIFF_BEGIN

class DiffNode : public QObject
{
    Q_OBJECT
public:
    explicit DiffNode(QObject *parent = 0);

    enum Type { Added, Removed, Changed, Conflict };

    Type type;
signals:

public slots:
};


M_NAMESPACE_DIFF_END
