#include <stdio.h>
#include <stdlib.h>
#include <strcmp.h>
#include <context.h>

int main(int argc, char **argv){
    int test_method_flag = 0;
    int i = 1;
    char *path = "./test.txt";
    int s = 0;

    if(argc <= 1) {
        printf("no arguments\n");
        return(-1);
    }

    while(i < argc){
        if(strcmp(argv[i++], "-t")){
            if(strcmp(argv[i], "readFunc")){
                test_method_flag = 0;
            }else if(strcmp(argv[i], "writeFunc")){
                test_method_flag = 1;
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
        Context* context = initContext(path);

        s = readFunc(context); 

        if(s != 0){
            printf("success returned %c\n", s);
        }else{
            printf("failed returned 0\n");
        }

        deleteContext(context);
    }else if(test_method_flag == 1){
        printf("Running writeFunc\n");
        Context* context = initContext(path);
        char c = 'a';

        writeFunc(c, context);
        
        printf("no return good\n");

        deleteContext(context);
    }else{
        printf("Invalid test flag\n");
    }

    return(1);
}
