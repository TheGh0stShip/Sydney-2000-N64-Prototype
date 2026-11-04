#ifndef LEAF_NAME
#define LEAF_NAME createRuntimeRenderRecord
#endif
#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocateHandle
#endif
#ifndef FIND_NAME
#define FIND_NAME findRenderRecord
#endif

typedef signed int s32;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u32 size;
    u8 padding04[0x34];
    float width;
    float height;
    u8 padding40[0x30];
    u16 recordType;
    u8 padding72[10];
} RuntimeRenderObject;

typedef struct {
    u32 type;
    RuntimeRenderObject *object;
    u32 active;
    RuntimeRenderObject **objectAddress;
    void *thirdHandle;
} RuntimeRenderRecord;

extern void *memoryContext __asm__("D_8005A9E8");
extern u32 videoMode __asm__("D_8005A83C");
extern RuntimeRenderRecord runtimeRenderRecords[] __asm__("D_8005ACD0");
extern u32 runtimeRenderRecordCount __asm__("D_8005AC7C");
extern char renderObjectTag[] __asm__("D_80000C50");
extern char renderAddressTag[] __asm__("D_80000ADC");
extern float compactDisplayScale __asm__("D_80000C58");

extern void ALLOCATE_NAME(void *context, void **output, u32 size, char *tag);
extern u32 FIND_NAME(u16 type, u32 first, u32 second, u32 third, u32 fourth);

s32 LEAF_NAME(RuntimeRenderObject **output, float width, float height, u32 type)
{
    RuntimeRenderObject *object;
    RuntimeRenderRecord *record;

    ALLOCATE_NAME(memoryContext, (void **)output, 124, renderObjectTag);
    object = *output;
    if (object == 0) {
        return -1000;
    }

    object->size = 64;
    object->recordType = FIND_NAME((u16)type, 0, 0, 0, 0);
    if (videoMode == 1) {
        object->width = width * compactDisplayScale;
        object->height = height * compactDisplayScale;
    } else {
        object->width = width;
        object->height = height;
    }

    record = &runtimeRenderRecords[runtimeRenderRecordCount];
    record->active = 1;
    record->objectAddress = 0;
    record->thirdHandle = 0;
    ALLOCATE_NAME(memoryContext, (void **)&record->objectAddress,
                  sizeof(RuntimeRenderObject *), renderAddressTag);
    record->object = object;
    *record->objectAddress = object;
    record->type = 60;
    runtimeRenderRecordCount++;
    return 0;
}
