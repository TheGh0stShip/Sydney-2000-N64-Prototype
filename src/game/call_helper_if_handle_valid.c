#ifndef LEAF_NAME
#define LEAF_NAME callHelperIfHandleValid
#endif
#ifndef HELPER_NAME
#define HELPER_NAME helper
#endif
#ifndef HANDLE_NAME
#define HANDLE_NAME handle
#endif

extern int HANDLE_NAME;
extern int HELPER_NAME(int handle, void *argument);

int LEAF_NAME(void *argument) {
    int result = 0;

    if (HANDLE_NAME != -1) {
        result = HELPER_NAME(HANDLE_NAME, argument);
    }
    return result;
}
