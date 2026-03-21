#
# Makefile pentru lucrarea de laborator 3
#

CC = gcc
CFLAGS = -Wall -g -O
AR = ar

LIBLAB = liblab3.a

TEMPFILES = core core.* *.o temp.* *.out typescript*
PROGS =	seek seek2 hole hole2 mycat mycat2 fileflags

OBJS = error.o

all: ${PROGS}

seek: seek.c $(LIBLAB)
	$(CC) -o $@ $?

seek2: seek2.c $(LIBLAB)
	$(CC) -o $@ $?

hole: hole.c $(LIBLAB)
	$(CC) -o $@ $?

hole2: hole2.c $(LIBLAB)
	$(CC) -o $@ $?

mycat: mycat.c $(LIBLAB)
	$(CC) -o $@ $?

mycat2: mycat2.c $(LIBLAB)
	$(CC) -o $@ $?

fileflags: fileflags.c $(LIBLAB)
	$(CC) -o $@ $?

lib: ${OBJS}
	${AR} rcs ${LIBLAB} $<

clean:
	rm -f ${PROGS} ${TEMPFILES} ${LIBLAB} file.hole
