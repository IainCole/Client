#pragma once

#include <QtCore/QtGlobal>

#if defined(START_LIBRARY)
    #define START_EXPORT Q_DECL_EXPORT
#else
    #define START_EXPORT Q_DECL_IMPORT
#endif
