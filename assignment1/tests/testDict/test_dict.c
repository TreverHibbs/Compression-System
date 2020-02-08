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
            printf("this is the pointer to the table %p\n", out->table);
        }else{
            printf("failed\n");
        }
        deleteDictDeep(out);
    }else if(test_method_flag == 1){
        printf("Running deleteDictDeep\n");
	    Dict* myDict = newDict(hashSize);
        deleteDictDeep(myDict);
        printf("good no return\n");
    }else if(test_method_flag == 2){
        printf("Running searchDict\n");
        Dict* myDict = newDict(hashSize);
        Sequence* mySequence = newSequence('a', hashSize);
        unsigned int* code;

        bool out = searchDict(myDict, mySequence, code);
        if(out == false){
            printf("success returned false\n");
        }else{
            printf("fail\n");
        }

        deleteDictDeep(myDict);
        deleteSequence(mySequence);
    }else if(test_method_flag == 3){
        unsigned int* code = malloc(sizeof(unsigned int*));
        *code = 'a';
        Dict* myDict = newDict(hashSize);
        Sequence* mySequence = newSequence('a', hashSize);
        printf("Running insertDict\n");
        insertDict(myDict, mySequence, 'a');
        bool found = searchDict(myDict, mySequence, code);
        if(found){
            printf("insert was successfull and found by searchDict\n");
            printf("code is %u\n", *code);
        }else{
            printf("insert was unsuccesfull or was not found by searchDict\n");
        }

        free(mySequence);
        printf("good no return\n");
        deleteDictDeep(myDict);
        free(code);
    }else{
        printf("Invalid test flag\n");
    }

    return(1);
}
