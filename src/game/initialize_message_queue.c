#ifndef LEAF_NAME
#define LEAF_NAME initializeMessageQueue
#endif
#ifndef CREATE_QUEUE_NAME
#define CREATE_QUEUE_NAME createQueue
#endif
#ifndef READY_NAME
#define READY_NAME ready
#endif
#ifndef QUEUE_NAME
#define QUEUE_NAME queue
#endif
#ifndef BUFFER_NAME
#define BUFFER_NAME buffer
#endif

extern int READY_NAME;
extern char QUEUE_NAME[];
extern void *BUFFER_NAME[];
extern void CREATE_QUEUE_NAME(void *queue, void **buffer, int count);

void LEAF_NAME(void) {
    CREATE_QUEUE_NAME(QUEUE_NAME, BUFFER_NAME, 8);
    READY_NAME = 1;
}
