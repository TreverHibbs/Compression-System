#include <stdio.h>
#include <strcmp.h>
#include <sequence.h>

int main(int argc, char **argv){
    int test_method_flag = 0;
    int i = 1;

    if(argc <= 1) {
        printf("no arguments\n");
        return(-1);
    }

    while(i < argc){
        if(strcmp(argv[i++], "-t")){
            if(strcmp(argv[i], "newSequence")){
                test_method_flag = 0;
            }else if(strcmp(argv[i], "copySequenceAppending")){
                test_method_flag = 1;
            }else if(strcmp(argv[i], "deleteSequence")){
                test_method_flag = 2;
            }else if(strcmp(argv[i], "outputSequence")){
                test_method_flag = 3;
            }else if(strcmp(argv[i], "identicalSequences")){
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
        printf("Running newSequence\n");
        Sequence* mySequence = newSequence('s', 65536);
        if(mySequence != NULL){
            printf("success returned pointer\n");
            printf("the sequence hash is %llu\n", mySequence->hash);
            printf("the sequence byte is %i\n", mySequence->bytes[0]);
        }else{
            printf("failed\n");
        }
        free(mySequence);
    }else if(test_method_flag == 1){
        printf("Running copySequenceAppending\n");
        Sequence* mySequence = newSequence('s', 10);
        void* out = copySequenceAppending(mySequence, 't', 10);
        if(out != NULL){
            printf("success return sequence\n");
            printf("hash is %llu\n", mySequence->hash);
            printf("new sequence is %c and %c\n", mySequence->bytes[0], mySequence->bytes[1]);
        }else{
            printf("failed");
        }
    }else if(test_method_flag == 2){
        printf("Running deleteSequence\n");
        Sequence* mySequence = newSequence('s', 10);
        deleteSequence(mySequence);
        printf("good no return\n");
    }else if(test_method_flag == 3){
        printf("Running outputSequence\n");
        bool out = outputSequence(NULL, NULL, NULL);
        if(out == 0){
            printf("succes returned 0\n");
        }else{
            printf("failed");
        }
    }else if(test_method_flag == 4){
        printf("Running identicalSequences\n");
        bool out = identicalSequences(NULL, NULL);
        if(out == true){
            printf("succes returned true\n");
        }else{
            printf("failed");
        }
    }else{
        printf("Invalid test flag\n");
    }

    return(1);
}