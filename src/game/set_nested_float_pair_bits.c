#ifndef LEAF_NAME
#define LEAF_NAME setNestedFloatPairBits
#endif
#ifndef FIELD_OFFSET
#define FIELD_OFFSET 0x60
#endif

int LEAF_NAME(void **object, float first, float second) {
    char *nested = *(char **)object;

    if (nested == 0) {
        return 0;
    }
    *(float *)(nested + FIELD_OFFSET) = first;
    *(float *)(nested + FIELD_OFFSET + 4) = second;
    return 0;
}
