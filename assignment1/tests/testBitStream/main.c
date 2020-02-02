#include <stdio.h>
#include <strcmp.h>

int main(int argc, char **argv){
    int test_method_flag = 0;
    int i = 1;
    if(argc <= 1) {
        printf("no arguments\n");
        return(-1);
    }

    while(i < argc){
        if(strcmp(argv[i++], "-t")){
            if(strcmp(argv[i++], "methodName")){
                test_method_flag = 0;
            }else{
                printf("no argument for -t\n");
                return(-1);
            }
        }else{
            printf("invalid or no flags\n");
            return(-1);
        }
    }

    if(test_method_flag == 0){
        printf("this test worked\n");
        return(1);
    }

    return(1);

    //while argc is not zero 
        //check the arguements of argv
            //first check for a option flag
            //and then use the data in the next index in the
            //argv array accordingly.
            //go to the top of the loop.
}