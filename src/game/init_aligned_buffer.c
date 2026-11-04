#ifndef LEAF_NAME
#define LEAF_NAME initAlignedBuffer
#endif

#ifndef MINIMUM_SIZE
#define MINIMUM_SIZE 32
#endif

void *LEAF_NAME(void *buffer, unsigned int size) {
    unsigned int original = (unsigned int)buffer;
    unsigned int address;
    unsigned int padding;
    unsigned int *header;

    if (size < MINIMUM_SIZE) {
        return (void *)-1;
    }

    address = (original + 15) & -16;
    padding = address - original;
    size -= padding;
    header = (unsigned int *)address;
    header[0] = 0;
    asm volatile ("" : "=r" (size) : "0" (size) : "memory");
    header[1] = size - 16;
    header[2] = 0;
    header[3] = size;
    return header;
}
