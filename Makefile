.POSIX:
.PHONY: install uninstall clean

PREFIX = /usr/local
CC = cc
BIN = humin
CFLAGS = -Wall
LDFLAGS =

all: $(BIN)

install: $(BIN)
	cp $(BIN) $(PREFIX)/bin/$(BIN)
	chmod +x $(PREFIX)/bin/$(BIN)

uninstall:
	rm -i $(PREFIX)/bin/$(BIN)

clean:
	-rm -i *.core $(BIN)
