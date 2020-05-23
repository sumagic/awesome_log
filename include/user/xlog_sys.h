#ifndef __MACRO_XLOG_SYS_H__
#define __MACRO_XLOG_SYS_H__

#include <stdlib.h>

#include <sys/types.h>

#include "user/xerror.h"
#include "user/xlevel.h"

void xErrorSys(const char* fmt, ...);

xStatus xRegisterSys(const pid_t ppid, const pid_t pid, const char* moudle, uint trytimes, uint timeout);
xStatus xUnRegisterSys(const pid_t ppid, const pid_t pid);



#endif // __MACRO_XLOG_SYS_H__