#ifndef LEAF_NAME
#define LEAF_NAME callHelperIfGlobalAtLeast
#endif
#ifndef HELPER_NAME
#define HELPER_NAME helper
#endif
#ifndef GLOBAL_NAME
#define GLOBAL_NAME globalValue
#endif

extern unsigned int GLOBAL_NAME;
extern void HELPER_NAME(unsigned int value);

int LEAF_NAME(void *unused, unsigned int value) {
    if (GLOBAL_NAME >= value) {
        HELPER_NAME(value);
    }
    return 0;
}
