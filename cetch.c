#include <libgen.h>
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

typedef struct logo {
    unsigned width, height;
    char *name;
    char **body;
} Logo;

#include "logos.h"

unsigned width, height;

void logo(char *name) {
    for (int i = 0; i < sizeof(Logos) / sizeof(Logo); i++) {
        if (!strcmp(Logos[i].name, name)) {
            width = Logos[i].width;
            height = Logos[i].height;
            for (int j = 0; j < sizeof(Logos[i].body) / sizeof(char*); j++) {
                printf(Logos[i].body[j]);
            }
        }
    }
};

int main(int argc, char *argv[])
{
#if defined __GNU_LIBRARY__
    char *lib = "glibc";
    char *libversion = STR(__GLIBC__) "." STR(__GLIBC_MINOR__);
#elif defined __UCLIBC__
    char *lib = "uclibc";
    char *libversion = STR(__UCLIBC_MAJOR__) "." STR(__UCLIBC_MINOR__);
#elif defined  __dietlibc__
    char *lib = "dietlibc";
    char *libversion = "unknown";
#elif defined __NEWLIB_STDIO_H
    char *lib = "newlib";
    char *libversion = "unknown";
#elif defined USR_KLIBC_STDIO_STDIONT_H
    char *lib = "klibc";
    char *libversion = "unknown";
#else
    char *lib = "muslc";
    char *libversion = "unknown";
#endif

    struct passwd *passwd = getpwuid(getuid());
    char *name = passwd->pw_name;
    if (!name) name = "unknown";    
    char *shellpath = passwd->pw_shell;
    if (!shellpath) shellpath = "unknown";
    char *shell = basename(shellpath);
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
    if (!osrelease) osrelease = "unknown";

#include "config.h"
    
    return 0;
}
