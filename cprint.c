#include "cprint.h"
#include <stdio.h>
#include <stdarg.h>
#include <windows.h>

#define CPRINT_OUT stderr 

int
cprint_getatt(void) {
        CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
 
        int ret = GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ),&bufferInfo);        
        
        if (ret == 0) {
                return -1;
        }
        return bufferInfo.wAttributes;
}

int
cprint_setatt(int att) {
        return 1 ^ SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), att);
}

int
cprint_print(const char *fmt, ...) {
        int ret;
        va_list arg;

        va_start(arg,fmt);
        ret = vfprintf(CPRINT_OUT, fmt, arg);
        va_end(arg);

        return ret;
}


