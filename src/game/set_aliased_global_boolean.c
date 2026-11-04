#ifndef LEAF_NAME
#define LEAF_NAME setAliasedGlobalBoolean
#endif
#ifndef TRUE_GLOBAL_NAME
#define TRUE_GLOBAL_NAME trueGlobal
#endif
#ifndef FALSE_GLOBAL_NAME
#define FALSE_GLOBAL_NAME falseGlobal
#endif

extern int TRUE_GLOBAL_NAME;
extern int FALSE_GLOBAL_NAME;

void LEAF_NAME(int enabled) {
    if (enabled != 0) {
        TRUE_GLOBAL_NAME = 1;
        return;
    }
    FALSE_GLOBAL_NAME = 0;
}
