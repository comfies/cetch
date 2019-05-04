#include <limits.h>
#include <pwd.h>
#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <unistd.h>

#define CSI "\033["
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

#define item(...) do { \
    printf(__VA_ARGS__); \
    printf(RESET"\n"); \
} while (0);

int main(int argc, char *argv[])
{
    struct passwd *passwd = getpwuid(getuid());
    char *username = passwd->pw_name;
    char *shellname = passwd->pw_shell;
    char *userinfo = passwd->pw_gecos;
    
    char hostname[HOST_NAME_MAX + 1];
    gethostname(hostname, sizeof(hostname));
    
    struct utsname utsname;
    uname(&utsname);
    char *osname = utsname.sysname;
    char *osversion = utsname.release;
    
    #include "config.h"
    
    return 0;
}
