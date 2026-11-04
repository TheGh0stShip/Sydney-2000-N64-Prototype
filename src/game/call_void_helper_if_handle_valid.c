#ifndef LEAF_NAME
#define LEAF_NAME callVoidHelperIfHandleValid
#endif
#ifndef HELPER_NAME
#define HELPER_NAME helper
#endif
#ifndef HANDLE_NAME
#define HANDLE_NAME handle
#endif

extern int HANDLE_NAME;
extern void HELPER_NAME(int handle, void *argument);

void LEAF_NAME(void *argument) {
    if (HANDLE_NAME != -1) {
        HELPER_NAME(HANDLE_NAME, argument);
    }
}
