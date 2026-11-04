#ifndef LEAF_NAME
#define LEAF_NAME callHelperThenClear
#endif

#ifndef HELPER_NAME
#define HELPER_NAME helper
#endif

extern void HELPER_NAME(void *value);

void LEAF_NAME(int *value) {
    HELPER_NAME(value);
    *value = 0;
}
