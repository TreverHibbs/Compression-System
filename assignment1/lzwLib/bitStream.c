#include <stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
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

BitStream* openOutputBitStream(void (*writeFunc)(unsigned char c,Context* context),Context* context) {
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
    freeContext(bs->context);
    free(bs);
    return;
}

void outputBits(BitStream* bs, unsigned int nBits, unsigned int code) {
    /* write out the least significant nBits of code to fileStream. */    
}

bool readInBits(BitStream* bs, unsigned int nBits, unsigned int* code) {
    int actual = 0;
    //nBits is the number of bits that 
    //bs will attempt to read.
    bs->context->attempt=nBits;

    //input bits will be stored in context->buffer.
    actual = bs->readFunc(bs->context);

    if(actual == -1){
        printf("readFunc errored\n");
        return false;
    }else if(actual == 0){
        printf("reached end of file\n");
        return false;
    }

    (*code)++;

    return true;
}
