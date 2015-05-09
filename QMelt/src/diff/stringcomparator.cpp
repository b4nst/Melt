#include "stringcomparator.h"

M_NAMESPACE_DIFF_BEGIN

StringComparator::StringComparator(QObject *parent) : QObject(parent)
{

}

double StringComparator::computeSimilarity(QSharedPointer<QString>& first_, QSharedPointer<QString>& second_) {
    double result = 0;

    if (first_.isNull() || second_.isNull()) {
        return 0;
    }

    QString* firstString = first_.data();
    int firstLength = firstString->length();
    QString* secondString = second_.data();
    int secondLength = secondString->length();

    if (firstLength == 1 || secondLength == 1) {
        if (firstString == secondString) {
            return 1;
        }
        return 0;
    }
    if (firstLength == 0 && secondLength == 0) {
        return 1;
    }
    QString firstLower = firstString->toLower();
    QString secondLower = secondString->toLower();

    QSet<QString> firstPairs = generatePairs(firstLower);
    QSet<QString> secondPairs = generatePairs(secondLower);

    int totalSize = firstPairs.size() + secondPairs.size();

    if (totalSize == 0) {
        return 0;
    }

    firstPairs.intersect(secondPairs);

    int inter = firstPairs.size();
    result = inter * 2.0 / totalSize;
    if (result > 1) {
        result = 1;
    }
    if (result == 1.0 && !(firstString == secondString)) {
        return 0.999999;
    }

    return result;
}

QSet<QString> StringComparator::generatePairs(QString& input_) {
    QSet<QString> result = QSet<QString>();
    for (int i = 0; i < input_.length() - 1; i++) {
        result += (input_.mid(i, 2));
    }
    if (input_.length() % 2 == 1 && input_.length() > 1) {
        result += (input_.mid(input_.length() - 2, 2));
    }
    return result;
}

M_NAMESPACE_DIFF_END
