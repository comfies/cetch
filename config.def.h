/**
Functions you can use to get information:

    hostname	system hostname
    username	user's name
    libc	systems c library
    libcversion version of system libc
    userinfo    user GECOS field
    osname	operating system name
    osversion	operating system version
    shellname	shell path
    
**/

item(BOLD BLUE "%s" RESET "@" BOLD BLUE "%s", username, hostname)
item(BOLD GREEN "NM" BOLD BLACK "%12s", userinfo)
item(BOLD GREEN "LC" BOLD BLACK "%12s", libc)
item(BOLD GREEN "OS" BOLD BLACK "%12s", osname)
item(BOLD GREEN "SH" BOLD BLACK "%12s", shellname)