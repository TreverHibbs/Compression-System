
CC=gcc
LZWLIB=../../lzwLib/
INCLUDE=../../lzwLib/include/
OFLAGS=-c -Wall -pedantic -std=c99 -g
CFLAGS=-Wall -pedantic -std=c99 -g -o test.out
CFILES=./main.c
OFILES=./strcmp.o
UTILCFILES=$(LZWLIB)strcmp.c

UTILDIR=../../lzwLib
UTILLIB=$(UTILDIR)liblzw.a

test.out: $(OFILES) $(INCLUDE)strcmp.h $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) $(OFILES) -I$(INCLUDE)

strcmp.o: $(UTILCFILES) $(INCLUDE)strcmp.h
	gcc $(OFLAGS) $(UTILCFILES) -I$(INCLUDE)

clean:
	rm -f test.out strcmp.o
