.PHONY: sysinfo install

cetch: cetch.c config.h logos.h
	$(CC) cetch.c -o cetch

sysinfo: cetch.c config.h logos.h
	$(CC) cetch.c -o cetch -DSYSINFO -lsysinfo

install: cetch cetch.1
	install -Dm755 cetch /usr/bin/cetch
	install -Dm644 cetch.1 /usr/local/share/man/cetch.1

config.h:
	cp config.def.h config.h
