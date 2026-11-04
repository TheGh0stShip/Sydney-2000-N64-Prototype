#ifndef LEAF_NAME
#define LEAF_NAME setByteField
#endif

#ifndef FIELD_OFFSET
#define FIELD_OFFSET 0
#endif

#ifndef FIELD_VALUE
#define FIELD_VALUE 0
#endif

void LEAF_NAME(char *object) {
    register int fieldValue asm("$14") = FIELD_VALUE;

    object[FIELD_OFFSET] = fieldValue;
}
