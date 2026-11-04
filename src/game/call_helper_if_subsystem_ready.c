#ifndef LEAF_NAME
#define LEAF_NAME callHelperIfSubsystemReady
#endif
#ifndef PREPARE_HELPER_NAME
#define PREPARE_HELPER_NAME prepareHelper
#endif
#ifndef MAIN_HELPER_NAME
#define MAIN_HELPER_NAME mainHelper
#endif
#ifndef SUBSYSTEM_NAME
#define SUBSYSTEM_NAME subsystem
#endif

extern void *SUBSYSTEM_NAME;
extern void PREPARE_HELPER_NAME(void);
extern int MAIN_HELPER_NAME(void *object, int argument, int value);

int LEAF_NAME(void *object, int argument) {
    if (SUBSYSTEM_NAME == 0) {
        return -1;
    }
    PREPARE_HELPER_NAME();
    return MAIN_HELPER_NAME(object, argument, 0);
}
