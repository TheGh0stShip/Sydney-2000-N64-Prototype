#ifndef LEAF_NAME
#define LEAF_NAME writeObjectWordBytes
#endif

#ifndef BYTE_OFFSET
#define BYTE_OFFSET 0
#endif

#ifndef OBJECT_FLAG
#define OBJECT_FLAG 0
#endif

int LEAF_NAME(unsigned char **object, unsigned int value) {
    register unsigned char *current asm("$3") = *object;
    register unsigned int flags asm("$2");

    asm volatile ("" : "=r" (current) : "0" (current));
    current[BYTE_OFFSET] = value >> 16;
    current[BYTE_OFFSET + 1] = value >> 8;
    asm volatile ("" : : : "memory");
    flags = *(unsigned int *)current;
    asm volatile ("" : "=r" (flags) : "0" (flags));
    current[BYTE_OFFSET + 2] = value;
    current[BYTE_OFFSET + 3] = value >> 24;
    asm volatile ("" : : : "memory");
    flags |= OBJECT_FLAG;
    *(unsigned int *)current = flags;
    return 0;
}
