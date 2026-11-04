#ifndef LEAF_NAME
#define LEAF_NAME callTwoHelpersGlobalAddresses
#endif
#ifndef FIRST_HELPER_NAME
#define FIRST_HELPER_NAME firstHelper
#endif
#ifndef SECOND_HELPER_NAME
#define SECOND_HELPER_NAME secondHelper
#endif
#ifndef FIRST_GLOBAL_NAME
#define FIRST_GLOBAL_NAME firstGlobal
#endif
#ifndef SECOND_GLOBAL_NAME
#define SECOND_GLOBAL_NAME secondGlobal
#endif

extern char FIRST_GLOBAL_NAME[];
extern char SECOND_GLOBAL_NAME[];
extern void FIRST_HELPER_NAME(void *object);
extern void SECOND_HELPER_NAME(void *object);

void LEAF_NAME(void) {
    FIRST_HELPER_NAME(FIRST_GLOBAL_NAME);
    SECOND_HELPER_NAME(SECOND_GLOBAL_NAME);
}
