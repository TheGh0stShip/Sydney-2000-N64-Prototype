#ifndef LEAF_NAME
#define LEAF_NAME copyString
#endif

unsigned char *LEAF_NAME(
    unsigned char *destination,
    const unsigned char *source
) {
    unsigned char *cursor = destination;

    if (*source != '\0') {
        do {
            *cursor = *source;
            source++;
            cursor++;
        } while (*source != '\0');
    }
    *cursor = '\0';
    return destination;
}
