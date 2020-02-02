#include <stdlib.h>
#include <bitStream.h>

Context* initContext(int attempt, char* buffer, char* path){
    /*
    Initialize a context structure pointer with default values for read
    Func. This will provide an easy way to pass parameters to
    organize necesary data for reading from a file such as the file path.
    */
    Context* context = malloc(sizeof(Context));
    
    context->attempt=attempt;
    context->buffer=buffer;
    context->path=path;
    context->fd = open (context->path, O_WRONLY, 0644);
    if (context->fd < 0){
        printf("open returned negative number\n");
    }

    return(context);
}

int readFunc(Context* context){
    return(1);
}

BitStream* openInputBitStream(int (*readFunc)(Context* context), Context* context) {
    return NULL;
}

BitStream* openOutputBitStream(void (*writeFunc)(unsigned char c,void* context),void* context) {
    return NULL;
}

void closeAndDeleteBitStream(BitStream* bs) {
}

void outputBits(BitStream* bs, unsigned int nBits, unsigned int code) {
}

bool readInBits(BitStream* bs, unsigned int nBits, unsigned int* code) {
    return true;
}
