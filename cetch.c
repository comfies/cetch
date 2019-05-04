#include <limits.h>
#include <pwd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
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
    char *lib = "glibc";
    char *libversion = STR(__GLIBC__) "." STR(__GLIBC_MINOR__);
#else
#ifdef __UCLIBC__
    char *lib = "uclibc";
    char *libversion = STR(__UCLIBC_MAJOR__) "." STR(__UCLIBC_MINOR__);
#else
    char *lib = "unknown";
    char *libversion = "0.0";
#endif
#endif

    struct passwd *passwd = getpwuid(getuid());
    char *name = passwd->pw_name;
    if (!name) name = "unknown";    
    char *shell = passwd->pw_shell;
    if (!shell) shell = "unknown";
    char *gecos = passwd->pw_gecos;
    if (!gecos) gecos = "unknown";
    
    char host[HOST_NAME_MAX+1];
    gethostname(host, sizeof(host));
    if (!host) strcpy("unknown\0", host);
    
    struct utsname utsname;
    uname(&utsname);
    char *os = utsname.sysname;
    if (!os) os = "unknown";
    char *osrelease = utsname.release;
    if (!osrelease) osrelease = "0.0";
    
#include "config.h"
    
    return 0;
}
