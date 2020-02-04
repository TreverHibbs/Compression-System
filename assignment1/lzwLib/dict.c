#include <stdio.h>
#include <stdlib.h>
#include <dict.h>



Dict* newDict(unsigned long long hashSize) {
    /* A dict will be a dyncamic array. */
    Dict* myDict = malloc(sizeof(Dict));
    myDict->hashSize = hashSize;
    myDict->table = malloc(sizeof(Sequence*)); 
    (*myDict->table) = calloc(hashSize, sizeof(Sequence)); 
    
    return(myDict);
}

void deleteDictDeep(Dict* dict) {
int i = 0;
    while(i < (dict->hashSize)){
        if(((*dict->table) + i) != NULL){
           deleteSequence((*dict->table)+i);
        }
	i++;
    }
    free(dict->table);
    free(dict);    
    return;    
}

bool searchDict(Dict* dict, Sequence* key, unsigned int* code) {
    Sequence* sequence = (*(dict[key->hash]).table);
    if(sequence == NULL){
        return false;
    }

    *code = sequence->code;
    return true;
}

void insertDict(Dict* dict, Sequence* key, unsigned int code) {
    //store the key in the hash table.
    key->code = code;
	(*(dict[key->hash]).table) = key;

}
