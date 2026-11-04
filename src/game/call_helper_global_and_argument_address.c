#ifndef LEAF_NAME
#define LEAF_NAME callHelperGlobalAndArgumentAddress
#endif
#ifndef HELPER_NAME
#define HELPER_NAME helper
#endif
#ifndef GLOBAL_NAME
#define GLOBAL_NAME globalObject
#endif

extern char GLOBAL_NAME[];
extern void HELPER_NAME(void *object, void *argument);

void LEAF_NAME(int value) {
    HELPER_NAME(GLOBAL_NAME, &value);
}
