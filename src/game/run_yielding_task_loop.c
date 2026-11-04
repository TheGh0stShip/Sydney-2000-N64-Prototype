#ifndef LEAF_NAME
#define LEAF_NAME runYieldingTaskLoop
#endif

#ifndef RECEIVE_NAME
#define RECEIVE_NAME receiveMessage
#endif
#ifndef WRITEBACK_NAME
#define WRITEBACK_NAME writebackCache
#endif
#ifndef YIELD_NAME
#define YIELD_NAME yieldTask
#endif
#ifndef YIELDED_NAME
#define YIELDED_NAME taskYielded
#endif
#ifndef LOAD_NAME
#define LOAD_NAME loadTask
#endif
#ifndef START_NAME
#define START_NAME startTask
#endif
#ifndef SEND_NAME
#define SEND_NAME sendMessage
#endif
#ifndef BLOCKED_NAME
#define BLOCKED_NAME schedulerTaskBlocked
#endif

typedef unsigned int u32;
typedef unsigned char u8;

extern u32 BLOCKED_NAME;
extern void RECEIVE_NAME(void *queue, void **message, u32 flags);
extern void WRITEBACK_NAME(void);
extern void YIELD_NAME(void);
extern u32 YIELDED_NAME(void *task);
extern void LOAD_NAME(void *task);
extern void START_NAME(void *task);
extern void SEND_NAME(void *queue, void *message, u32 flags);

void LEAF_NAME(void *argument)
{
    register u8 *scheduler __asm__("$18") = argument;
    void *messages[2] = {0, 0};
    register void **replyAddress __asm__("$19") = &messages[1];
    register u8 *yieldQueue __asm__("$20") = scheduler + 0xac;
    register void *previous __asm__("$17");
    register u32 yieldState __asm__("$16");

    for (;;) {
        RECEIVE_NAME(scheduler + 4, &messages[0], 1);
        WRITEBACK_NAME();

        if (BLOCKED_NAME == 0) {
            previous = *(void **)(scheduler + 0x66c);
            yieldState = 0;
            if (previous != 0) {
                yieldState = 2;
                YIELD_NAME();
                RECEIVE_NAME(scheduler + 0xac, replyAddress, 1);
                if (YIELDED_NAME((u8 *)previous + 0x10) != 0) {
                    yieldState = 1;
                }
            }

            *(void **)(scheduler + 0x670) = messages[0];
            LOAD_NAME((u8 *)messages[0] + 0x10);
            START_NAME((u8 *)messages[0] + 0x10);
            RECEIVE_NAME(yieldQueue, replyAddress, 1);
            *(void **)(scheduler + 0x670) = 0;

            if (*(void **)(scheduler + 0x674) != 0) {
                SEND_NAME(scheduler + 0x11c, replyAddress, 1);
            }

            if (yieldState == 1) {
                previous = (u8 *)previous + 0x10;
                LOAD_NAME(previous);
                START_NAME(previous);
            } else if (yieldState == 2) {
                SEND_NAME(yieldQueue, replyAddress, 1);
            }
        }

        SEND_NAME(*(void **)((u8 *)messages[0] + 0x50),
                  *(void **)((u8 *)messages[0] + 0x54), 1);
    }
}
