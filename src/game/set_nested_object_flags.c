#ifndef LEAF_NAME
#define LEAF_NAME setNestedObjectFlags
#endif

typedef struct {
    char padding[0x14];
    unsigned int flags;
} NestedObject;

int LEAF_NAME(NestedObject **object, unsigned int flags) {
    NestedObject *nested = *object;

    flags |= 8;
    if (nested == 0) {
        return 0;
    }
    nested->flags |= flags;
    return 0;
}
