#ifndef __MACRO_XLOG_SYS_H__
#define __MACRO_XLOG_SYS_H__

#include <stdlib.h>

#include <sys/types.h>

#include "user/xerror.h"
#include "user/xlevel.h"

void xErrorSys(const char* fmt, ...);

xStatus xRegisterSys(const pid_t ppid, const pid_t pid, const char* moudle, uint trytimes, uint timeout);
xStatus xUnRegisterSys(const pid_t ppid, const pid_t pid);

inline void xExit(const char* ch1, const char* cmp, const char* ch2, const char* fmt, ...)
{
    #ifdef ERROR_USE_FILENAME
    xErrorSys("file(%s): ", __FILE__);
    #endif

    #ifdef ERROR_USE_LINE
    xErrorSys("line(%d): ", __LINE__);
    #endif

    xErrorSys("check faild: %s %s %s", ch1, cmp, ch2);
    abort();
}


#endif // __MACRO_XLOG_SYS_H__