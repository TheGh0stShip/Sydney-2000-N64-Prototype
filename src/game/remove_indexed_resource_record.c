#ifndef LEAF_NAME
#define LEAF_NAME removeIndexedResourceRecord
#endif
#ifndef RELEASE_NAME
#define RELEASE_NAME releaseHandle
#endif

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 key;
    u16 resourceIds[64];
} IndexedRecord;

typedef struct {
    u32 state;
    u32 secondary;
    u16 references;
    unsigned char padding0A[0xCE];
    void *handle;
} ResourceSlot;

extern u32 indexedRecordCount __asm__("D_800479C8");
extern IndexedRecord indexedRecords[] __asm__("D_800456C0");
extern ResourceSlot resourceSlots[] __asm__("D_80049A28");
extern void *memoryContext __asm__("D_800F2758");

extern void RELEASE_NAME(void *context, void **handle);

void LEAF_NAME(u32 key)
{
    u32 index;

    if (indexedRecordCount == 0) {
        return;
    }

    for (index = 0; index < indexedRecordCount; index++) {
        IndexedRecord *record = &indexedRecords[index];
        u16 *resourceId;

        if (record->key != key) {
            continue;
        }

        resourceId = record->resourceIds;
        while (*resourceId != 0xFFFF) {
            ResourceSlot *slot = &resourceSlots[*resourceId];
            slot->references--;
            if (slot->references == 0) {
                slot->state = 0xFFFE;
                slot->secondary = 0;
                if (slot->handle != 0) {
                    RELEASE_NAME(memoryContext, &slot->handle);
                }
            }
            resourceId++;
        }

        if (index < indexedRecordCount - 1) {
            u32 moveIndex;
            for (moveIndex = index; moveIndex < indexedRecordCount - 1;
                 moveIndex++) {
                indexedRecords[moveIndex] = indexedRecords[moveIndex + 1];
            }
        }
        indexedRecordCount--;
        return;
    }
}
