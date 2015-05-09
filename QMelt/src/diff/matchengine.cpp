#include "matchengine.h"
#include <QMetaProperty>
#include "stringcomparator.h"

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

double MatchEngine::computeSimilarity(QSharedPointer<QObject>& first_,
                                      QSharedPointer<QObject>& second_) {
    const QMetaObject* firstMetaObject = first_->metaObject();
    const QMetaObject* secondMetaObject = second_->metaObject();
    QString firstClassName = QString(firstMetaObject->className());
    QString secondClassName = QString(secondMetaObject->className());
    if (firstClassName != secondClassName) {
        // objects of different classes can never match
        return 0;
    }

    StringComparator sc;
    QSharedPointer<QString> firstString = toString(first_.data());
    QSharedPointer<QString> secondString = toString(second_.data());
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
