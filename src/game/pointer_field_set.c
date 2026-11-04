#ifndef LEAF_NAME
#define LEAF_NAME pointerFieldSet
#endif

#ifndef FIELD_OFFSET
#define FIELD_OFFSET 0
#endif

void LEAF_NAME(char **object, int value) {
    *(int *)(*object + FIELD_OFFSET) = value;
}
