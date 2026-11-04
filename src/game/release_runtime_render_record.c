#ifndef LEAF_NAME
#define LEAF_NAME releaseRuntimeRenderRecord
#endif
#ifndef WRITEBACK_NAME
#define WRITEBACK_NAME writebackCache
#endif
#ifndef RECEIVE_NAME
#define RECEIVE_NAME receiveMessage
#endif
#ifndef RELEASE_RESOURCE_NAME
#define RELEASE_RESOURCE_NAME releaseRenderResources
#endif
#ifndef RELEASE_HANDLE_NAME
#define RELEASE_HANDLE_NAME releaseHandle
#endif

typedef signed short s16;
typedef unsigned int u32;

typedef struct {
    s16 type;
} RenderMessage;

typedef struct {
    u32 type;
    void *object;
    u32 unused08;
    void *secondHandle;
    void *thirdHandle;
} RuntimeRenderRecord;

extern u32 pendingRenderMessages __asm__("D_800661D4");
extern unsigned char renderMessageQueue[] __asm__("D_800392F8");
extern u32 runtimeRenderRecordCount __asm__("D_8005AC7C");
extern RuntimeRenderRecord runtimeRenderRecords[] __asm__("D_8005ACD0");
extern void *memoryContext __asm__("D_8005A9E8");

extern void WRITEBACK_NAME(void);
extern int RECEIVE_NAME(void *queue, RenderMessage **message, int flags);
extern void RELEASE_RESOURCE_NAME(void *object, u32 releaseRecord);
extern void RELEASE_HANDLE_NAME(void *context, void **handle);

void LEAF_NAME(void *object, u32 releaseRecord)
{
    RenderMessage *message = 0;
    u32 index;

    WRITEBACK_NAME();
    while (pendingRenderMessages != 0) {
        if (RECEIVE_NAME(renderMessageQueue, &message, 0) == 0 &&
            message->type != 1 && message->type == 2) {
            pendingRenderMessages--;
        }
    }
    WRITEBACK_NAME();

    for (index = 0; index < runtimeRenderRecordCount; index++) {
        RuntimeRenderRecord *record = &runtimeRenderRecords[index];

        if (record->object == object) {
            if (record->type != 60) {
                break;
            }
            RELEASE_RESOURCE_NAME(record->object, releaseRecord);
            if (record->object != 0) {
                RELEASE_HANDLE_NAME(memoryContext, &record->object);
            }
            if (record->secondHandle != 0) {
                RELEASE_HANDLE_NAME(memoryContext, &record->secondHandle);
            }
            if (record->thirdHandle != 0) {
                RELEASE_HANDLE_NAME(memoryContext, &record->thirdHandle);
            }
            break;
        }
    }
}
