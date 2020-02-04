#include <stdio.h>
#include <dict.h>
#include <strcmp.h>

int main(int argc, char **argv){
    int test_method_flag = 0;
    int i = 1;
    unsigned long long hashSize = 65536;
    //unsigned int code_size = 2;

    if(argc <= 1) {
        printf("no arguments\n");
        return(-1);
    }

    while(i < argc){
        if(strcmp(argv[i++], "-t")){
            if(strcmp(argv[i], "newDict")){
                test_method_flag = 0;
            }else if(strcmp(argv[i], "deleteDictDeep")){
                test_method_flag = 1;
            }else if(strcmp(argv[i], "searchDict")){
                test_method_flag = 2;
            }else if(strcmp(argv[i], "insertDict")){
                test_method_flag = 3;
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
        printf("Running newDict\n");
        Dict* out = newDict(hashSize);
        if(out != NULL){
            printf("success returned pointer\n");
	    printf("this is the hashSize of newDict %u\n", out->hashSize);
        }else{
            printf("failed\n");
        }
    }else if(test_method_flag == 1){
        printf("Running deleteDictDeep\n");
	Dict* myDict = newDict(hashSize);
        deleteDictDeep(myDict);
        printf("good no return\n");
    }else if(test_method_flag == 2){
        printf("Running searchDict\n");
        bool out = searchDict(NULL, NULL, NULL);
        if(out == false){
            printf("success returned false\n");
        }else{
            printf("fail\n");
        }
    }else if(test_method_flag == 3){
        printf("Running insertDict\n");
        insertDict(NULL, NULL, 1);
        printf("good no return\n");
    }else{
        printf("Invalid test flag\n");
    }

    return(1);
}
