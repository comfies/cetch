/**
Functions you can use to get information:

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

item(BOLD BLUE "%s" RESET "@" BOLD BLUE "%s", name, host)
item(BOLD GREEN "name" BOLD BLACK "%11s", gecos)
item(BOLD GREEN "libc" BOLD BLACK "%11s", lib)
item(BOLD GREEN "os" BOLD BLACK "%13s", os)
item(BOLD GREEN "shell" BOLD BLACK "%10s", shell)