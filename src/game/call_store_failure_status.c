#ifndef LEAF_NAME
#define LEAF_NAME callStoreFailureStatus
#endif

#ifndef HELPER_NAME
#define HELPER_NAME helper
#endif

#ifndef RESULT_GLOBAL
#define RESULT_GLOBAL resultGlobal
#endif

extern int HELPER_NAME(void);
extern int RESULT_GLOBAL;

int LEAF_NAME(void) {
    int result = HELPER_NAME();

    RESULT_GLOBAL = result;
    return result == -1 ? -1 : 0;
}
