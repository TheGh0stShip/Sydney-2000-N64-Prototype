#ifndef LEAF_NAME
#define LEAF_NAME findSubstring
#endif

const unsigned char *LEAF_NAME(
    const volatile unsigned char *text,
    const volatile unsigned char *pattern
) {
    const volatile unsigned char *textCursor;
    const volatile unsigned char *patternCursor;

    while (*text != '\0') {
        textCursor = text;
        patternCursor = pattern;
        do {
            if (*patternCursor == '\0') {
                return (const unsigned char *)text;
            }
        } while (*patternCursor++ == *textCursor++);
        text++;
    }
    return 0;
}
