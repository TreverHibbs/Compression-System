#include <stdio.h>
#include <stdlib.h>
#include <dict.h>



Dict* newDict(unsigned long long hashSize) {
    /* A dict will be a dyncamic array. */
    Dict* myDict = malloc(sizeof(Dict));
    myDict->hashSize = hashSize;
    myDict->table = malloc(sizeof(Sequence**)); 
    *(myDict->table) = calloc(hashSize, sizeof(Sequence*)); 
    
    return(myDict);
}

void deleteDictDeep(Dict* dict) {
    //int i = 0;
    //while(i < (dict->hashSize)){
        //if((*(dict->table))[i]){
            //free((dict->table)[i]);
        //}
        //i++;
    //}
    free((*dict->table));
    free(dict->table);
    free(dict);    
    return;    
}

bool searchDict(Dict* dict, Sequence* key, unsigned int* code) {
    //get the created sequence to find if it is in the dictionary.
    //If it is in the dictuionary return true and set the code pointer/
    // if not return false
    if((dict->table) == NULL){
        printf("dict table NULL\n");
        return(false);
    }

    Sequence* sequence = (dict->table[key->hash]);
    if(sequence == NULL){
        printf("dict sequence NULL at index %llu\n", key->hash);
        return false;
    }

    *code = sequence->code;
    return true;
}

void insertDict(Dict* dict, Sequence* key, unsigned int code) {
    //store the key in the hash table.
    key->code = code;

    //(dict->table)[key->hash] = key;
    
    (*(dict->table)+(key->hash))->length = key->length;
    (*(dict->table)+(key->hash))->hash = key->hash;
    (*(dict->table)+(key->hash))->code = key->code;
    (*(dict->table)+(key->hash))->bucket = key->bucket;
    (*(dict->table)+(key->hash))->bytes[0] = key->bytes[0];
    (*(dict->table)+(key->hash))->bytes[1] = key->bytes[1];

}
