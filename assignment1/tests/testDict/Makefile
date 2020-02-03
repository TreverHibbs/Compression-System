
CC=gcc
LZWLIB=../../lzwLib/
INCLUDE=../../lzwLib/include/
OFLAGS=-c -Wall -pedantic -std=c99 -g
CFLAGS=-Wall -pedantic -std=c99 -g -o test.out
CFILES=./testdict.c
OFILES=./dict.o
UTILCFILES=$(LZWLIB)strcmp.c

CUNIT=/usr/share/doc/libcunit1

test.out: $(OFILES) $(INCLUDE)dict.h $(CFILES) 
	$(CC) $(CFLAGS) $(CFILES) $(OFILES) -I$(INCLUDE)

dict.o: $(LZWLIB)dict.c $(INCLUDE)dict.h
	$(CC) $(OFLAGS) $(LZWLIB)dict.c -I$(INCLUDE)