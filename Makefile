include config.mk
BIN=nine-lives


all:
	$(CC) main.c -o $(BIN)


install:
	@cp $(BIN) $(DESTDIR)$(PREFIX)/bin/$(BIN)
	@chmod 755 $(DESTDIR)$(PREFIX)/bin/$(BIN)


uninstall:
	@rm -f $(DESTDIR)$(PREFIX)/bin/$(BIN)

