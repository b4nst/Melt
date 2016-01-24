#pragma once
#include "src/common/common.h"

// QT
#include <QByteArray>

M_NAMESPACE_UTILS_BEGIN

class ZLibHelper
{
public:
    static bool compress(QByteArray input, QByteArray &output, int level = -1);
    static bool uncompress(QByteArray input, QByteArray &output);
};

M_NAMESPACE_UTILS_END
