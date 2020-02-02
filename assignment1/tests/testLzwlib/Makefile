
CC=gcc
LZWLIB=../../lzwLib/
INCLUDE=../../lzwLib/include/
CFLAGS= -Wall -pedantic -std=c99 -g
CFILES=./main.c

UTILDIR=../../lzwLib
UTILFLAG=-llzw
UTILLIB=$(UTILDIR)liblzw.a

test.out: $(LZWLIB)liblzw.a $(INCLUDE)lzw.h $(CFILES)
	$(CC) $(CFLAGS) -o test.out $(CFILES) -L$(UTILDIR) $(UTILFLAG)  -I$(INCLUDE)

clean:
	rm -f test.out
