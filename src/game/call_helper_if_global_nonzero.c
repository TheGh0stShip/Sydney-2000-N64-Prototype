#ifndef LEAF_NAME
#define LEAF_NAME callHelperIfGlobalNonzero
#endif
#ifndef HELPER_NAME
#define HELPER_NAME helper
#endif
#ifndef GLOBAL_NAME
#define GLOBAL_NAME globalValue
#endif

extern int GLOBAL_NAME;
extern int HELPER_NAME(void *object, int value, int argument);

int LEAF_NAME(void *object, int argument) {
    int result;

    if (GLOBAL_NAME != 0) {
        result = HELPER_NAME(object, 0, argument);
    } else {
        result = 0;
    }
    return result;
}
