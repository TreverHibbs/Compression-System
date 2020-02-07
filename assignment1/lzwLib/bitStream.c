#include <stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <bitStream.h>

BitStream* openInputBitStream(int (*readFunc)(void* context), void* context) {
    /*
    This function will initialize a BitStream object.
    */
    BitStream* bitStream = malloc(sizeof(BitStream));

    bitStream->readFunc = readFunc;
    bitStream->context = context;
    bitStream->direction = 1; //1 indicates and input direction.
    bitStream->extraCount = 0; //irelavent for input bitStream.
    bitStream->extraBits = 0; //irelavent for input bitStream.
    bitStream->byteCount = 0;
    
    return (bitStream);
}

BitStream* openOutputBitStream(void (*writeFunc)(unsigned char c,void* context),void* context) {
    BitStream* bitStream = malloc(sizeof(BitStream));

    bitStream->writeFunc = writeFunc;
    bitStream->context = context;
    bitStream->direction = 0; //0 indicates and ouput direction.
    bitStream->extraCount = 0; //Amount of bits that are not yet written.
    bitStream->extraBits = 0; //The bits that have not been written.
    bitStream->byteCount = 0;
    
    return (bitStream);
}

void closeAndDeleteBitStream(BitStream* bs) {
    free(bs);
    return;
}

void outputBits(BitStream* bs, unsigned int nBits, unsigned int code) {
    /* write out the least significant nBits of code to fileStream. */
    char c1 = 0;
    char c2 = 0;
    unsigned int tmp = 0;
    unsigned short first_byte_mask = 65280;
    unsigned short second_byte_mask = 255;

    tmp = code & first_byte_mask;
    c1 = tmp >> 8;

    c2 = code & second_byte_mask;

    bs->writeFunc(c1, bs->context);
    bs->writeFunc(c2, bs->context);    

    return;
}

bool readInBits(BitStream* bs, unsigned int nBits, unsigned int* code) {
    int tmp = 0;
    *code = 0;
    //nBits is the number of bits that 
    //bs will attempt to read.

    //input bits will be stored in context->buffer.


    tmp = bs->readFunc(bs->context);

    if(tmp < 0){
        fprintf(stderr, "value of errno: %d\n", tmp);
        return(false);
    }else if(tmp == 0){
        printf("end of file\n");
        return(false);
    }

    *code = *code | tmp;
    *code = *code << 8;
    tmp = bs->readFunc(bs->context);
    *code = *code | tmp;

    return true;
}
