#pragma once

#include <QtCore/QtGlobal>

#if defined(SQUEEZE_LIBRARY)
    #define SQUEEZE_EXPORT Q_DECL_EXPORT
#else
    #define SQUEEZE_EXPORT Q_DECL_IMPORT
#endif
