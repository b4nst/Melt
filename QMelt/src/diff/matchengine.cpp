#include "matchengine.h"
#include <QMetaProperty>
#include "stringcomparator.h"
#include <QDebug>

M_NAMESPACE_DIFF_BEGIN

MatchEngine::MatchEngine(QObject *parent) : QObject(parent)
{

}

QSharedPointer<MatchResult> MatchEngine::match(
                                  QVector<QObject*>& leftObjects_,
                                  QVector<QObject*>& rightObjects_) {

    QMap<QObject*, QSharedPointer<Match>> map;


    for (QObject* left : leftObjects_) {
        for (QObject* right : rightObjects_) {
            // only nodes of the same type can be considered similar
            if (left->metaObject()->className() == right->metaObject()->className()) {
                double similarity = computeSimilarity(left, right);
                QSharedPointer<Match> match = QSharedPointer<Match>(new Match());
                match->left = left;
                match->right = right;
                match->similarity = similarity;

                if (map.contains(left)) {
                    if (map[left]->similarity < similarity) {
                        map.insert(left, match);
                    }
                } else {
                    map.insert(left, match);
                }

            }

        }
    }

    for (QObject* key : map.keys()) {
        qDebug() << key;
        qDebug() << map[key]->left;
        qDebug() << map[key]->right;
        qDebug() << map[key]->similarity;

    }

    /*
        // calculate similarity for all combinations of nodes
        for (int i = 0; i < leftWrappers.length; i++) {
            AbstractModelWrapper leftNode = leftWrappers[i];
            for (int j = 0; j < rightWrappers.length; j++) {
                AbstractModelWrapper rightNode = rightWrappers[j];
                // only nodes of the same type can be considered similar
                if (leftNode.getType().equals(rightNode.getType())) {
                    double similarity = computeSimilarity(leftNode, rightNode);
                    NodeMatchingResult result = new NodeMatchingResult(leftNode, rightNode, similarity);
                    result.setThreshold(config.getThresholdValue());
                    // get the existing mapping for the given left node
                    NodeMatchingResult mappedResult = matchMap.get(leftNode);
                    // if there is a mapping for the given left node
                    if (mappedResult != null) {
                        // if the new match has a higher similarity than the old
                        // one
                        if (mappedResult.getSimilarity() < similarity) {
                            // we map the left node to the new matching result,
                            // overwriting the old one
                            matchMap.put(leftNode, result);
                        }
                    } else {
                        // if no mapping is found we map the left node to the
                        // new matching result
                        matchMap.put(leftNode, result);
                    }
                }
            }

            if (monitor != null) {
                // check if user clicked on cancel
                if (monitor.isCanceled()) {
                    throw new OperationCanceledException();
                }
                monitor.worked(1);
            }
        }
     */
}

double MatchEngine::computeSimilarity(QObject* first_,
                                      QObject* second_) {
    const QMetaObject* firstMetaObject = first_->metaObject();
    const QMetaObject* secondMetaObject = second_->metaObject();
    QString firstClassName = QString(firstMetaObject->className());
    QString secondClassName = QString(secondMetaObject->className());
    if (firstClassName != secondClassName) {
        // objects of different classes can never match
        return 0;
    }

    StringComparator sc;
    QSharedPointer<QString> firstString = toString(first_);
    QSharedPointer<QString> secondString = toString(second_);
    return sc.computeSimilarity(firstString, secondString);
}

QSharedPointer<QString> MatchEngine::toString(QObject* object_) {
    const QMetaObject* metaObject = object_->metaObject();
    int propertyCount = object_->metaObject()->propertyCount();
    QStringList stringList = QStringList();
    for (int i = 0; i < propertyCount; i++) {
        QMetaProperty property = object_->metaObject()->property(i);
        stringList << (property.name());
        stringList << (object_->property(property.name()).toString());
    }

    return QSharedPointer<QString>::create(stringList.join(','));
}

M_NAMESPACE_DIFF_END
