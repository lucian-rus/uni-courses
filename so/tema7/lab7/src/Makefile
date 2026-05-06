#
# Makefile pentru lucrarea de laborator 7
#

CC = gcc
CFLAGS = -Wall -g -O
AR = ar

TEMPFILES = core core.* *.o *.out
PROGS =	hello prodcons prodcons2 semprodcons

all: ${PROGS}

hello: hello.c
	$(CC) -o $@ $^

prodcons: prodcons.c
	$(CC) -o $@ $^

prodcons2: prodcons2.c
	$(CC) -o $@ $^

semprodcons: semprodcons.c
	$(CC) -o $@ $^

clean:
	rm -f ${PROGS} ${TEMPFILES}
