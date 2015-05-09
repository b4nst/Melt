#pragma once
#include "common.h"


// QT
#include <QObject>


M_NAMESPACE_DIFF_BEGIN


class DiffEngine : public QObject
{
    Q_OBJECT
public:
    explicit DiffEngine(QObject *parent = 0);

signals:

public slots:
};


M_NAMESPACE_DIFF_END
