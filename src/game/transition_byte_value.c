#ifndef LEAF_NAME
#define LEAF_NAME transitionByteValue
#endif

#ifndef FIELD_OFFSET
#define FIELD_OFFSET 0
#endif

#ifndef EXPECTED_VALUE
#define EXPECTED_VALUE 0
#endif

#ifndef REPLACEMENT_VALUE
#define REPLACEMENT_VALUE 1
#endif

void LEAF_NAME(char *object) {
    register int current asm("$14") = object[FIELD_OFFSET];
    register int expected asm("$1") = EXPECTED_VALUE;
    register int replacement asm("$15") = REPLACEMENT_VALUE;

    asm volatile ("" : "=r" (current), "=r" (expected), "=r" (replacement)
                  : "0" (current), "1" (expected), "2" (replacement));
    if (current != expected) {
        return;
    }

    asm volatile ("" : : : "memory");
    object[FIELD_OFFSET] = replacement;
}
