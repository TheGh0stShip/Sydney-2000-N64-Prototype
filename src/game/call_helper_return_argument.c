#ifndef LEAF_NAME
#define LEAF_NAME callHelperReturnArgument
#endif

#ifndef HELPER_NAME
#define HELPER_NAME helper
#endif

extern void HELPER_NAME(void *value);

void *LEAF_NAME(void *value) {
    HELPER_NAME(value);
    return value;
}
