#ifndef LEAF_NAME
#define LEAF_NAME queueAudioRuntimeRecords
#endif

typedef signed int s32;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct AudioRuntimeInput {
    u32 value;
    u32 secondary;
    u8 pad08[4];
    u32 limit;
    u8 pad10[8];
} AudioRuntimeInput;

typedef struct AudioRuntimeRecord {
    u32 state;
    u32 request;
    u32 value;
    u32 secondary;
    u32 start;
    u32 end;
    u32 current;
    u32 sequence;
    u32 limit;
} AudioRuntimeRecord;

extern AudioRuntimeRecord audioRuntimeRecords[10];
extern u32 audioRuntimeRequest;
extern u32 audioRuntimeCurrent;
extern u32 audioRuntimeSequence;

s32 LEAF_NAME(void *unused, AudioRuntimeInput *inputs, s32 count,
              u32 start, u32 end)
{
    AudioRuntimeRecord *record;
    s32 allocated;
    s32 inputIndex;
    s32 recordIndex;
    u32 request;

    (void)unused;
    request = ++audioRuntimeRequest;
    allocated = 0;

    for (inputIndex = 0; inputIndex < count; inputIndex++, inputs++) {
        record = audioRuntimeRecords;
        for (recordIndex = 0; recordIndex < 10; recordIndex++, record++) {
            if (record->state == 0) {
                break;
            }
        }
        if (recordIndex >= 10 || record->state != 0) {
            continue;
        }

        record->request = request;
        record->value = inputs->value;
        record->secondary = inputs->secondary;
        record->start = start;
        record->end = end;
        record->current = audioRuntimeCurrent;
        record->sequence = audioRuntimeSequence++;
        record->limit = inputs->limit;
        record->state = 2;
        if (start != 0) {
            record->start += audioRuntimeCurrent;
        }
        allocated++;
        if (end != 0) {
            record->end += audioRuntimeCurrent;
        }
    }

    if (allocated == count) {
        return request;
    }
    return -1;
}
