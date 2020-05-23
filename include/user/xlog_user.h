#ifndef __MACRO_XLOG_USER_H__
#define __MACRO_XLOG_USER_H__

#include "user/xerror.h"
#include "user/xlevel.h"
#include "user/xlog_sys.h"

#ifdef use_xLog

    #include <stdlib.h>
    #include <sys/types.h>
    #include <unistd.h>

    pid_t g_pid = -1;
    pid_t g_ppid = -1;

    #define xCheckEQ(left, right, fmt, ...) do { \
        if ((left) != (right)) {
            xErrorSys("check failed, file(%s)-line(%d): %s != %s", __FILE__, __LINE__, #left, #right);
            abort();
        }
    } while(0)

    #define xCheckGT(left, right, fmt, ...) do { \
        if ((left) <= (right)) {
            xErrorSys("check failed, file(%s)-line(%d): %s <= %s", __FILE__, __LINE__, #left, #right);
            abort();
        }
    } while(0)

    #define xCheckGE(left, right, fmt, ...) do { \
        if ((left) < (right)) {
            xErrorSys("check failed, file(%s)-line(%d): %s < %s", __FILE__, __LINE__, #left, #right);
            abort();
        }
    } while(0)

    #define xCheckLT(left, right, fmt, ...) do { \
        if ((left) >= (right)) {
            xErrorSys("check failed, file(%s)-line(%d): %s >= %s", __FILE__, __LINE__, #left, #right);
            abort();
        }
    } while(0)

    #define xCheckLE(left, right, fmt, ...) do { \
        if ((left) > (right)) {
            xErrorSys("check failed, file(%s)-line(%d): %s > %s", __FILE__, __LINE__, #left, #right);
            abort();
        }
    } while(0)

    #define xError(const char* fmt, ...) do { \
    } while(0)

    #define xWarn(const char* fmt, ...) do { \
    } while(0)

    #define xInfo(const char* fmt, ...) do { \
    } while(0)

    #define xDebug(const char* fmt, ...) do { \
    } while(0)

    inline xStatus xRegister(moudle, try_times, timeout)
    {
        g_pid = getpid();
        g_ppid = getppid();
        xStatus status = xRegisterSys(g_ppid, g_pid, #moudle, try_times, timeout);
        if (status != xSuccess) {
            dfxError("register error, process name(%s), pid(%d), ppid(%d), status(%d)",\
                __progname, g_pid, g_ppid, status);  //start log print
            return status;
        }

        xInfo(xlog, "register success, process name(%s), pid(%d), ppid(%d), status(%d)",\
                __progname, g_pid, g_ppid, status);
        return xSuccess;
    }

    inline xStatus xUnRegister(void)
    {                                                    \
        xStatus status = xUnRegisterSys(g_ppid, g_pid);
        if (status != xSuccess) {
            dfxError("unregister error, process name(%s), pid(%d), ppid(%d), status(%d)",\
                __progname, g_pid, g_ppid, status);
            return status;
        }

        dfxInfo(xlog, "unregister success, process name(%s), pid(%d), ppid(%d), status(%d)",\
                __progname, g_pid, g_ppid, status);
        return xSuccess;
    } while(0)

    inline xStatus xSetLevel(const xLevelInfo* info) do { \
    } while(0)

    

#else
    #define xRegister(timeout) NULL
    #define xUnRegister() NULL
    #define xSetLevel(level) NULL
    #define xError(fmt, ...) NULL
    #define xWarn(fmt, ...) NULL
    #define xInfo(fmt, ...) NULL
    #define xDebug(fmt, ...) NULL

    #define xCheckEQ(left, right, fmt, ...) NULL
    #define xCheckGT(left, right, fmt, ...) NULL
    #define xCheckGE(left, right, fmt, ...) NULL
    #define xCheckLT(left, right, fmt, ...) NULL
    #define xCheckLE(left, right, fmt, ...) NULL

#endif // use_xLog



#endif //__MACRO_XLOG_USER_H__