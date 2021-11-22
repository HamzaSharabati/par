CC=gcc
CFLAGS=-Wall -ansi -pedantic
par: par.c
	$(CC) -o par par.c
