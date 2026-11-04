#ifndef LEAF_NAME
#define LEAF_NAME startPiWorkerThread
#endif

#ifndef CREATE_PI_MANAGER_NAME
#define CREATE_PI_MANAGER_NAME createPiManager
#endif

#ifndef CREATE_THREAD_NAME
#define CREATE_THREAD_NAME createThread
#endif

#ifndef START_THREAD_NAME
#define START_THREAD_NAME startThread
#endif

#ifndef WORKER_NAME
#define WORKER_NAME worker
#endif

#ifndef PI_QUEUE_NAME
#define PI_QUEUE_NAME piQueue
#endif

#ifndef PI_MESSAGES_NAME
#define PI_MESSAGES_NAME piMessages
#endif

#ifndef THREAD_NAME
#define THREAD_NAME thread
#endif

#ifndef STACK_TOP_NAME
#define STACK_TOP_NAME stackTop
#endif

typedef signed int s32;
typedef unsigned char u8;

extern u8 PI_QUEUE_NAME[];
extern u8 PI_MESSAGES_NAME[];
extern u8 THREAD_NAME[];
extern u8 STACK_TOP_NAME[];

extern void CREATE_PI_MANAGER_NAME(s32 priority, void *queue,
                                   void *messages, s32 count);
extern void CREATE_THREAD_NAME(void *thread, s32 id, void (*entry)(void *),
                               void *argument, void *stackTop, s32 priority);
extern void START_THREAD_NAME(void *thread);
extern void WORKER_NAME(void *argument);

void LEAF_NAME(void *argument) __attribute__((noreturn));

void LEAF_NAME(void *argument) {
    CREATE_PI_MANAGER_NAME(150, PI_QUEUE_NAME, PI_MESSAGES_NAME, 50);
    CREATE_THREAD_NAME(THREAD_NAME, 3, WORKER_NAME, argument, STACK_TOP_NAME, 10);
    START_THREAD_NAME(THREAD_NAME);
    for (;;) {
    }
}
