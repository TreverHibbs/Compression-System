#include <stdio.h>
#include <strcmp.h>
#include <bitStream.h>
#include <readFunc.h>

int main(int argc, char **argv){
    int test_method_flag = 0;
    int i = 1;
    int code_size = 10;
    Context *myContext = initContext(code_size, "./test_input.txt");

    if(argc <= 1) {
        printf("no arguments\n");
        return(-1);
    }

    while(i < argc){
        if(strcmp(argv[i++], "-t")){
            if(strcmp(argv[i], "readFunc")){
                test_method_flag = 0;
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
        printf("Running readFunc\n");
        int actual = readFunc(myContext);
        if(actual == code_size){
            printf("success read data\n");
            printf("the buffer is %s\n", myContext->buffer);
            printf("the attempt is %i\n", myContext->attempt);
        }else{
            printf("failed\n");
        }
        freeContext(myContext);
    }else{
        printf("Invalid test flag\n");
    }

    return(1);
}