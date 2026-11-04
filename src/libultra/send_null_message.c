#ifndef LEAF_NAME
#define LEAF_NAME sendNullMessage
#endif
#ifndef SEND_MESSAGE_NAME
#define SEND_MESSAGE_NAME sendMessage
#endif
#ifndef QUEUE_NAME
#define QUEUE_NAME queue
#endif

extern char QUEUE_NAME[];
extern void SEND_MESSAGE_NAME(void *queue, void *message, int flags);

void LEAF_NAME(void) {
    SEND_MESSAGE_NAME(QUEUE_NAME, 0, 0);
}
