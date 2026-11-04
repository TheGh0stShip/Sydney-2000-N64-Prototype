#ifndef LEAF_NAME
#define LEAF_NAME callHelperConstant
#endif

#ifndef HELPER_NAME
#define HELPER_NAME helper
#endif

#ifndef ARGUMENT_VALUE
#define ARGUMENT_VALUE 0
#endif

extern void HELPER_NAME(int value);

void LEAF_NAME(void) {
    HELPER_NAME(ARGUMENT_VALUE);
}
