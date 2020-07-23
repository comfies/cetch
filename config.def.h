/**

Functions:
    logo(logotext, width, height)
        render the logotext on the left of the system info
    ITEM(...)	        printf, but with extra formatting (should be used for all
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
**/

LOGO(tux)

ITEM("")
ITEM(BOLD BLUE "%s" RESET "@" BLUE "%s", name, host)
ITEM(BOLD GREEN "NAME" BOLD BLACK "%14s", gecos)
ITEM(BOLD YELLOW "LIBC" BOLD BLACK "%14s", lib)
ITEM(BOLD RED "OS" BOLD BLACK "%16s", os)
ITEM(BOLD MAGENTA "SH" BOLD BLACK "%13s", shell)

#ifdef SYSINFO
ITEM(BOLD BLUE "memory" BOLD BLACK "%8lu MiB", totalram)
ITEM(BOLD GREEN "uptime" BOLD BLACK "%12s", uptime)
ITEM(BOLD YELLOW "processes" BOLD BLACK "%9d", procs)
#endif

ITEM(BOLD "colors    " BLACK_BACKGROUND "  " RED_BACKGROUND "  " GREEN_BACKGROUND "  " YELLOW_BACKGROUND "  ")
ITEM("          " BLUE_BACKGROUND "  " MAGENTA_BACKGROUND "  " CYAN_BACKGROUND "  " WHITE_BACKGROUND "  ")
