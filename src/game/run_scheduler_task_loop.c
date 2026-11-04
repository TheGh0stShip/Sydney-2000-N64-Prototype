#ifndef LEAF_NAME
#define LEAF_NAME runSchedulerTaskLoop
#endif

#ifndef PROCESS_NAME
#define PROCESS_NAME processSchedulerMessage
#endif

#ifndef RECEIVE_NAME
#define RECEIVE_NAME receiveMessage
#endif

#ifndef LOAD_TASK_NAME
#define LOAD_TASK_NAME loadTask
#endif

#ifndef START_TASK_NAME
#define START_TASK_NAME startTask
#endif

#ifndef SET_BLACK_NAME
#define SET_BLACK_NAME setBlack
#endif

#ifndef SWAP_BUFFER_NAME
#define SWAP_BUFFER_NAME swapBuffer
#endif

#ifndef SEND_NAME
#define SEND_NAME sendMessage
#endif

typedef unsigned int u32;
typedef unsigned char u8;

extern u32 shutdownActive;

extern void PROCESS_NAME(void *scheduler, void *message);
extern void RECEIVE_NAME(void *queue, void **message, u32 flags);
extern void LOAD_TASK_NAME(void *task);
extern void START_TASK_NAME(void *task);
extern void SET_BLACK_NAME(u32 active);
extern void SWAP_BUFFER_NAME(void *buffer);
extern void SEND_NAME(void *queue, void *message, u32 flags);

void LEAF_NAME(void *argument) {
    u8 *scheduler = argument;
    void *message;
    void *reply = 0;

    for (;;) {
        RECEIVE_NAME(scheduler + 0x3c, &message, 1);

        if (shutdownActive == 0) {
            PROCESS_NAME(scheduler, message);

            if (*(void **)(scheduler + 0x670) != 0) {
                *(void **)(scheduler + 0x674) = message;
                RECEIVE_NAME(scheduler + 0x11c, &reply, 1);
                *(void **)(scheduler + 0x674) = 0;
            }

            *(void **)(scheduler + 0x66c) = message;
            LOAD_TASK_NAME((u8 *)message + 0x10);
            START_TASK_NAME((u8 *)message + 0x10);
            RECEIVE_NAME(scheduler + 0xac, &reply, 1);
            *(void **)(scheduler + 0x66c) = 0;
            RECEIVE_NAME(scheduler + 0xe4, &reply, 1);

            if (*(u32 *)(scheduler + 0x678) != 0) {
                SET_BLACK_NAME(0);
                *(u32 *)(scheduler + 0x678) = 0;
            }

            if ((*(u32 *)((u8 *)message + 8) & 0x40) != 0) {
                SWAP_BUFFER_NAME(*(void * volatile *)((u8 *)message + 0xc));
            }
        }

        SEND_NAME(*(void **)((u8 *)message + 0x50),
                  *(void **)((u8 *)message + 0x54), 1);
    }
}
