#
# Makefile pentru lucrarea de laborator 6
#

CC = gcc
CFLAGS = -Wall -g -O
AR = ar

LIBLAB = liblab6.a

TEMPFILES = core core.* *.o *.out
PROGS =	fork1 wait1 fork2 tellwait1 tellwait2 echoall exec1

OBJS = error.o prexit.o tellwait.o

all: ${PROGS}

fork1: fork1.c $(LIBLAB)
	$(CC) -o $@ $^

wait1: wait1.c $(LIBLAB)
	$(CC) -o $@ $^

fork2: fork2.c $(LIBLAB)
	$(CC) -o $@ $^

tellwait1: tellwait1.c $(LIBLAB)
	$(CC) -o $@ $^

tellwait2: tellwait2.c $(LIBLAB)
	$(CC) -o $@ $^

echoall: echoall.c $(LIBLAB)
	$(CC) -o $@ $^

exec1: exec1.c $(LIBLAB)
	$(CC) -o $@ $^

lib: ${OBJS}
	${AR} rcs ${LIBLAB} $^

clean:
	rm -f ${PROGS} ${TEMPFILES} ${LIBLAB}
