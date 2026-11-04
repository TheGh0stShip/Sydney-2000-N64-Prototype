#ifndef LEAF_NAME
#define LEAF_NAME argumentOffset
#endif

#ifndef FIELD_OFFSET
#define FIELD_OFFSET 0
#endif

char *LEAF_NAME(char *object) {
    return object + FIELD_OFFSET;
}
