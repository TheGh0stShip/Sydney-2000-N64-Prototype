#ifndef LEAF_NAME
#define LEAF_NAME updateIndexedRenderRecord
#endif
#ifndef FIRST_PREPARE_NAME
#define FIRST_PREPARE_NAME prepareIndexedRenderRecord
#endif
#ifndef SECOND_PREPARE_NAME
#define SECOND_PREPARE_NAME prepareIndexedRenderValues
#endif

typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;

typedef struct {
    u32 index;
    u32 object;
    u16 padding08;
    u16 firstPairSecond;
    u16 secondPairFirst;
    u16 secondPairSecond;
    float firstScale;
    float secondScale;
    u32 firstValue;
    u32 secondValue;
} IndexedRenderUpdate;

typedef struct {
    u32 active;
    u32 padding04;
    u32 object;
    u16 firstPairFirst;
    u16 firstPairSecond;
    u16 secondPairFirst;
    u16 secondPairSecond;
    float firstScale;
    float secondScale;
    u32 firstValue;
    u32 secondValue;
    u32 padding24[23];
    u32 updateFlags;
} IndexedRenderRecord;

extern IndexedRenderRecord renderRecords[] __asm__("D_8005AAF0");
extern void FIRST_PREPARE_NAME(void);
extern void SECOND_PREPARE_NAME(float first, float second, u32 third);

s32 LEAF_NAME(IndexedRenderUpdate *update, u32 flags)
{
    IndexedRenderRecord *records;

    FIRST_PREPARE_NAME();
    SECOND_PREPARE_NAME(0.0f, 0.0f, 0);

    if (update->index >= 3) {
        return -998;
    }
    records = renderRecords;
    if (records[update->index].active == 0) {
        return -998;
    }

    if (flags & 1) {
        records[update->index].firstPairFirst = update->padding08;
        records[update->index].firstPairSecond = update->firstPairSecond;
    }
    if (flags & 2) {
        records[update->index].secondPairFirst = update->secondPairFirst;
        records[update->index].secondPairSecond = update->secondPairSecond;
    }
    if (flags & 4) {
        records[update->index].firstValue = update->firstValue;
    }
    if (flags & 8) {
        records[update->index].secondValue = update->secondValue;
    }
    if (flags & 16) {
        records[update->index].firstScale = update->firstScale;
        records[update->index].secondScale = update->secondScale;
    }
    if (flags & 32) {
        records[update->index].object = update->object;
    }
    records[update->index].updateFlags = flags;
    return 0;
}
