#include <stdlib.h>
#include <sequence.h>

Sequence* newSequence(unsigned char firstByte, unsigned long long hashSize) {
    Sequence* mySequence = malloc(sizeof(Sequence));
    mySequence->bytes[0] = firstByte;
    if(hashSize != 0){
	//use the has function to generate a hash for the current sequence.
        mySequence->hash = hashSize % mySequence->bytes[0]; 
    } 
    mySequence->length = 1;

    return mySequence;
}

void deleteSequence(Sequence* sequence) {
    free(sequence);
    return;
}

Sequence* copySequenceAppending(Sequence* sequence, unsigned char newByte, unsigned long long hashSize) {
    sequence->bytes[1] = newByte;
    // Compute a new hash for the sequence.
    sequence->hash = hashSize % (sequence->bytes[0] + sequence->bytes[1]);
    sequence->length = 2;

    return sequence;
}

int outputSequence(Sequence* sequence, 
    void (*writeFunc)(unsigned char c, void* context), 
    void* context) {

    if(sequence->length == 2){
        writeFunc(sequence->bytes[0], context);
        writeFunc(sequence->bytes[1], context);
        return(2);
    }else if(sequence->length == 1){
        writeFunc(sequence->bytes[0], context);
        return(1);
    }    
    
    return(0);
}

bool identicalSequences(Sequence* a, Sequence* b) {
    int i = 0;
    while(i < 2){
        if(a->bytes[i] != b->bytes[i]){
            return(false);
        }
    }
    return true;
}
