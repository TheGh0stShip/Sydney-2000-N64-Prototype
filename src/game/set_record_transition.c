#ifndef LEAF_NAME
#define LEAF_NAME setRecordTransition
#endif

#ifndef RECORDS_NAME
#define RECORDS_NAME records
#endif

typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;

typedef struct TransitionRecord {
    u8 padding00[0x18];
    s32 currentValue;
    u8 padding1C[0x1C];
    u8 mode;
    u8 padding39;
    s16 duration;
    s32 step;
} TransitionRecord;

extern TransitionRecord RECORDS_NAME[];

void LEAF_NAME(void *unused, s32 index, s32 targetValue, s32 duration, s32 mode) {
    TransitionRecord *record;
    s16 signedDuration;

    if (index >= 0) {
        record = &RECORDS_NAME[index];
        signedDuration = (s16)duration;
        record->duration = duration;
        record->mode = mode;
        record->step = (targetValue - record->currentValue) / signedDuration;
    }
}
