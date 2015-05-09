#pragma once
#include "common.h"
#include "match.h"


// QT
#include <QObject>
#include <QSharedPointer>
#include <QVector>

M_NAMESPACE_DIFF_BEGIN

class MatchResult : public QObject
{
    Q_OBJECT
public:
    explicit MatchResult(QObject *parent = 0);

    QVector<QSharedPointer<Match>> added;
    QVector<QSharedPointer<Match>> removed;
    QVector<QSharedPointer<Match>> changed;
    QVector<QSharedPointer<Match>> conflicting;
signals:

public slots:
};

M_NAMESPACE_DIFF_END
