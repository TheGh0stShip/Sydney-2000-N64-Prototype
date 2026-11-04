#ifndef LEAF_NAME
#define LEAF_NAME callHelper
#endif

#ifndef HELPER_NAME
#define HELPER_NAME helper
#endif

extern void HELPER_NAME(void);

void LEAF_NAME(void) {
    HELPER_NAME();
}
