#ifndef LEAF_NAME
#define LEAF_NAME appendString
#endif

unsigned char *LEAF_NAME(
    unsigned char *destination,
    const unsigned char *source
) {
    register unsigned char *cursor __asm__("$3");

    cursor = destination;
    if (*destination == '\0') {
        goto check_source;
    }
    do {
        cursor++;
    } while (*cursor != '\0');
    goto check_source;

copy_character:
    *cursor = *source;
    source++;
    cursor++;
check_source:
    if (*source != '\0') {
        goto copy_character;
    }
    *cursor = '\0';
    return destination;
}
