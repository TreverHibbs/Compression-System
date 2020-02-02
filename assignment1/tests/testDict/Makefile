
CC=gcc
INCLUDE=../include/
LZWINCLUDE=../../lzwLib/include/
LZWOFILES=../../lzwLib/
CFLAGS=-Wall -pedantic -std=c99 -g
CFILES=./testdict.c

CUNIT=/usr/share/doc/libcunit1

test.out: $(CFILES) $(INCLUDE)header.h $(LZWINCLUDE)dict.h $(LZWOFILES)dict.o $(CUNIT)/libcunit.a
	$(CC) $(CFLAGS) $(CFILES) -I$(INCLUDE) -I$(LZWINCLUDE) $(LZWOFILES)dict.o -L$(CUNIT) -lcunit -o test.out 
