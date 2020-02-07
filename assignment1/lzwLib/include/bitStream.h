#ifndef BITSTREAM_H     
#define BITSTREAM_H     
#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_CODE_BITS   24
#define CHAR_BITS       8

/* BitStream: module to enable variable width integers/codes to be read */
/* or written from/to an open stdio FILE* */

/* module only supports codes with 8 to 24 bit width */

typedef struct context_s {
    FILE *input;
    FILE *output;
    int fd;
    char* buffer;
    int attempt;
} Context;

typedef struct _bitStream {
    int (*readFunc)(Context* context);
    void (*writeFunc)(unsigned char c, Context* context);
    Context* context;
    int direction;              // input or output
    unsigned int extraCount;    // number of bits held in extraBits
    unsigned int extraBits;     // bits buffer
    unsigned int byteCount;     // # of bytes read/written from/to fd
} BitStream;

Context* initContext(int attempt, char* path);

int readFunc(Context* context);

void writeFunc(unsigned char c, Context* context);

void freeContext(Context* context);

BitStream* openInputBitStream(int (*readFunc)(Context* context), Context* context);

BitStream* openOutputBitStream(void (*writeFunc)(unsigned char c, Context* context), Context* context);

/* free bs, flush any remaining bits if its an output direction */
void closeAndDeleteBitStream(BitStream* bs);

/* Write any remaining bits to to fileStream */
void flushOutBits(BitStream* bs);

/* Write out the least significant nBits of code to fileStream */
void outputBits(BitStream* bs, unsigned int nBits, unsigned int code);

/* Read an nBit code from fileStream, if EOF, return false, 
   else write the code to the pointer argument and return true. */
bool readInBits(BitStream* bs, unsigned int nBits, unsigned int* code);

#endif
