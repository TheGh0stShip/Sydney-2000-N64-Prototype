#ifndef LEAF_NAME
#define LEAF_NAME callHelperGlobalHalfword
#endif
#ifndef HELPER_NAME
#define HELPER_NAME helper
#endif
#ifndef GLOBAL_NAME
#define GLOBAL_NAME globalValue
#endif

extern unsigned short GLOBAL_NAME;
extern void HELPER_NAME(unsigned int value);

void LEAF_NAME(void) {
    HELPER_NAME(GLOBAL_NAME);
}
