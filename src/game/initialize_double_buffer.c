#ifndef LEAF_NAME
#define LEAF_NAME initializeDoubleBuffer
#endif
#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocate
#endif
#ifndef COPY_NAME
#define COPY_NAME copyBytes
#endif
#ifndef TAG_NAME
#define TAG_NAME tag
#endif

typedef struct {
    int unused0;
    void *source;
    int unused8;
    void *firstBuffer;
    void *secondBuffer;
    unsigned short count;
    unsigned short flags;
} DoubleBuffer;

typedef struct {
    unsigned char padding[0x56B0];
    void *context;
} Globals;

extern char TAG_NAME[];

void ALLOCATE_NAME(void *context, void **output, unsigned int size, char *tag);
void *COPY_NAME(void *destination, const void *source, unsigned int size);

void LEAF_NAME(DoubleBuffer *buffer) {
    register Globals *globals __asm__("$17");

    if (buffer->firstBuffer != 0) {
        return;
    }
    globals = (Globals *)0x80040000;
    __asm__("" : "=r"(globals) : "0"(globals));
    ALLOCATE_NAME(
        globals->context,
        &buffer->firstBuffer,
        buffer->count << 4,
        TAG_NAME
    );
    ALLOCATE_NAME(
        globals->context,
        &buffer->secondBuffer,
        buffer->count << 4,
        TAG_NAME
    );
    COPY_NAME(buffer->firstBuffer, buffer->source, buffer->count << 4);
    COPY_NAME(buffer->secondBuffer, buffer->source, buffer->count << 4);
    buffer->flags |= 0x10;
}
