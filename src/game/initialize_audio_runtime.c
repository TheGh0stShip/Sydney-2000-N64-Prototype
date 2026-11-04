#ifndef LEAF_NAME
#define LEAF_NAME initializeAudioRuntime
#endif

#ifndef GET_TIME_NAME
#define GET_TIME_NAME getTime
#endif

typedef signed int s32;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct AudioRuntimeRecord {
    u32 value;
    u32 remaining[8];
} AudioRuntimeRecord;

extern u64 GET_TIME_NAME(void);
extern volatile u32 audioRuntimeEnabled;
extern volatile u32 audioRuntimeState;
extern volatile u32 audioRuntimePending;
extern volatile u64 audioRuntimeTime;
extern volatile u32 audioRuntimeCurrent;
extern volatile u32 audioRuntimeReady;
extern volatile u32 audioRuntimeCount;
extern AudioRuntimeRecord audioRuntimeRecords[10];
extern volatile u32 audioRuntimeTail;
extern volatile u32 audioRuntimeLimit;

void LEAF_NAME(void) {
    register u32 enabled __asm__("$16") = 1;
    AudioRuntimeRecord *record;
    s32 index;

    audioRuntimeEnabled = enabled;
    audioRuntimeState = 0;
    audioRuntimePending = 0;
    audioRuntimeTime = GET_TIME_NAME();
    audioRuntimeCurrent = 0;
    audioRuntimeReady = enabled;
    audioRuntimeCount = 0;

    record = &audioRuntimeRecords[9];
    for (index = 9; index >= 0; index--) {
        record->value = 0;
        record--;
    }

    audioRuntimeTail = 0;
    audioRuntimeLimit = 0;
}
