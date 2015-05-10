#include "matchengine.h"
#include <QMetaProperty>
#include "stringcomparator.h"
#include <QDebug>

M_NAMESPACE_DIFF_BEGIN

MatchEngine::MatchEngine(QObject *parent) : QObject(parent)
{

}

QSharedPointer<MatchResult> MatchEngine::match(QVector<QObject*>& leftObjects_,
                                  QVector<QObject*>& rightObjects_) {

    QMap<QObject*, Match*> leftToMatchMap;
    QVector<QObject*> removed = QVector<QObject*>();
    QVector<QObject*> added = QVector<QObject*>();

    for (int i = 0; i < leftObjects_.length(); i++) {
        QObject* left = leftObjects_[i];
        for (int j = 0; j < rightObjects_.length(); j++) {
            QObject* right = rightObjects_[i];
            // only nodes of the same type can be considered similar
            if (left->metaObject()->className() == right->metaObject()->className()) {
                double similarity = computeSimilarity(left, right);
                Match* match = new Match();
                match->left = left;
                match->right = right;
                match->similarity = similarity;

                if (leftToMatchMap.contains(left)) {
                    if (leftToMatchMap[left]->similarity < similarity) {
                        leftToMatchMap.insert(left, match);
                    }
                } else {
                    leftToMatchMap.insert(left, match);
                }
            }
        }
    }

    QMap<QObject*, Match*> filteredMap;

    for (QObject* key : leftToMatchMap.keys()) {
        Match* value = leftToMatchMap[key];
        if (value->similarity > 0.8) {
            filteredMap.insert(key, value);
        }
    }

    for (QObject* leftObject : leftObjects_) {
        bool leftFound = false;
        for (Match* mapValue : filteredMap.values()) {
            QObject* leftMapValue = mapValue->left;
            if (leftMapValue == leftObject) {
                leftFound = true;
                break;
            }
        }
        if (!leftFound) {
            qDebug() << "left not found";
            qDebug() << *toString(leftObject).data();
            removed.append(leftObject);
        }
    }

    for (QObject* rightObject : rightObjects_) {
        bool rightFound = false;
        for (Match* mapValue : filteredMap.values()) {
            QObject* rightMapValue = mapValue->right;
            if (rightMapValue == rightObject) {
                rightFound = true;
                break;
            }
        }
        if (!rightFound) {
            qDebug() << "right not found";
            qDebug() << *toString(rightObject).data();
            added.append(rightObject);
        }
    }

    qDebug() << "added";
    qDebug() << added.length();
    qDebug() << "removed";
    qDebug() << removed.length();
    qDebug() << "filtered map";
    for (QObject* key : filteredMap.keys()) {
        qDebug() << key;
        qDebug() << filteredMap[key]->left;
        qDebug() << filteredMap[key]->right;
        qDebug() << filteredMap[key]->similarity;
    }


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
