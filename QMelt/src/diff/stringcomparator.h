#pragma once
#include "common.h"


// QT
#include <QObject>
#include <QVector>
#include <QSharedPointer>
#include <QSet>


M_NAMESPACE_DIFF_BEGIN

class StringComparator : public QObject
{
    Q_OBJECT
public:
    explicit StringComparator(QObject *parent = 0);

    double computeSimilarity(QSharedPointer<QString>& first_, QSharedPointer<QString>& second_);
private:
    QSet<QString> generatePairs(QString& input);
signals:

public slots:
};


M_NAMESPACE_DIFF_END
