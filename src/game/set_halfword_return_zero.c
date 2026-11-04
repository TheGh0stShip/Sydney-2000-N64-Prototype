#ifndef LEAF_NAME
#define LEAF_NAME setHalfwordReturnZero
#endif

#ifndef FIELD_OFFSET
#define FIELD_OFFSET 0
#endif

#ifndef FIELD_VALUE
#define FIELD_VALUE 0
#endif

int LEAF_NAME(char *object) {
    *(short *)(object + FIELD_OFFSET) = FIELD_VALUE;
    return 0;
}
