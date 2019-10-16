DESTDIR=

cetch: cetch.c config.h
	$(CC) cetch.c -o cetch

install: cetch cetch.1
	install -Dm755 cetch $(DESTDIR)/usr/bin/cetch
	install -Dm644 cetch.1 $(DESTDIR)/usr/local/share/man/cetch.1
	
config.h:
	cp config.def.h config.h
