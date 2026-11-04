#ifndef LEAF_NAME
#define LEAF_NAME callHelperGlobalAddress
#endif
#ifndef HELPER_NAME
#define HELPER_NAME helper
#endif
#ifndef GLOBAL_NAME
#define GLOBAL_NAME globalObject
#endif

extern char GLOBAL_NAME[];
extern void HELPER_NAME(void *object);

void LEAF_NAME(void) {
    HELPER_NAME(GLOBAL_NAME);
}
