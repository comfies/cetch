#include <limits.h>
#include <pwd.h>
#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <unistd.h>

#define CSI         "\033["
#define BLACK   CSI "30m"
#define RED     CSI "31m"
#define GREEN   CSI "32m"
#define YELLOW  CSI "33m"
#define BLUE    CSI "34m"
#define MAGENTA CSI "35m"
#define CYAN    CSI "36m"
#define WHITE   CSI "37m"
#define BOLD    CSI "1m"
#define RESET   CSI "0m"

#define STR(x) _STR(x)
#define _STR(x) #x

#define item(...) do { \
    printf(__VA_ARGS__); \
    printf(RESET"\n"); \
} while (0);

int main(int argc, char *argv[])
{
#ifdef __GNU_LIBRARY__
    const char *libc = "glibc";
    const char *libcversion = STR(__GLIBC__) "." STR(__GLIBC_MINOR__);
#else
#ifdef __UCLIBC__
    const char *libc = "uclibc";
    const char *libcversion = STR(__UCLIBC_MAJOR__) "." STR(__UCLIBC_MINOR__);
#else
    const char *libc = "unknown";
    const char *libcversion = "0.0";
#endif
#endif
    struct passwd *passwd = getpwuid(getuid());
    const char *username = passwd->pw_name;
    const char *shellname = passwd->pw_shell;
    const char *userinfo = passwd->pw_gecos;
    
    char hostname[HOST_NAME_MAX + 1];
    gethostname(hostname, sizeof(hostname));
    
    struct utsname utsname;
    uname(&utsname);
    const char *osname = utsname.sysname;
    const char *osversion = utsname.release;
    
    #include "config.h"
    
    return 0;
}
