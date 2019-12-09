<h2 align="center">cetch(1)</h2>
<img align="right" src="scrot.png" alt="very out of date screenshot">

`cetch` is an (esoteric) application for UNIX systems. It emulates the
functionality of the popular "fetch" type of tools with suckless-esque
source-based configuration as opposed to itself being a script or being
configurable through a script. Originally written soley to piss of xent,
it has since been used as a farm for Hacktoberfest pull requests and a
test-bed for stupid ideas to use in C code.

I know you'll love using it, because I hated every minute of writing it,
and yes, so did woosh. If you'd like to contribute, go ahead, I will
pull any changes as long as they aren't profoundly stupid. Heck, I won't
even test them first. Also if someone wants to refactor the code -- *please*.

As previously stated, all configuration is done through a `config.h`,
which should (and will) be copied from `config.def.h`. Almost every option
*should* work, though some are Linux:tm: only. (These should be
automagically disabled if running on anything else, but hey, it probably
won't). `cetch` also supports logos for Debian, FreeBSD, Linux (Tux), NixOS,
and Void Linux: colors and all.

**If you run `make` and get some sort of error with sysinfo,
run `nosysinfo= make` instead**
