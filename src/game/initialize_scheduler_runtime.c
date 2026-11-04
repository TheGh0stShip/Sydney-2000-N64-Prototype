#ifndef LEAF_NAME
#define LEAF_NAME initializeSchedulerRuntime
#endif
#ifndef CREATE_QUEUE_NAME
#define CREATE_QUEUE_NAME createMessageQueue
#endif
#ifndef CREATE_THREAD_NAME
#define CREATE_THREAD_NAME createThread
#endif
#ifndef SET_EVENT_NAME
#define SET_EVENT_NAME setEventMessage
#endif
#ifndef START_THREAD_NAME
#define START_THREAD_NAME startThread
#endif
#ifndef CREATE_VI_NAME
#define CREATE_VI_NAME createViManager
#endif
#ifndef APPLY_MODE_NAME
#define APPLY_MODE_NAME applyVideoMode
#endif
#ifndef SET_BLACK_NAME
#define SET_BLACK_NAME setVideoBlack
#endif
#ifndef SET_VI_EVENT_NAME
#define SET_VI_EVENT_NAME setViEvent
#endif
#ifndef INITIALIZE_CONTROLLERS_NAME
#define INITIALIZE_CONTROLLERS_NAME initializeControllers
#endif

typedef unsigned int u32;
typedef unsigned char u8;

extern u8 runtimeQueue[] __asm__("D_80043B30");
extern u32 runtimeBusy __asm__("D_8004372C");
extern u8 videoMode[] __asm__("D_80067660");
extern u8 firstStack[] __asm__("D_8003F668");
extern u8 secondStack[] __asm__("D_80041668");
extern u8 thirdStack[] __asm__("D_80043668");

extern void CREATE_QUEUE_NAME(void *queue, void *messages, u32 count);
extern void CREATE_THREAD_NAME(void *thread, u32 id, void (*entry)(void *),
                               void *argument, void *stack, u32 priority);
extern void SET_EVENT_NAME(u32 event, void *queue, u32 message);
extern void START_THREAD_NAME(void *thread);
extern void CREATE_VI_NAME(u32 priority);
extern void APPLY_MODE_NAME(void *mode);
extern void SET_BLACK_NAME(u32 black);
extern void SET_VI_EVENT_NAME(void *queue, u32 message, u8 retraceCount);
extern void INITIALIZE_CONTROLLERS_NAME(u32 count);
extern void func_80006430(void *);
extern void func_80006348(void *);
extern void func_80005F60(void *);
extern void func_8000608C(void *);

void LEAF_NAME(u8 *scheduler, u32 unused, u32 retraceCount)
{
    (void)unused;
    runtimeBusy = 0;
    CREATE_QUEUE_NAME(runtimeQueue, runtimeQueue + 0x18, 8);
    CREATE_THREAD_NAME(runtimeQueue + 0x38, 16, func_80006430,
                       runtimeQueue, runtimeQueue, 127);
    SET_EVENT_NAME(14, runtimeQueue, 669);
    START_THREAD_NAME(runtimeQueue + 0x38);

    *(u32 *)(scheduler + 0x668) = 0;
    *(u32 *)(scheduler + 0x66C) = 0;
    *(u32 *)(scheduler + 0x670) = 0;
    *(u32 *)(scheduler + 0x674) = 0;
    *(u32 *)(scheduler + 0x678) = 1;
    *(unsigned short *)(scheduler + 0) = 1;
    *(unsigned short *)(scheduler + 2) = 3;
    CREATE_QUEUE_NAME(scheduler + 0x74, scheduler + 0x8C, 8);
    CREATE_QUEUE_NAME(scheduler + 0xAC, scheduler + 0xC4, 8);
    CREATE_QUEUE_NAME(scheduler + 0xE4, scheduler + 0xFC, 8);
    CREATE_QUEUE_NAME(scheduler + 0x3C, scheduler + 0x54, 8);
    CREATE_QUEUE_NAME(scheduler + 0x04, scheduler + 0x1C, 8);
    CREATE_QUEUE_NAME(scheduler + 0x11C, scheduler + 0x134, 8);

    CREATE_VI_NAME(254);
    APPLY_MODE_NAME(videoMode);
    SET_BLACK_NAME(1);
    SET_VI_EVENT_NAME(scheduler + 0x74, 666, (u8)retraceCount);
    SET_EVENT_NAME(4, scheduler + 0xAC, 667);
    SET_EVENT_NAME(9, scheduler + 0xE4, 668);

    CREATE_THREAD_NAME(scheduler + 0x158, 19, func_80006348,
                       scheduler, firstStack, 126);
    START_THREAD_NAME(scheduler + 0x158);
    CREATE_THREAD_NAME(scheduler + 0x308, 18, func_80005F60,
                       scheduler, secondStack, 110);
    START_THREAD_NAME(scheduler + 0x308);
    CREATE_THREAD_NAME(scheduler + 0x4B8, 17, func_8000608C,
                       scheduler, thirdStack, 105);
    START_THREAD_NAME(scheduler + 0x4B8);
    runtimeBusy = 1;
    INITIALIZE_CONTROLLERS_NAME(4);
    runtimeBusy = 0;
}
