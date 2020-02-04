
CC=gcc
LZWLIB=../../lzwLib/
INCLUDE=../../lzwLib/include/
OFLAGS=-c -Wall -pedantic -std=c99 -g
CFLAGS=-Wall -pedantic -std=c99 -g -o test.out
CFILES=./test_dict.c
OFILES=./dict.o $(LZWLIB)sequence.o $(LZWLIB)strcmp.o
UTILCFILES=$(LZWLIB)strcmp.c

test.out: $(OFILES) $(INCLUDE)strcmp.h $(INCLUDE)dict.h $(INCLUDE)sequence.h $(CFILES) 
	$(CC) $(CFLAGS) $(CFILES) $(OFILES) -I$(INCLUDE)

dict.o: $(LZWLIB)dict.c $(INCLUDE)dict.h
	$(CC) $(OFLAGS) $(LZWLIB)dict.c -I$(INCLUDE)

clean: 
	rm -f dict.o test.out
