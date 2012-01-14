MAJOR=1
MINOR=1
CC=gcc
CFLAGS=-g -O2 -Wall -I. -DVERSION=\"$(MAJOR).$(MINOR)\"
OBJS=\
	cbtcommon/debug.o\
	cbtcommon/hash.o\
	cbtcommon/text_util.o\
	cvsps.o

cvsps: $(OBJS)
	gcc -o cvsps $(OBJS)

install:
	install cvsps /usr/local/bin

clean:
	rm -f cvsps *.o cbtcommon/*.o core

.PHONY: install clean
