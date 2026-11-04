#ifndef LEAF_NAME
#define LEAF_NAME setNestedFloatQuadBits
#endif
#ifndef FIELD_OFFSET
#define FIELD_OFFSET 0x58
#endif

int LEAF_NAME(
    void **object,
    float first,
    float second,
    float third,
    float fourth
) {
    char *nested = *(char **)object;

    if (nested == 0) {
        return 0;
    }
    *(float *)(nested + FIELD_OFFSET) = first;
    *(float *)(nested + FIELD_OFFSET + 4) = second;
    *(float *)(nested + FIELD_OFFSET + 8) = third;
    *(float *)(nested + FIELD_OFFSET + 12) = fourth;
    return 0;
}
