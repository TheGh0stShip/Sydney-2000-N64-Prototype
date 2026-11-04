#ifndef LEAF_NAME
#define LEAF_NAME asciiLowercase
#endif

unsigned char *LEAF_NAME(unsigned char *string) {
    unsigned char *current = string;

    while (*current != '\0') {
        unsigned int character = *current;

        if (character - 'A' < 26) {
            *current = character + ('a' - 'A');
        }
        current++;
    }
    return string;
}
