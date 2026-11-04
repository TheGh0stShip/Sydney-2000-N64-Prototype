#ifndef LEAF_NAME
#define LEAF_NAME runPiWorkerStartup
#endif
#ifndef GET_TIME_NAME
#define GET_TIME_NAME getTime
#endif
#ifndef SET_SEED_NAME
#define SET_SEED_NAME setRandomSeed
#endif
#ifndef INITIALIZE_QUEUE_NAME
#define INITIALIZE_QUEUE_NAME initializeMessageQueue
#endif
#ifndef READ_NAME
#define READ_NAME readRom
#endif
#ifndef WRITEBACK_NAME
#define WRITEBACK_NAME writebackDataCache
#endif
#ifndef INVALIDATE_NAME
#define INVALIDATE_NAME invalidateInstructionCache
#endif
#ifndef CALL_RANGE_NAME
#define CALL_RANGE_NAME callFunctionRange
#endif
#ifndef INITIALIZE_SCHEDULER_NAME
#define INITIALIZE_SCHEDULER_NAME initializeScheduler
#endif
#ifndef INITIALIZE_STATE_NAME
#define INITIALIZE_STATE_NAME initializeGlobalState
#endif
#ifndef FINISH_NAME
#define FINISH_NAME finishStartup
#endif
#ifndef ROM_CURSOR_NAME
#define ROM_CURSOR_NAME romCursor
#endif
#ifndef SCHEDULER_NAME
#define SCHEDULER_NAME scheduler
#endif

typedef unsigned int u32;
typedef unsigned long long u64;

extern u32 ROM_CURSOR_NAME;
extern unsigned char SCHEDULER_NAME[];
extern u64 GET_TIME_NAME(void);
extern void SET_SEED_NAME(u32 seed);
extern void INITIALIZE_QUEUE_NAME(void);
extern void READ_NAME(u32 rom, void *destination, u32 size);
extern void WRITEBACK_NAME(void);
extern void INVALIDATE_NAME(void *address, u32 size);
extern void CALL_RANGE_NAME(void *start, void *end);
extern void INITIALIZE_SCHEDULER_NAME(void *scheduler, u32 argument, u32 flags);
extern void INITIALIZE_STATE_NAME(u32 argument);
extern void FINISH_NAME(void);

void LEAF_NAME(void) {
    u32 address;
    u32 destination;
    u32 size;

    SET_SEED_NAME((u32)GET_TIME_NAME());
    INITIALIZE_QUEUE_NAME();

    address = 0x80083D5F;
    destination = (address >> 4) << 4;
    size = 0x801001C0 - (address - 15);
    ROM_CURSOR_NAME = 0xB0127640;
    READ_NAME(0xB0127640, (void *)destination, size);
    WRITEBACK_NAME();
    INVALIDATE_NAME((void *)destination, size);
    CALL_RANGE_NAME((void *)0x800022A0, (void *)0x800022B0);
    CALL_RANGE_NAME((void *)0x8008CC50, (void *)0x8008CCA4);
    INITIALIZE_SCHEDULER_NAME(SCHEDULER_NAME, 0, 1);
    INITIALIZE_STATE_NAME(0);
    FINISH_NAME();
}
