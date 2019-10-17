DESTDIR= /usr
nosysinfo ?= -I/usr/local/include -DLIBSYSINFO -lm -lsysinfo -L/usr/local/lib

cetch: cetch.c config.h
	$(CC) cetch.c -o cetch $(nosysinfo)

install: cetch cetch.1
	install -Dm755 cetch $(DESTDIR)/bin/cetch
	install -Dm644 cetch.1 $(DESTDIR)/local/share/man/cetch.1
	
config.h:
	cp config.def.h config.h
