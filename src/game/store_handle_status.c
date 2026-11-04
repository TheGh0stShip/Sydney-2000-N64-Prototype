#ifndef LEAF_NAME
#define LEAF_NAME storeHandleStatus
#endif
#ifndef HELPER_NAME
#define HELPER_NAME helper
#endif
#ifndef HANDLE_NAME
#define HANDLE_NAME handle
#endif

extern int HANDLE_NAME;
extern int HELPER_NAME(void);

int LEAF_NAME(void) {
    int result = HELPER_NAME();

    HANDLE_NAME = result;
    if (result == -1) {
        return -1;
    }
    return 0;
}
