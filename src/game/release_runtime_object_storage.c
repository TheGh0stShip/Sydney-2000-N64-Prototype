#ifndef LEAF_NAME
#define LEAF_NAME releaseRuntimeObjectStorage
#endif
#ifndef WRITEBACK_NAME
#define WRITEBACK_NAME writebackDataCache
#endif
#ifndef RECEIVE_NAME
#define RECEIVE_NAME receiveMessage
#endif
#ifndef UNLINK_NAME
#define UNLINK_NAME unlinkIndexedResourceRecord
#endif
#ifndef RELEASE_NAME
#define RELEASE_NAME releaseHandle
#endif

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 handleCount;
    unsigned char padding02[2];
    void *firstHandle;
    void *secondHandle;
    void *thirdHandle;
    void *fourthHandle;
    unsigned char padding14[2];
    u16 flags;
    unsigned char padding18[0x2C];
    void *handles[1];
} RuntimeStorage;

typedef struct {
    u32 type;
    RuntimeStorage *object;
    u32 active;
    RuntimeStorage **objectAddress;
    void *extraHandle;
} RuntimeStorageRecord;

extern u32 pendingControllerMessages __asm__("D_800661D4");
extern unsigned char controllerQueue[] __asm__("D_800392F8");
extern void *memoryContext __asm__("D_8005A9E8");
extern u32 runtimeStorageRecordCount __asm__("D_8005AC7C");
extern RuntimeStorageRecord runtimeStorageRecords[] __asm__("D_8005ACD0");

extern void WRITEBACK_NAME(void);
extern int RECEIVE_NAME(void *, void **, int);
extern void UNLINK_NAME(RuntimeStorage *);
extern void RELEASE_NAME(void *, void **);

void LEAF_NAME(RuntimeStorage *target)
{
    u32 index;
    void *message = 0;

    WRITEBACK_NAME();
    while (pendingControllerMessages != 0) {
        if (RECEIVE_NAME(controllerQueue, &message, 0) == 0) {
            short type = *(short *)message;
            if (type != 1 && type == 2) {
                pendingControllerMessages--;
            }
        }
    }
    WRITEBACK_NAME();

    for (index = 0; index < runtimeStorageRecordCount; index++) {
        RuntimeStorageRecord *record = &runtimeStorageRecords[index];
        RuntimeStorage *storage;
        u32 handleIndex;

        if (record->type != 90 || record->object == 0 ||
            *record->objectAddress != target) {
            continue;
        }
        storage = target;
        UNLINK_NAME(storage);
        for (handleIndex = 0; handleIndex < storage->handleCount; handleIndex++) {
            if (storage->handles[handleIndex] != 0) {
                RELEASE_NAME(memoryContext, &storage->handles[handleIndex]);
            }
        }
        if ((storage->flags & 1) && storage->firstHandle != 0) {
            RELEASE_NAME(memoryContext, &storage->firstHandle);
        }
        if ((storage->flags & 2) && storage->secondHandle != 0) {
            RELEASE_NAME(memoryContext, &storage->secondHandle);
        }
        if (storage->flags & 0x10) {
            if (storage->thirdHandle != 0) {
                RELEASE_NAME(memoryContext, &storage->thirdHandle);
            }
            if (storage->fourthHandle != 0) {
                RELEASE_NAME(memoryContext, &storage->fourthHandle);
            }
        }
        RELEASE_NAME(memoryContext, (void **)&record->objectAddress);
        if (record->extraHandle != 0) {
            RELEASE_NAME(memoryContext, &record->extraHandle);
        }
        RELEASE_NAME(memoryContext, (void **)&record->object);
        break;
    }
}
