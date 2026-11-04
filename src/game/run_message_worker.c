#ifndef LEAF_NAME
#define LEAF_NAME runMessageWorker
#endif

#ifndef RECEIVE_NAME
#define RECEIVE_NAME receiveMessage
#endif

#ifndef BROADCAST_NAME
#define BROADCAST_NAME broadcastMessage
#endif

#ifndef UPDATE_NAME
#define UPDATE_NAME updateWorkerState
#endif

#ifndef APPLY_NAME
#define APPLY_NAME applyWorkerConfiguration
#endif

typedef signed int s32;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 prefix[116];
    u8 queue[24];
} MessageWorker;

extern u32 workerReceiveBlocked;
extern u32 workerUpdateRequested;
extern u32 workerUpdateActive;
extern u32 workerUpdateCount;
extern s32 workerConfigurationValue;
extern u8 workerConfiguration[];
extern s32 RECEIVE_NAME(void *queue, void **message, s32 flags);
extern void BROADCAST_NAME(void *first, void *second);
extern void UPDATE_NAME(void);
extern void APPLY_NAME(void *configuration, s32 value);

void LEAF_NAME(MessageWorker *worker) {
    void *message = 0;
    u32 alternate = 0;

    *(volatile u32 *)0x800661D4 = 0;
    for (;;) {
        do {
            RECEIVE_NAME(worker->queue, &message, 1);
        } while (workerReceiveBlocked != 0 || (u32)message != 666);

        BROADCAST_NAME(worker, worker);
        if (alternate != 0 && workerUpdateRequested == 0) {
            workerUpdateActive = 1;
            UPDATE_NAME();
            workerUpdateCount++;
            APPLY_NAME(workerConfiguration, workerConfigurationValue >> 8);
            workerUpdateActive = 0;
        }
        alternate ^= 1;
    }
}
