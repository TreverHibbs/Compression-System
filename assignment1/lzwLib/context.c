#include <stdio.h>
#include <stdlib.h>
#include <context.h>

Context* initContext(char* path){
    /*
    Initialize a context structure pointer with default values for read
    Func. This will provide an easy way to pass parameters to
    organize necesary data for reading from a file such as the file path.
    */
    Context* context = malloc(sizeof(Context));
    
    // context->attempt=attempt;
    // context->buffer= malloc(sizeof(char)*attempt);
    // context->fd = open (path, O_RDWR | O_APPEND, 0666);
    // if (context->fd < 0){
    //     printf("open returned negative number\n");
    // }
    FILE *input = fopen(path, "r");
    FILE *output = fopen(path, "a");

    context->input = input;
    context->output = output;

    return(context);
}

void deleteContext(Context* context){

    fclose(context->input);
    fclose(context->output);
    free(context->input);
    free(context->output);
    free(context);
    return;
}

int readFunc(void* context){
    /*
    This function is meant to be used to get codes one by one from the
    input file. Each code can be a minimum of 8 bits or a maximum of
    24 bits. default is 16 bits.
    */
    // int actual = 0;
    // actual = read(context->fd, context->buffer, context->attempt);

    // if(actual == 0){
    //     printf("eof reached\n");
    //     return(actual);
    // }else if(actual == -1){
    //     printf("read returned %i\n", actual);
    //     return(actual);
    // }

    // return(actual);
    //Returns a pointer to buffer s.
    return fgetc(((Context*) context)->input);
}

void writeFunc(unsigned char c, void* context){
    /* write c to the file specified in the context object. */
    //write(context->fd, &c, sizeof(char));

    fseek(((Context*) context)->output, 0, SEEK_CUR);
    putc(c ,((Context*) context)->output);
    fflush(((Context*) context)->output);


    return;
}