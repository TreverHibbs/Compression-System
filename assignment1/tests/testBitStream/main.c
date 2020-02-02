#include <stdio.h>
#include <strcmp.h>
#include <bitStream.h>
#include <stdlib.h>

int main(int argc, char **argv){
    int test_method_flag = 0;
    int i = 1;
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
        char buffer[16];
        if(openInputBitStream(readFunc, initContext(16, buffer, "./test_input.txt")) == NULL){
            printf("returned NULL\n");
        }else{
            printf("failed");
        }
    }else if(test_method_flag == 1){
        printf("Running openOutputBitStream\n");
        if(openOutputBitStream(NULL, NULL) == NULL){
            printf("returned NULL\n");
        }else{
            printf("failed");
        }
    }else if(test_method_flag == 2){
        printf("Running closeAndDeleteBitStream\n");
        closeAndDeleteBitStream(NULL);
        printf("good no return");
    }else if(test_method_flag == 3){
        printf("Running outputBits\n");
        outputBits(NULL, 1, 1);
        printf("good no return");
    }else if(test_method_flag == 4){
        printf("Running readInBits\n");
        if(readInBits(NULL, 1, NULL) == true){
            printf("returned true\n");
        }else{
            printf("failed");
        }
    }else if(test_method_flag == 5){
        printf("Running initContext()\n");
        char buffer[16];
        void *pointer = initContext(16, buffer, "./test_input.txt");
        if(pointer != NULL){
            printf("good returned non NULL pointer -> %p\n", pointer);
            free(pointer);
        }else{
            printf("failed\n");
        }
    }else if(test_method_flag == 6){
        printf("Running readFunc\n");
        if(readFunc(NULL) == 1){
            printf("good returned 1\n");
        }else{
            printf("failed");
        }
    }else{
        printf("Invalid test flag\n");
    }

    return(1);
}