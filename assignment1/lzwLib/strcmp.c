#include <stdio.h>
#include <strcmp.h>

int strcmp(const char *str1, const char *str2){
    if(*str1 == '\0' || *str2 == '\0'){

        printf("Null pointer past aborting\n");
        return(0);
    }
    
    int i = 0;
    while(str1[i] != '\0' && str2[i] != '\0'){
        if(str1[i] != str2[i]){
            return(0);
        }
        i++;
    }

    if(str1[i] == '\0' && str2[i] == '\0'){
        return(1);    
    }

    return(0);
    
    //while *str1 != '/0'
        //check if str1[i] == str2[i]
            //if they dont equal return 0
            //if they do equal increment i
            //and ocmpare again.
}