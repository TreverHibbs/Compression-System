CC=gcc
LZWLIB=../../lzwLib/
INCLUDE=../../lzwLib/include/
OFLAGS=-c -Wall -pedantic -std=c99 -g
CFLAGS=-Wall -pedantic -std=c99 -g -o test.out
CFILES=./test_main.c
OFILES=./strcmp.o ./readFunc.o $(LZWLIB)bitStream.o
UTILCFILES=$(LZWLIB)strcmp.c

UTILDIR=../../lzwLib
UTILLIB=$(UTILDIR)liblzw.a

test.out: $(OFILES) $(INCLUDE)strcmp.h $(INCLUDE)readFunc.h $(INCLUDE)bitStream.h $(CFILES) 
	$(CC) $(CFLAGS) $(CFILES) $(OFILES) -I$(INCLUDE)

strcmp.o: $(UTILCFILES) $(INCLUDE)strcmp.h
	gcc $(OFLAGS) $(UTILCFILES) -I$(INCLUDE)

readFunc.o: $(LZWLIB)readFunc.c $(INCLUDE)bitStream.h $(INCLUDE)readFunc.h
	gcc $(OFLAGS) $(LZWLIB)readFunc.c -I$(INCLUDE)

clean:
	rm -f test.out strcmp.o readFunc.o