#ifndef LEAF_NAME
#define LEAF_NAME callHelperIfFlag
#endif

#ifndef HELPER_NAME
#define HELPER_NAME helper
#endif

#ifndef FLAG_MASK
#define FLAG_MASK 1
#endif

extern void HELPER_NAME(void *value);

void LEAF_NAME(void *value, int flags) {
    if (flags & FLAG_MASK) {
        HELPER_NAME(value);
    }
}
