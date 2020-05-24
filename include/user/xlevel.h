
#ifndef __MACRO_XLEVEL_H__
#define __MACRO_XLELVE_H__

#include "xsys/xmax.h"

enum xLevel {
    xLevelError = 0,
    xLevelWarn = 1,
    xLevelInfo = 2,
    xLevelDebug = 3,
    xLevelReserve
};

typedef struct _xLevelInfo {
    char moudle[MOUDLE_MAX_NAME + 1];
    xLevel level2File;
    xLevel level2Screen;
} xLevelInfo;

#endif //__MACRO_XLEVEL_H__