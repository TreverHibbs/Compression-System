#include <stdlib.h>
#include <sequence.h>

Sequence* newSequence(unsigned char firstByte, unsigned long long hashSize) {
    return NULL;
}

void deleteSequence(Sequence* sequence) {
}

Sequence* copySequenceAppend(Sequence* sequence, unsigned char addByte, unsigned int hashSize) {
    return NULL;
}

unsigned int outputSequence(Sequence* sequence, 
                            void (*writeFunc)(unsigned char c, void* context), 
                            void* context) {
    return(0);
}

bool identicalSequences(Sequence* a, Sequence* b) {
    return true;
}
