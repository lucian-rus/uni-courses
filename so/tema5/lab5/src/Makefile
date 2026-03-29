#
# Makefile pentru lucrarea de laborator 5
#

CC = gcc
CFLAGS = -Wall -g -O
AR = ar

LIBLAB = liblab5.a

TEMPFILES = core core.* *.o temp.* *.out tempfile
PROGS =	ftw4 ftw4-2 unlink nls zap mycd cdpwd devrdev

OBJS = error.o pathalloc.o

all: ${PROGS}

ftw4: ftw4.c $(LIBLAB)
	$(CC) -o $@ $^

ftw4-2: ftw4-2.c $(LIBLAB)
	$(CC) -o $@ $^

unlink: unlink.c $(LIBLAB)
	$(CC) -o $@ $^

zap: zap.c $(LIBLAB)
	$(CC) -o $@ $^

nls: nls.c $(LIBLAB)
	$(CC) -o $@ $^

mycd: mycd.c $(LIBLAB)
	$(CC) -o $@ $^

cdpwd: cdpwd.c $(LIBLAB)
	$(CC) -o $@ $^

devrdev: devrdev.c $(LIBLAB)
	$(CC) -o $@ $^

lib: ${OBJS}
	${AR} rcs ${LIBLAB} $^

clean:
	rm -f ${PROGS} ${TEMPFILES} ${LIBLAB}
