#ifndef LEAF_NAME
#define LEAF_NAME callHelperWithOutput
#endif
#ifndef HELPER_NAME
#define HELPER_NAME helper
#endif
#ifndef CONTEXT_NAME
#define CONTEXT_NAME context
#endif
#ifndef CALLBACK_NAME
#define CALLBACK_NAME callback
#endif

extern char CONTEXT_NAME[];
extern char CALLBACK_NAME[];
extern void HELPER_NAME(void *context, int *output, void *argument, void *callback);

int LEAF_NAME(void *argument) {
    int output = 0;

    HELPER_NAME(CONTEXT_NAME, &output, argument, CALLBACK_NAME);
    return output;
}
