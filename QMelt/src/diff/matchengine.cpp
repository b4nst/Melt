#include "matchengine.h"


M_NAMESPACE_DIFF_BEGIN

MatchEngine::MatchEngine(QObject *parent) : QObject(parent)
{

}

QSharedPointer<MatchResult> MatchEngine::match(QVector<QSharedPointer<QObject>>& originObjects_,
                                  QVector<QSharedPointer<QObject>>& leftObjects_,
                                  QVector<QSharedPointer<QObject>>& rightObjects_) {
    /*
     * - iterate over left objects, create matches
     * - iterate over right objects, try to pair up with existing matches
     * - iterate over origin objects, try to pair up with existing matches
     * - build match result object
     */
}

M_NAMESPACE_DIFF_END
