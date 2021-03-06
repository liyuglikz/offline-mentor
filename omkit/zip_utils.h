#ifndef ZIP_UTILS_H
#define ZIP_UTILS_H

#include "omkit_global.h"

#include <QString>

OMKITSHARED_EXPORT bool compress(QString srcDirPath, QString dstPath);
OMKITSHARED_EXPORT bool extract(QString srcPath, QString dstDirPath);

#endif // ZIP_UTILS_H
