#pragma once

#include <QtCore/QtGlobal>

#if defined(RECORDER_LIBRARY)
    #define RECORDER_EXPORT Q_DECL_EXPORT
#else
    #define RECORDER_EXPORT Q_DECL_IMPORT
#endif
