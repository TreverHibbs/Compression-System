
CC=gcc
LZWLIB=../../lzwLib/
INCLUDE=../../lzwLib/include/
CFLAGS=-c -Wall -pedantic -std=c99 -g
CFILES=./main.c
UTILCFILES=$(LZWLIB)strcmp.c

UTILDIR=../../lzwLib
UTILLIB=$(UTILDIR)liblzw.a

test.out: strcmp.o $(INCLUDE)strcmp.h $(CFILES)
	$(CC) -Wall -pedantic -std=c99 -g -o test.out $(CFILES) strcmp.o -I$(INCLUDE)

strcmp.o: $(UTILCFILES) $(INCLUDE)strcmp.h
	gcc $(CFLAGS) $(UTILCFILES) -I$(INCLUDE)

clean:
	rm -f test.out strcmp.o
