#ifndef LEAF_NAME
#define LEAF_NAME finalizeRenderShutdown
#endif

#ifndef RESET_AUDIO_NAME
#define RESET_AUDIO_NAME resetAudio
#endif

#ifndef WRITEBACK_NAME
#define WRITEBACK_NAME writebackCache
#endif

#ifndef RECEIVE_NAME
#define RECEIVE_NAME receiveMessage
#endif

#ifndef RESET_RENDER_NAME
#define RESET_RENDER_NAME resetRender
#endif

#ifndef FINALIZE_NAME
#define FINALIZE_NAME finalizeRuntime
#endif

#ifndef SOURCE_STATE_NAME
#define SOURCE_STATE_NAME sourceState
#endif

#ifndef COPIED_STATE_NAME
#define COPIED_STATE_NAME copiedState
#endif

#ifndef TASK_COUNT_NAME
#define TASK_COUNT_NAME taskCount
#endif

#ifndef MESSAGE_QUEUE_NAME
#define MESSAGE_QUEUE_NAME messageQueue
#endif

#ifndef FRAME_COUNTER_NAME
#define FRAME_COUNTER_NAME frameCounter
#endif

#ifndef READY_NAME
#define READY_NAME ready
#endif

typedef unsigned int u32;
typedef unsigned char u8;
typedef signed short s16;

extern u32 SOURCE_STATE_NAME;
extern u32 COPIED_STATE_NAME;
extern u32 TASK_COUNT_NAME;
extern u32 FRAME_COUNTER_NAME;
extern u32 READY_NAME;
extern unsigned char MESSAGE_QUEUE_NAME[];

extern void RESET_AUDIO_NAME(void);
extern void WRITEBACK_NAME(void);
extern int RECEIVE_NAME(void *queue, void **message, u32 flags);
extern void RESET_RENDER_NAME(void);
extern void FINALIZE_NAME(void *argument);

int LEAF_NAME(void *argument) {
    void *message = 0;
    register void *finalizeArgument asm("$20") = argument;
    register u8 *queuePage asm("$19") = (u8 *)0x80040000;
    register int firstType asm("$18") = 1;
    register int secondType asm("$17") = 2;
    register volatile u32 *statePage asm("$16") =
        (volatile u32 *)0x80060000;

    COPIED_STATE_NAME = SOURCE_STATE_NAME;
    RESET_AUDIO_NAME();
    WRITEBACK_NAME();

    while (statePage[0x61d4 / 4] != 0) {
        s16 type;
        if (RECEIVE_NAME(queuePage - 0x6d08, &message, 0) != 0) {
            goto message_done;
        }
        type = *(s16 *)message;
        if (type == firstType) {
            goto message_done;
        }
        if (type != secondType) {
            goto message_done;
        }
        statePage[0x61d4 / 4]--;
message_done:
        ;
    }

    WRITEBACK_NAME();
    FRAME_COUNTER_NAME = 0;
    RESET_RENDER_NAME();
    READY_NAME = 1;
    FINALIZE_NAME(finalizeArgument);
    return 0;
}
