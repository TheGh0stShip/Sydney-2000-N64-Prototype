#ifndef LEAF_NAME
#define LEAF_NAME setNestedObjectFlag
#endif
#ifndef FLAG_VALUE
#define FLAG_VALUE 2
#endif

typedef struct {
    char padding[0x80];
    unsigned int flags;
} NestedObject;

void LEAF_NAME(NestedObject **object, int enabled) {
    NestedObject *nested = *object;

    if (enabled != 0) {
        nested->flags |= FLAG_VALUE;
        return;
    }
    nested->flags &= ~FLAG_VALUE;
}
