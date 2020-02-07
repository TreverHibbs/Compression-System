#include <stdio.h>
#include <strcmp.h>
#include <bitStream.h>
#include <context.h>

int main(int argc, char **argv){
    int test_method_flag = 0;
    int i = 1;
    unsigned int code_size = 16;
    Context *context = initContext("./test_input.txt");

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
        BitStream* bs = openInputBitStream(readFunc, context);
        if(bs != NULL){
            printf("success returned pointer\n");
        }else{
            printf("failed\n");
        }
        closeAndDeleteBitStream(bs);
    }else if(test_method_flag == 1){
        printf("Running openOutputBitStream\n");
        BitStream* bs = openOutputBitStream(writeFunc, context);
        if(bs != NULL){
            printf("success return pointer\n");
            printf("the direction is %d\n", bs->direction);
        }else{
            printf("failed");
        }
        closeAndDeleteBitStream(bs);
    }else if(test_method_flag == 2){
        printf("Running closeAndDeleteBitStream\n");
        BitStream* bs = openInputBitStream(readFunc, context);
        closeAndDeleteBitStream(bs);
        printf("good no return");
    }else if(test_method_flag == 3){
        printf("Running outputBits\n");
        unsigned int code = 29800;
        BitStream* bs = openOutputBitStream(writeFunc, context);

        outputBits(bs, code_size, code);
        printf("good no return\n");
        closeAndDeleteBitStream(bs);
    }else if(test_method_flag == 4){\
        printf("Preparing to run readInBits\n");
        BitStream* bs = openInputBitStream(readFunc, context);
        unsigned int* code = malloc(sizeof(unsigned int*));
	    *code = 0;
        printf("Running readInBits\n");
        bool out = readInBits(bs, code_size, code);
        if(out == true){
            printf("succes returned true\n");
            printf("code is %d\n",  *code);
        }else{
            printf("failed returned false\n");
        }
	    free(code);
        closeAndDeleteBitStream(bs);
    }else{
        printf("Invalid test flag\n");
    }

    deleteContext(context);
    return(1);
}
