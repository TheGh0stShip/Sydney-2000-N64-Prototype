#ifndef LEAF_NAME
#define LEAF_NAME waitForMessageType
#endif

#ifndef RECEIVE_NAME
#define RECEIVE_NAME receiveMessage
#endif

#ifndef QUEUE_NAME
#define QUEUE_NAME queue
#endif

typedef signed short s16;

extern unsigned char QUEUE_NAME[];
extern int RECEIVE_NAME(void *queue, void **message, int flags);

void LEAF_NAME(void) {
    register unsigned char *globalBase __asm__("$2");
    register void *messageQueue __asm__("$16");
    register void *queueArgument __asm__("$4");
    register void *zeroArgument __asm__("$5");
    void *message;

    globalBase = (unsigned char *)0x80070000;
    __asm__("" : "=r"(globalBase) : "0"(globalBase));
    messageQueue = globalBase - 0x47E0;
    __asm__("" : "=r"(messageQueue) : "0"(messageQueue));
    do {
        RECEIVE_NAME(messageQueue, &message, 1);
        queueArgument = messageQueue;
        __asm__("" : "=r"(queueArgument) : "0"(queueArgument));
        zeroArgument = 0;
        __asm__("" : "=r"(zeroArgument) : "0"(zeroArgument));
        RECEIVE_NAME(queueArgument, zeroArgument, (int)zeroArgument);
    } while (*(s16 *)message != 1);
}
