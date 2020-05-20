/*
 * @Author: your name
 * @Date: 2020-05-21 00:13:25
 * @LastEditTime: 2020-05-21 01:12:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /awesome_log/include/user/alog.h
 */
#ifndef __MACRO_ALOG_H__
#define __MACRO_ALOG_H__

#include "user/aerror.h"

#define ag_check(left, right, fmt, ...) do { \
    if ((left) != (right)) {}
} while(0)

astatus ag_register(unsigned int timeout);
astatus ag_setlevel();
astatus ag_screen_level();
astatus uag_register(void);

astatus ag_error(const char* fmt, ...);
astatus ag_warn(const char* fmt, ...);
astatus ag_info(const char* fmt, ...);
astatus ag_debug(const char* fmt, ...);


#endif //__MACRO_ALOG_H__