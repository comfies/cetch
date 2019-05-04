/**
Functions you can use to get information:

    name	username
    host	hostname
    shell	user's default shell
    gecos	user GECOS field, usually the full name
    lib		system libc
    libversion  system libc version
    os		the system's uname
    osrelease	the system's uname release number
    
**/

item(BOLD BLUE "%s" RESET "@" BOLD BLUE "%s", name, host)
item(BOLD GREEN "NM" BOLD BLACK "%12s", gecos)
item(BOLD GREEN "LC" BOLD BLACK "%12s", lib)
item(BOLD GREEN "OS" BOLD BLACK "%12s", os)
item(BOLD GREEN "SH" BOLD BLACK "%12s", shell)