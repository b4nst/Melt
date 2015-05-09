#include "depthfirsttraversal.h"

M_NAMESPACE_DIFF_BEGIN

DepthFirstTraversal::DepthFirstTraversal(QObject *parent) : QObject(parent)
{

}

QVector<QObject*> DepthFirstTraversal::traverse(QObject* rootObject_) {
    QVector<QObject*> result = QVector<QObject*>();
    result.append(rootObject_);
    for (auto child : rootObject_->children()) {
       result += traverse(child);
    }
    return result;
}

M_NAMESPACE_DIFF_END
