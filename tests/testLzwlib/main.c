#include <stdio.h>
#include <lzw.h>

int main(){
    if(lzwEncode(2, 2, NULL, NULL, NULL)){
        printf("worked\n");
    }
    printf("worked\n");
    return(1);
}
