#include <stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <bitStream.h>

Context* initContext(int attempt, char* path){
    /*
    Initialize a context structure pointer with default values for read
    Func. This will provide an easy way to pass parameters to
    organize necesary data for reading from a file such as the file path.
    */
    Context* context = malloc(sizeof(Context));
    
    context->attempt=attempt;
    context->buffer= malloc(sizeof(char)*attempt);
    context->fd = open (path, O_RDWR | O_APPEND, 0666);
    if (context->fd < 0){
        printf("open returned negative number\n");
    }

    return(context);
}

void freeContext(Context* context){
    free(context->buffer);
    free(context);
    return;
}

int readFunc(Context* context){
    /*
    This function is meant to be used to get codes one by one from the
    input file. Each code can be a minimum of 8 bits or a maximum of
    24 bits. default is 16 bits.
    */
    int actual = 0;
    actual = read(context->fd, context->buffer, context->attempt);

    if(actual == 0){
        printf("eof reached\n");
        return(actual);
    }else if(actual == -1){
        printf("read returned %i\n", actual);
        return(actual);
    }

    return(actual);
}

void writeFunc(unsigned char c, Context* context){
    /* write c to the file specified in the context object. */
    write(context->fd, &c, sizeof(char));	    
        
    return;
}

BitStream* openInputBitStream(int (*readFunc)(Context* context), Context* context) {
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
