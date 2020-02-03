CC=gcc
LZWLIB=../../lzwLib/
INCLUDE=../../lzwLib/include/
OFLAGS=-c -Wall -pedantic -std=c99 -g
CFLAGS=-Wall -pedantic -std=c99 -g -o test.out
CFILES=./test_main.c
OFILES=./strcmp.o ./sequence.o
UTILCFILES=$(LZWLIB)strcmp.c

UTILDIR=../../lzwLib
UTILLIB=$(UTILDIR)liblzw.a

test.out: $(OFILES) $(INCLUDE)strcmp.h $(INCLUDE)sequence.h $(CFILES) 
	$(CC) $(CFLAGS) $(CFILES) $(OFILES) -I$(INCLUDE)

strcmp.o: $(UTILCFILES) $(INCLUDE)strcmp.h
	gcc $(OFLAGS) $(UTILCFILES) -I$(INCLUDE)

sequence.o: $(LZWLIB)sequence.c $(INCLUDE)sequence.h
	gcc $(OFLAGS) $(LZWLIB)sequence.c -I$(INCLUDE)

clean:
	rm -f test.out strcmp.o sequence.o