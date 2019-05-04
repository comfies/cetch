/**

Functions:
    logo(name)	render the logo with name, <name> (should only be called once, and before item(1))
    item(...)	printf, but with extra formatting (should be used for all information)

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
    
**/

logo(os);

item(BOLD BLUE "%s" RESET "@" BOLD BLUE "%s", name, host)
item(BOLD GREEN "name" BOLD BLACK "%14s", gecos)
item(BOLD YELLOW "libc" BOLD BLACK "%14s", lib)
item(BOLD RED "os" BOLD BLACK "%16s", os)
item(BOLD MAGENTA "shell" BOLD BLACK "%13s", shell)
