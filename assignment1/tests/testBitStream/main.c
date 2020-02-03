#include <stdio.h>
#include <strcmp.h>
#include <bitStream.h>

int main(int argc, char **argv){
    int test_method_flag = 0;
    int i = 1;
    unsigned int code_size = 2;
    Context *context = initContext(code_size, "./test_input.txt");

    if(argc <= 1) {
        printf("no arguments\n");
        return(-1);
    }

    while(i < argc){
        if(strcmp(argv[i++], "-t")){
            if(strcmp(argv[i], "openInputBitStream")){
                test_method_flag = 0;
            }else if(strcmp(argv[i], "openOutputBitStream")){
                test_method_flag = 1;
            }else if(strcmp(argv[i], "closeAndDeleteBitStream")){
                test_method_flag = 2;
            }else if(strcmp(argv[i], "outputBits")){
                test_method_flag = 3;
            }else if(strcmp(argv[i], "readInBits")){
                test_method_flag = 4;
            }else if(strcmp(argv[i], "initContext")){
                test_method_flag = 5;
            }else if(strcmp(argv[i], "readFunc")){
                test_method_flag = 6;
            }else if(strcmp(argv[i], "writeFunc")){
                test_method_flag = 7;
            }else{
                printf("no argument for -t\n");
                return(-1);
            }
            i++;
        }else{
            printf("invalid or no flags\n");
            return(-1);
        }
    }

    if(test_method_flag == 0){
        printf("Running openInputBitStream\n");
        if(openInputBitStream(readFunc, context) != NULL){
            printf("success returned pointer\n");
        }else{
            printf("failed\n");
        }
    }else if(test_method_flag == 1){
        printf("Running openOutputBitStream\n");
        BitStream* bs = openOutputBitStream(writeFunc, context);
        if(bs != NULL){
            printf("success return pointer\n");
            printf("the context file path is %d\n", bs->context->fd);
            printf("the direction is %d\n", bs->direction);
        }else{
            printf("failed");
        }
        closeAndDeleteBitStream(bs);
    }else if(test_method_flag == 2){
        printf("Running closeAndDeleteBitStream\n");
        closeAndDeleteBitStream(NULL);
        printf("good no return");
    }else if(test_method_flag == 3){
        printf("Running outputBits\n");
        outputBits(NULL, 1, 1);
        printf("good no return");
    }else if(test_method_flag == 4){
        BitStream* bs = openInputBitStream(readFunc, context);
        unsigned int* code;
        printf("Running readInBits\n");
        bool out = readInBits(bs, code_size, code);
        if(out == true){
            printf("succes returned true\n");
        }else{
            printf("failed");
        }
        closeAndDeleteBitStream(bs);
    }else if(test_method_flag == 5){
        printf("Running initContext()\n");
        Context *pointer = initContext(code_size, "./test_input.txt");
        if(pointer != NULL){
            printf("good returned non NULL pointer.\n");
            free(pointer);
        }else{
            printf("failed\n");
        }
    }else if(test_method_flag == 6){

        printf("Running readFunc\n");
        int value = readFunc(context);
        if(value != 0){
            printf("good returned %i\n", value);
	    printf("context buff is %s\n", context->buffer);
            value = readFunc(context);
	    printf("context buff is %s\n", context->buffer);
        }else{
            printf("failed\n");
        }
        freeContext(context);
    }else if(test_method_flag == 7){
        unsigned char c = 's';
        printf("Running writeFunc\n");
        writeFunc(c, context);
        printf("good no return value\n");
        freeContext(context);
    }else{
        printf("Invalid test flag\n");
    }

    return(1);
}
