#ifndef LEAF_NAME
#define LEAF_NAME initializeSchedulerQueues
#endif

#ifndef CREATE_QUEUE_NAME
#define CREATE_QUEUE_NAME createQueue
#endif

#ifndef ADD_CLIENT_NAME
#define ADD_CLIENT_NAME addClient
#endif

#ifndef FIRST_QUEUE_NAME
#define FIRST_QUEUE_NAME firstQueue
#endif

#ifndef FIRST_BUFFER_NAME
#define FIRST_BUFFER_NAME firstBuffer
#endif

#ifndef SECOND_QUEUE_NAME
#define SECOND_QUEUE_NAME secondQueue
#endif

#ifndef SECOND_BUFFER_NAME
#define SECOND_BUFFER_NAME secondBuffer
#endif

#ifndef SCHEDULER_NAME
#define SCHEDULER_NAME scheduler
#endif

#ifndef CLIENT_NAME
#define CLIENT_NAME client
#endif

typedef signed int s32;
typedef unsigned char u8;

extern u8 FIRST_QUEUE_NAME[];
extern u8 FIRST_BUFFER_NAME[];
extern u8 SECOND_QUEUE_NAME[];
extern u8 SECOND_BUFFER_NAME[];
extern u8 SCHEDULER_NAME[];
extern u8 CLIENT_NAME[];

extern void CREATE_QUEUE_NAME(void *queue, void *buffer, s32 count);
extern void ADD_CLIENT_NAME(void *scheduler, void *client, void *queue);

void LEAF_NAME(void) {
    CREATE_QUEUE_NAME(FIRST_QUEUE_NAME, FIRST_BUFFER_NAME, 4);
    CREATE_QUEUE_NAME(SECOND_QUEUE_NAME, SECOND_BUFFER_NAME, 4);
    ADD_CLIENT_NAME(SCHEDULER_NAME, CLIENT_NAME, FIRST_QUEUE_NAME);
}
