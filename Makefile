cetch: cetch.c config.h
	$(CC) cetch.c -o cetch

install: cetch
	install -Dm755 cetch /usr/bin/cetch
	
config.h:
	cp config.def.h config.h
