#include <stdlib.h>
#include <sequence.h>

Sequence* newSequence(unsigned char firstByte, unsigned long long hashSize) {
    Sequence* mySequence = malloc(sizeof(Sequence));
    mySequence->bytes[0] = firstByte;
    if(hashSize != 0){
        mySequence->bucket = mySequence->bytes[0] % hashSize; 
    } 

    return mySequence;
}

void deleteSequence(Sequence* sequence) {
    free(sequence);
    return;
}

Sequence* copySequenceAppending(Sequence* sequence, unsigned char newByte, unsigned long long hashSize) {
    sequence->bytes[1] = newByte;
    // Compute a new hash for the sequence.
    sequence->bucket = (sequence->bytes[0] + sequence->bytes[1]) % hashSize;

    return sequence;
}

unsigned int outputSequence(Sequence* sequence, 
                            void (*writeFunc)(unsigned char c, void* context), 
                            void* context) {
    return(0);
}

bool identicalSequences(Sequence* a, Sequence* b) {
    return true;
}
