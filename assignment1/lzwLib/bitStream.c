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
    context->fd = open (path, O_RDWR, 0666);
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

BitStream* openInputBitStream(int (*readFunc)(Context* context), Context* context) {
    /*
    This function will initialize a BitStream object.
    */
    BitStream* bitStream = malloc(sizeof(BitStream));
    int actual = readFunc(context);

    if(actual == -1){
        printf("readFunc returned -1\n");
        return NULL;
    }

    bitStream->readFunc = readFunc;
    bitStream->context = context;
    bitStream->direction = 1; //1 indicates and input direction.
    bitStream->extraCount = 0; //irelavent for input bitStream.
    bitStream->extraBits = 0; //irelavent for input bitStream.
    bitStream->byteCount = actual;
    
    return (bitStream);
}

BitStream* openOutputBitStream(void (*writeFunc)(unsigned char c,void* context),void* context) {
    return NULL;
}

void closeAndDeleteBitStream(BitStream* bs) {
    freeContext(bs->context);
    free(bs);
    return;
}

void outputBits(BitStream* bs, unsigned int nBits, unsigned int code) {
}

bool readInBits(BitStream* bs, unsigned int nBits, unsigned int* code) {
    int actual = 0;
    bs->context->attempt=nBits;

    actual = bs->readFunc(bs->context);

    if(actual == -1){
        printf("readFunc errored\n");
        return false;
    }else if(actual == 0){
        printf("reached end of file\n");
        return false;
    }

    //add code here that searches dict for code.

    return true;


}
