#ifndef LEAF_NAME
#define LEAF_NAME allocateAudioRecord
#endif

#ifndef RECORDS_NAME
#define RECORDS_NAME audioRecords
#endif

#ifndef LOCK_NAME
#define LOCK_NAME audioRecordLock
#endif

typedef signed int s32;
typedef unsigned int u32;

typedef struct AudioRecord {
    u32 active;
    u32 enabled;
    u32 special;
    u32 initialized;
    u32 value;
    u32 volume;
    u32 limit;
    u32 elapsed;
    u32 specialValue;
    u32 index;
    u32 counter;
    u32 owner;
    u32 state;
    u32 reserved;
    u32 padding[2];
} AudioRecord;

extern AudioRecord RECORDS_NAME[20];
extern u32 LOCK_NAME;

s32 LEAF_NAME(void *unused, u32 value, void *unused2, u32 specialValue) {
    AudioRecord *record;
    s32 index;

    if (LOCK_NAME != 0) {
        return LOCK_NAME;
    }

    for (index = 0, record = RECORDS_NAME; index < 20; index++, record++) {
        if (record->active == 0 && record->owner == 0) {
            record->active = 1;
            record->initialized = 1;
            record->value = value;
            record->special = 0;
            record->specialValue = 0;
            record->enabled = 1;
            record->limit = 32767;
            record->elapsed = 0;
            record->volume = 128;
            record->counter = 0;
            record->state = 0;
            if (specialValue != 0) {
                record->special = 1;
                record->specialValue = specialValue;
            }
            record->reserved = 0;
            record->index = index;
            return index;
        }
    }
    return 0;
}
