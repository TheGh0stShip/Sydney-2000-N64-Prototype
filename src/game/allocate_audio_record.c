#ifndef LEAF_NAME
#define LEAF_NAME allocateAudioRecord
#endif

#ifndef RECORDS_NAME
#define RECORDS_NAME audioRecords
#endif

#ifndef LOCK_NAME
#define LOCK_NAME audioRecordLock
#endif

#include "audio_record.h"

typedef signed int s32;
typedef unsigned int u32;

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
            record->handle = 0;
            record->index = index;
            return index;
        }
    }
    return 0;
}
