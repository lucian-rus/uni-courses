#
# Makefile pentru lucrarea de laborator 8
#

CC = gcc
CFLAGS = -Wall -g -O
AR = ar

LIBLAB = liblab8.a

TEMPFILES = core core.* *.o *.out fifo2
PROGS =	pipe1 pipe2 tellwait2 popen2 myuclc popen1 add2 pipe4 fifo

OBJS = error.o tellwait.o

all: ${PROGS}

pipe1: pipe1.c $(LIBLAB)
	$(CC) -o $@ $^

pipe2: pipe2.c $(LIBLAB)
	$(CC) -o $@ $^

tellwait2: tellwait2.c $(LIBLAB)
	$(CC) -o $@ $^

popen2: popen2.c $(LIBLAB)
	$(CC) -o $@ $^

myuclc: myuclc.c $(LIBLAB)
	$(CC) -o $@ $^

popen1: popen1.c $(LIBLAB)
	$(CC) -o $@ $^

add2: add2.c $(LIBLAB)
	$(CC) -o $@ $^

pipe4: pipe4.c $(LIBLAB)
	$(CC) -o $@ $^

fifo: fifo.c $(LIBLAB)
	$(CC) -o $@ $^

lib: ${OBJS}
	${AR} rcs ${LIBLAB} $^

clean:
	rm -f ${PROGS} ${TEMPFILES} ${LIBLAB}
