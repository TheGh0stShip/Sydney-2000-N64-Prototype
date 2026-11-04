#ifndef LEAF_NAME
#define LEAF_NAME callHelperGlobalConstant
#endif
#ifndef HELPER_NAME
#define HELPER_NAME helper
#endif
#ifndef GLOBAL_NAME
#define GLOBAL_NAME globalObject
#endif
#ifndef CONSTANT_VALUE
#define CONSTANT_VALUE 2
#endif

extern char GLOBAL_NAME[];
extern void HELPER_NAME(void *object, int value);

void LEAF_NAME(void) {
    HELPER_NAME(GLOBAL_NAME, CONSTANT_VALUE);
}
