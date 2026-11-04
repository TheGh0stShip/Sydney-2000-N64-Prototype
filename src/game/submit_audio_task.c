#ifndef LEAF_NAME
#define LEAF_NAME submitAudioTask
#endif
#ifndef QUEUE_NAME
#define QUEUE_NAME getSchedulerQueue
#endif
#ifndef SEND_NAME
#define SEND_NAME sendMessage
#endif
#ifndef RECEIVE_NAME
#define RECEIVE_NAME receiveMessage
#endif

typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    u32 type;
    u32 flags;
    u64 *ucodeBoot;
    u32 ucodeBootSize;
    u64 *ucode;
    u32 ucodeSize;
    u64 *ucodeData;
    u32 ucodeDataSize;
    u64 *dramStack;
    u32 dramStackSize;
    u64 *outputBuffer;
    u64 *outputBufferSize;
    u64 *dataPointer;
    u32 dataSize;
    u64 *yieldDataPointer;
    u32 yieldDataSize;
} TaskList;

typedef struct SchedulerTask {
    struct SchedulerTask *next;
    u32 state;
    u32 flags;
    void *framebuffer;
    TaskList list;
    void *messageQueue;
    void *message;
    u32 pad[4];
} SchedulerTask;

typedef struct {
    u64 *dataPointer;
    u32 dataSize;
    u64 *ucode;
    u64 *ucodeData;
} AudioTask;

typedef struct {
    unsigned char pad[0x30];
    char queue[0x18];
} SchedulerClient;

extern void *scheduler;
extern SchedulerClient *schedulerClient;
extern u64 ucodeBootStart[];
extern u64 ucodeBootEnd[];
extern void *QUEUE_NAME(void *scheduler);
extern int SEND_NAME(void *queue, void *message, int flags);
extern int RECEIVE_NAME(void *queue, void *message, int flags);

void LEAF_NAME(AudioTask *task)
{
    SchedulerTask schedulerTask;
    char message[0x20];

    schedulerTask.messageQueue = schedulerClient->queue;
    schedulerTask.next = 0;
    schedulerTask.message = message;
    schedulerTask.flags = 2;
    schedulerTask.list.dataPointer = task->dataPointer;
    schedulerTask.list.dataSize = task->dataSize;
    schedulerTask.list.type = 2;
    schedulerTask.list.ucodeBoot = ucodeBootStart;
    schedulerTask.list.ucodeBootSize = (u32)ucodeBootEnd - (u32)ucodeBootStart;
    schedulerTask.list.flags = 0;
    schedulerTask.list.ucode = task->ucode;
    schedulerTask.list.ucodeData = task->ucodeData;
    schedulerTask.list.ucodeSize = 0x1000;
    schedulerTask.list.ucodeDataSize = 0x800;
    schedulerTask.list.dramStack = 0;
    schedulerTask.list.dramStackSize = 0;
    schedulerTask.list.outputBuffer = 0;
    schedulerTask.list.outputBufferSize = 0;
    schedulerTask.list.yieldDataPointer = 0;
    schedulerTask.list.yieldDataSize = 0;
    SEND_NAME(QUEUE_NAME(scheduler), &schedulerTask, 1);
    RECEIVE_NAME(schedulerClient->queue, 0, 1);
}
