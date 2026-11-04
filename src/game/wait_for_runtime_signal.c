#ifndef LEAF_NAME
#define LEAF_NAME waitForRuntimeSignal
#endif
#ifndef RECEIVE_NAME
#define RECEIVE_NAME receiveMessage
#endif

typedef signed short s16;
extern unsigned char *runtimeState;
extern void RECEIVE_NAME(void *queue, void **message, int flags);

void LEAF_NAME(void)
{
    void *message;

    do {
        RECEIVE_NAME(runtimeState + 8, &message, 1);
        RECEIVE_NAME(runtimeState + 8, 0, 0);
    } while (*(s16 *)message != 1);
}
