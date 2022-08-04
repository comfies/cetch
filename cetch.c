#include <libgen.h>
#include <limits.h>
#include <pwd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <unistd.h>

#ifdef SYSINFO
#endif

#ifndef HOST_NAME_MAX
    #define HOST_NAME_MAX 255
#endif

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BLACK_BACKGROUND "\033[40m"
#define RED_BACKGROUND "\033[41m"
#define GREEN_BACKGROUND "\033[42m"
#define YELLOW_BACKGROUND "\033[43m"
#define BLUE_BACKGROUND "\033[44m"
#define MAGENTA_BACKGROUND "\033[45m"
#define CYAN_BACKGROUND "\033[46m"
#define WHITE_BACKGROUND "\033[47m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

#define STR(x) _STR(x)
#define _STR(x) #x

int info_offset = 0;

#define LOGO(L) do { \
    info_offset = logoSET[L].width; \
    printf("%s\033[%iA", logoSET[L].body, logoSET[L].height); \
} while (0);

#define ITEM(...) do { \
    printf("\033[%iC", info_offset); \
    printf(__VA_ARGS__); \
    printf(RESET"\033E"); \
} while (0);

char host[HOST_NAME_MAX+1], *name, *shellpath, *shell, *gecos, *os, *osrelease;

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
#elif defined(unix) || defined(__unix__) || defined(__unix)
    char *lib = "libc";
    char *libversion = "unknown";
#else
    char *lib = "muslc";
    char *libversion = "unknown";
#endif

#include "logos.h"

void get_passwd()
{
    struct passwd *passwd = getpwuid(getuid());

    if (!((name = passwd->pw_name))) name = "unknown";
    if (!((shellpath = passwd->pw_shell))) shellpath = "unknown";
    if (!((gecos = passwd->pw_gecos))) gecos = "unknown";

    shell = basename(shellpath);
}

void get_utsname()
{
    struct utsname utsname;
    uname(&utsname);

    if (!((os = utsname.sysname))) os = "unknown";
    if (!((osrelease = utsname.release))) os = "unknown";
}

#ifdef SYSINFO
#include <sys/sysinfo.h>
char uptime[9];
unsigned int freeram, totalram, procs;
void get_sysinfo()
{
    int divisor = 1048576;
    struct sysinfo info;
    sysinfo(&info);
    long uptime_s = info.uptime;
    char uptime[9];
    snprintf(uptime, 9, "%.2ld:%.2ld:%.2ld", uptime_s / 3600, uptime_s % 3600 / 60, uptime_s % 60);
    procs = info.procs;
    freeram = info.freeram / divisor;
    totalram = info.totalram / divisor;
}
#endif

int main(int argc, char *argv[])
{
    get_passwd();
    gethostname(host, sizeof(host));
    get_utsname();
#ifdef SYSINFO
    get_sysinfo();
#endif

    #include "config.h"
    return 0;
}
