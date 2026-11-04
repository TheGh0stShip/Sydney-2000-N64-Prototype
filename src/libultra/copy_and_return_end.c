#ifndef LEAF_NAME
#define LEAF_NAME copyAndReturnEnd
#endif
#ifndef COPY_HELPER_NAME
#define COPY_HELPER_NAME copyHelper
#endif

extern void *COPY_HELPER_NAME(void *destination, const void *source, unsigned int size);

void *LEAF_NAME(void *destination, const void *source, unsigned int size) {
    COPY_HELPER_NAME(destination, source, size);
    return (char *)destination + size;
}
