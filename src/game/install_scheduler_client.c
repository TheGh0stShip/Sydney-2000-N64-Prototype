#ifndef LEAF_NAME
#define LEAF_NAME installSchedulerClient
#endif
#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocateSchedulerClient
#endif
#ifndef CREATE_QUEUE_NAME
#define CREATE_QUEUE_NAME createMessageQueue
#endif
#ifndef ADD_CLIENT_NAME
#define ADD_CLIENT_NAME addSchedulerClient
#endif

typedef struct SchedulerClient {
    char client[8];
    char frameQueue[0x18];
    void *frameMessages[4];
    char taskQueue[0x18];
    void *taskMessages[4];
} SchedulerClient;

extern void *scheduler;
extern SchedulerClient *schedulerClient;
extern void *ALLOCATE_NAME(int size);
extern void CREATE_QUEUE_NAME(void *queue, void **messages, int count);
extern void ADD_CLIENT_NAME(void *scheduler, void *client, void *queue);

void LEAF_NAME(void)
{
    schedulerClient = ALLOCATE_NAME(sizeof(SchedulerClient));
    CREATE_QUEUE_NAME(&schedulerClient->frameQueue,
                      schedulerClient->frameMessages, 4);
    CREATE_QUEUE_NAME(&schedulerClient->taskQueue,
                      schedulerClient->taskMessages, 4);
    ADD_CLIENT_NAME(scheduler, schedulerClient->client,
                    &schedulerClient->frameQueue);
}
