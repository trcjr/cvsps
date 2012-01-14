MAJOR=1
MINOR=3.1
CC?=gcc
CFLAGS?=-g -O2 -Wall 
CFLAGS+=-I. -DVERSION=\"$(MAJOR).$(MINOR)\"
prefix?=/usr/local
OBJS=\
	cbtcommon/debug.o\
	cbtcommon/hash.o\
	cbtcommon/text_util.o\
	cvsps.o

cvsps: $(OBJS)
	$(CC) -o cvsps $(OBJS)

install:
	[ -d $(prefix)/bin ] || mkdir -p $(prefix)/bin
	[ -d $(prefix)/man/man1 ] || mkdir -p $(prefix)/man/man1
	install cvsps $(prefix)/bin
	install -m 644 cvsps.1 $(prefix)/man/man1

clean:
	rm -f cvsps *.o cbtcommon/*.o core

.PHONY: install clean