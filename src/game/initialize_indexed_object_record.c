#ifndef LEAF_NAME
#define LEAF_NAME initializeIndexedObjectRecord
#endif

#ifndef COPY_NAME
#define COPY_NAME copyObjectRecord
#endif

#ifndef RECORDS_NAME
#define RECORDS_NAME objectRecords
#endif

typedef signed int s32;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 active;
    u8 data[108];
    u32 firstState;
    u32 secondState;
    u8 remainder[8];
    u32 color;
} ObjectRecord;

extern ObjectRecord RECORDS_NAME[3];
extern void COPY_NAME(void *destination, const void *source, u32 length);

s32 LEAF_NAME(const u32 *source) {
    u32 index = source[0];
    ObjectRecord *record;

    if (index >= 3) {
        return -998;
    }
    record = &RECORDS_NAME[index];
    COPY_NAME(record->data, source, 32);
    record->active = 1;
    record->firstState = 0;
    record->secondState = 0;
    record->color = 255;
    return 0;
}
