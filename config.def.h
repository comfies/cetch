/**

Functions:
    logo(logotext, width, height)
        render the logotext on the left of the system info
    item(...)	        printf, but with extra formatting (should be used for all
        information)

Variables:
    name	username
    host	hostname
    shell	user's default shell
    shellpath	path to the user's default shell
    gecos	user GECOS field, usually the full name
    lib		system libc
    libversion  system libc version
    os		the system's uname
    osrelease	the system's uname release number
Linux only (and FreeBSD when libsysinfo is installed):
	procs	running processes
	freeram	free system memory in MiB
	totalram	total system memory in MiB
	uptime	system uptime

NOTE: You can remove the sysinfo dependency when building by using the
      following command:
        make nosysinfo=
**/

#include "logo/linux.h"

item(BOLD BLUE "%s" RESET "@" BOLD BLUE "%s", name, host)
item(BOLD GREEN "name" BOLD BLACK "%14s", gecos)
item(BOLD YELLOW "libc" BOLD BLACK "%14s", lib)
item(BOLD RED "os" BOLD BLACK "%16s", os)
item(BOLD MAGENTA "shell" BOLD BLACK "%13s", shell)

item(BOLD "colors    " BLACKBG "  " REDBG "  " GREENBG "  " YELLOWBG "  ")
item("          " BLUEBG "  " MAGENTABG "  " CYANBG "  " WHITEBG "  ")
//item(BOLD BLUE "memory" BOLD BLACK "%8.4g MiB", totalram)
//item(BOLD GREEN "uptime" BOLD BLACK "%12s", uptime)
//item(BOLD YELLOW "processes" BOLD BLACK "%9d", procs)
