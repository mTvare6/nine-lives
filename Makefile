include config.mk

all:
	$(CC) main.c -o nine-lives


install:
	@cp nine-lives $(DESTDIR)$(PREFIX)/bin/nine-lives
	@chmod 755 $(DESTDIR)$(PREFIX)/bin/nine-lives


uninstall:
	@rm -f $(DESTDIR)$(PREFIX)/bin/nine-lives

