<h2 align="center">cetch</h2>
<h6 align="center">a fetch tool written in C, because God has been dead for
a very long time</h6>

### Usage

cetch skips out on any bloat: there's no options, parameters, runtime
configs. the only thing to do when using cetch is to call it, it's that
simple.

### Configuration

configuration is done through the `config.h` file in the repository.
`config.h` is generated from the default `config.def.h`. the
only configuration setting is the `item()` command. It's a macro that wraps
around printf, appending a newline to the end and sending an SGR reset to
prevent color effects from bleeding over to the next line.

color effects are done through a set of standard ANSI SGR colors:
`BLACK`, `RED`, `GREEN`, `YELLOW`, `BLUE`, `MAGENTA`, `CYAN`, `WHITE`,
`BOLD`, `RESET`.

Example configuration:
```C
/**
Functions you can use to get information:

    hostname	system hostname
    username	user's name
    userinfo    user GECOS field
    osname	operating system name
    osversion	operating system version
    shellname	shell path
    
**/

item(BOLD BLUE "%s" RESET "@" BOLD BLUE "%s", username, hostname)
item(BOLD GREEN "NM" BOLD BLACK "%12s", userinfo)
item(BOLD GREEN "OS" BOLD BLACK "%12s", osname)
item(BOLD GREEN "SH" BOLD BLACK "%12s", shellname)
```