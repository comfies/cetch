#include <libgen.h>
#include <limits.h>
#include <pwd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <unistd.h>

#if defined(LIBSYSINFO) || defined __GNU_LIBRARY__ && __linux__
#include <sys/sysinfo.h>
#endif

#define CSI       "\033["

// Foreground colors
#define BLACK   CSI "30m"
#define RED     CSI "31m"
#define GREEN   CSI "32m"
#define YELLOW  CSI "33m"
#define BLUE    CSI "34m"
#define MAGENTA CSI "35m"
#define CYAN    CSI "36m"
#define WHITE   CSI "37m"
// Background colors
#define BLACKBG   CSI "40m"
#define REDBG     CSI "41m"
#define GREENBG   CSI "42m"
#define YELLOWBG  CSI "43m"
#define BLUEBG    CSI "44m"
#define MAGENTABG CSI "45m"
#define CYANBG    CSI "46m"
#define WHITEBG   CSI "47m"

#define BOLD    CSI "1m"
#define RESET   CSI "0m"

#define STR(x) _STR(x)
#define _STR(x) #x

#define item(...) do { \
    printf("\033[%iC", logowidth); \
    printf(__VA_ARGS__); \
    printf(RESET"\033E"); \
    linenum++; \
} while (0);

// Define HOST_NAME_MAX on systems where it isnt available (freebsd, macos, etc)
#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX 255
#endif

int logowidth;
int logoheight;

void logo(char* text, int width, int height) {
    logoheight = height;
    logowidth = width+1;
    printf("%s\033[%iA", text, height);
}

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
#elif defined(unix) || defined(__unix__) || defined(__unix)
    char *lib = "libc";
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
    
    struct utsname utsname;
    uname(&utsname);
    char *os = utsname.sysname;
    if (!os) os = "unknown";
    char *osrelease = utsname.release;
    if (!osrelease) osrelease = "unknown";

#if defined(LIBSYSINFO) || defined __GNU_LIBRARY__ && __linux__
#define DIVISOR 1048576
	struct sysinfo info;
	sysinfo(&info);
	long uptime_s = info.uptime;
	char uptime[9];
	snprintf(uptime, 9, "%.2ld:%.2ld:%.2ld", uptime_s/3600,
		uptime_s%3600/60, uptime_s%60);
	unsigned short procs = info.procs;
	unsigned long freeram = info.freeram/DIVISOR;
	unsigned long totalram = info.totalram/DIVISOR;
#endif
    int linenum = 0;
#include "config.h"
//    if (logowidth)
//        printf("\033[%iB", logoheight - linenum);
    return 0;
}
