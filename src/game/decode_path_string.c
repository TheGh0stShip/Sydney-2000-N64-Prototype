#ifndef LEAF_NAME
#define LEAF_NAME decodePathString
#endif

void LEAF_NAME(unsigned char *destination, const unsigned char *source) {
    *destination = *source++;
    if (*destination != '\0') {
        do {
            if (*destination == '_') {
                if (*source == '_') {
                    source++;
                    *destination = '\\';
                } else {
                    *destination = '.';
                }
            }
            destination++;
            *destination = *source++;
        } while (*destination != '\0');
    }
}
