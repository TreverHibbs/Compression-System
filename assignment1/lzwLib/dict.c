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
    free(*dict->table);
    free(dict->table);
    free(dict);    
    return;    
}

bool searchDict(Dict* dict, Sequence* key, unsigned int* code) {
    //get the created sequence to find if it is in the dictionary.
    //If it is in the dictuionary return true and set the code pointer/
    // if not return false
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
    
    (*(dict[key->hash]).table)->length = key->length;
    (*(dict[key->hash]).table)->code = key->code;
    (*(dict[key->hash]).table)->hash = key->hash;
    (*(dict[key->hash]).table)->bucket = key->bucket;
    (*(dict[key->hash]).table)->bytes[0] = key->bytes[0];
    (*(dict[key->hash]).table)->bytes[1] = key->bytes[1];

    deleteSequence(key);
}
