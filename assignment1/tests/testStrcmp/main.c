#include <stdio.h>
#include <strcmp.h>

int main(int argc, char **argv){
    if(argc == 1){

        printf("please give two strings.\n");
        return(-1);
    }

    printf("%i\n", strcmp(argv[1], argv[2]));
    return(1);
}
