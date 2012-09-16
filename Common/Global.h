#pragma once

#include <QtCore/QtGlobal>
#include <QtCore/QDebug>
#include <QtCore/QString>

#if defined(COMMON_LIBRARY)
    #define COMMON_EXPORT Q_DECL_EXPORT
#else
    #define COMMON_EXPORT Q_DECL_IMPORT
#endif
