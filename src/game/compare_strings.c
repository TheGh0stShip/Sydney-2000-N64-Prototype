#ifndef LEAF_NAME
#define LEAF_NAME compareStrings
#endif

int LEAF_NAME(const char *first, const char *second) {
    int left;
    int right;

    for (;;) {
        left = *first++;
        right = *second++;
        if ((unsigned char)left == (unsigned char)right) {
            if (left != 0) {
                continue;
            }
            return 0;
        }

        return (unsigned char)left - (unsigned char)right;
    }
}
