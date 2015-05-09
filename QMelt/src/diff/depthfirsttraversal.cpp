#include "depthfirsttraversal.h"

M_NAMESPACE_DIFF_BEGIN

DepthFirstTraversal::DepthFirstTraversal(QObject *parent) : QObject(parent)
{

}

QVector<QSharedPointer<QObject>> DepthFirstTraversal::traverse(QSharedPointer<QObject>& rootObject_) {
    QVector<QSharedPointer<QObject>> result = QVector<QSharedPointer<QObject>>();
    result.append(rootObject_);
    QObjectList children = rootObject_->children();
    for (int i = 0; i < children.size(); i++) {
       QSharedPointer<QObject> child (children[i]);
       result += traverse(child);
    }
    return result;
}

M_NAMESPACE_DIFF_END
