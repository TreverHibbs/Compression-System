typedef struct context_s {
    FILE *input;
    FILE *output;
    
} Context;


int readFunc(void* context);

void writeFunc(unsigned char c, void* context);

Context* initContext(char *path);

void deleteContext(Context* context);