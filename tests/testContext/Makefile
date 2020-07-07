
CC=gcc
LZWLIB=../../lzwLib/
INCLUDE=../../lzwLib/include/
OFLAGS=-c -Wall -pedantic -std=c99 -g
CFLAGS=-Wall -pedantic -std=c99 -g -o test.out
CFILES=./context_test.c
OFILES=$(LZWLIB)strcmp.o ./context.o
UTILCFILES=$(LZWLIB)strcmp.c

UTILDIR=../../lzwLib
UTILLIB=$(UTILDIR)liblzw.a

test.out: $(OFILES) $(INCLUDE)strcmp.h $(INCLUDE)context.h $(CFILES) 
	$(CC) $(CFLAGS) $(CFILES) $(OFILES) -I$(INCLUDE)

context.o: $(LZWLIB)context.c $(INCLUDE)context.h
	gcc $(OFLAGS) $(LZWLIB)context.c -I$(INCLUDE)

clean:
	rm -f test.out context.o