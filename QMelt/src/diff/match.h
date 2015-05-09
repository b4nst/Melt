#pragma once
#include "common.h"


// QT
#include <QObject>
#include <QSharedPointer>


M_NAMESPACE_DIFF_BEGIN

class Match : public QObject
{
    Q_OBJECT
public:
    explicit Match(QObject *parent = 0);

    double similarity;
    QObject* origin;
    QObject* left;
    QObject* right;

    ~Match();
//    Match(QSharedPointer<QObject> origin,
//                QSharedPointer<QObject> left,
//                QSharedPointer<QObject> right,
//                double similarity, QObject *parent = 0);

signals:

public slots:
};


M_NAMESPACE_DIFF_END
