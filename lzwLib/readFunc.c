#include <readFunc.h>
#include <bitStream.h>

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