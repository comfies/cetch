/**

NOTE: Using logos along with your information is not currently supported, there
was an attempt to implement it in earlier versions of cetch but they were
pretty terrible... but if you want logo support, contributions are always
welcome ^-^.

Functions:
    logo(name)	render the logo with name, <name> (should only be called once,
        and before item(1)) [DEPRECATED]
    item(...)	printf, but with extra formatting (should be used for all
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
Linux only:
	procs	running processes
	freeram	free system memory in MiB
	totalram	total system memory in MiB
	uptime	system uptime
**/

// logo(os); [DEPRECATED]

item(BOLD BLUE "%s" RESET "@" BOLD BLUE "%s", name, host)
item(BOLD GREEN "name" BOLD BLACK "%14s", gecos)
item(BOLD YELLOW "libc" BOLD BLACK "%14s", lib)
item(BOLD RED "os" BOLD BLACK "%16s", os)
item(BOLD MAGENTA "shell" BOLD BLACK "%13s", shell)
//item(BOLD BLUE "memory" BOLD BLACK "%8.4g MiB", totalram)
//item(BOLD GREEN "uptime" BOLD BLACK "%12s", uptime)
//item(BOLD YELLOW "processes" BOLD BLACK "%9d", procs)

