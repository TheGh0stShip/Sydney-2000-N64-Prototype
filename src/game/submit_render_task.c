#ifndef LEAF_NAME
#define LEAF_NAME submitRenderTask
#endif
#ifndef SEND_NAME
#define SEND_NAME sendMessage
#endif
#ifndef RESOURCE_PAIRS_NAME
#define RESOURCE_PAIRS_NAME renderResourcePairs
#endif
#ifndef FIRST_BUFFER_NAME
#define FIRST_BUFFER_NAME firstRenderBuffer
#endif
#ifndef SECOND_BUFFER_NAME
#define SECOND_BUFFER_NAME secondRenderBuffer
#endif
#ifndef OUTPUT_BUFFER_NAME
#define OUTPUT_BUFFER_NAME renderOutputBuffer
#endif
#ifndef MESSAGE_QUEUE_NAME
#define MESSAGE_QUEUE_NAME renderMessageQueue
#endif
#ifndef FIRST_SIGNAL_NAME
#define FIRST_SIGNAL_NAME firstRenderSignal
#endif
#ifndef SECOND_SIGNAL_NAME
#define SECOND_SIGNAL_NAME secondRenderSignal
#endif
#ifndef QUEUE_NAME
#define QUEUE_NAME schedulerCommandQueue
#endif
#ifndef INDEX_NAME
#define INDEX_NAME renderTaskIndex
#endif
#ifndef INDEX_LIMIT_NAME
#define INDEX_LIMIT_NAME renderTaskLimit
#endif
#ifndef MESSAGE_TABLE_NAME
#define MESSAGE_TABLE_NAME renderTaskMessages
#endif
#ifndef FRAME_NAME
#define FRAME_NAME renderFrame
#endif

typedef unsigned int u32;

extern u32 RESOURCE_PAIRS_NAME[][2];
extern u32 FIRST_BUFFER_NAME;
extern u32 SECOND_BUFFER_NAME;
extern u32 OUTPUT_BUFFER_NAME;
extern u32 MESSAGE_QUEUE_NAME;
extern u32 FIRST_SIGNAL_NAME;
extern u32 SECOND_SIGNAL_NAME;
extern void *QUEUE_NAME;
extern u32 INDEX_NAME;
extern u32 INDEX_LIMIT_NAME;
extern u32 MESSAGE_TABLE_NAME[];
extern u32 FRAME_NAME;
extern int SEND_NAME(void *queue, void *message, int flags);

void LEAF_NAME(u32 *task, u32 first, u32 second, u32 resourceIndex, u32 flags) {
    u32 index;

    task[4] = 1;
    task[7] = 0xD0;
    task[16] = first;
    task[17] = second;
    task[5] = 0;
    task[6] = 0x800022C0;
    task[8] = RESOURCE_PAIRS_NAME[resourceIndex][0];
    task[10] = RESOURCE_PAIRS_NAME[resourceIndex][1];
    task[11] = 0x800;
    task[12] = FIRST_BUFFER_NAME;
    task[13] = 0x400;
    task[14] = SECOND_BUFFER_NAME;
    task[15] = SECOND_BUFFER_NAME + 0x14000;
    task[18] = OUTPUT_BUFFER_NAME;
    task[19] = 0xC00;
    task[0] = 0;
    task[20] = (u32)&MESSAGE_QUEUE_NAME;
    task[2] = flags;
    if (flags & 0x40) {
        task[21] = (u32)&FIRST_SIGNAL_NAME;
    } else {
        task[21] = (u32)&SECOND_SIGNAL_NAME;
    }

    SEND_NAME(QUEUE_NAME, task, 1);
    index = INDEX_NAME;
    task[3] = MESSAGE_TABLE_NAME[index];
    if (flags & 0x40) {
        index++;
        INDEX_NAME = index;
        if (index >= INDEX_LIMIT_NAME) {
            INDEX_NAME = 0;
        }
    }
    FRAME_NAME = (FRAME_NAME + 1) & 1;
}
