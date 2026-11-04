#ifndef LEAF_NAME
#define LEAF_NAME createRenderRecord
#endif
#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocateRuntimeMemory
#endif
#ifndef CLEAR_NAME
#define CLEAR_NAME clearRuntimeMemory
#endif

typedef signed int s32;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    s32 lifetime;
    void *record;
    s32 active;
    void *owner;
    void *link;
} RenderSlot;

typedef struct {
    u32 kind;
    u8 padding04[0x1C];
    s32 initialValue;
    u8 padding24[0x2C];
    void *elements;
    void *indices;
    s32 field5C;
    s32 field60;
    u32 count;
    u8 padding68[4];
    s32 field6C;
    u16 field70;
    u16 field72;
    u16 field74;
    u16 field76;
} RenderRecord;

extern void *runtimeAllocator __asm__("D_8005A9E8");
extern RenderSlot renderSlots[] __asm__("D_8005ACD0");
extern s32 renderSlotCount __asm__("D_8005AC7C");

extern void ALLOCATE_NAME(void *allocator, void **output, u32 size,
                          const char *source);
extern void CLEAR_NAME(void *destination, s32 value, u32 size);

s32 LEAF_NAME(u16 kind, const u16 *count, RenderRecord **output,
              s16 initialValue)
{
    RenderRecord *record = 0;
    void *elements = 0;
    RenderSlot *slot;
    u32 elementCount;

    if (kind != 1) {
        for (;;) {
        }
    }

    ALLOCATE_NAME(runtimeAllocator, (void **)&record, 0x7C,
                  (const char *)0x80000AD4);
    if (record == 0) {
        return -1000;
    }

    record->kind = 2;
    elementCount = *count;
    ALLOCATE_NAME(runtimeAllocator, &elements, elementCount * 36,
                  (const char *)0x80000AD4);
    if (elements == 0) {
        return -1000;
    }

    slot = &renderSlots[renderSlotCount];
    slot->active = 1;
    slot->owner = 0;
    slot->link = 0;
    ALLOCATE_NAME(runtimeAllocator, &slot->owner, 4,
                  (const char *)0x80000ADC);
    ALLOCATE_NAME(runtimeAllocator, &slot->link, 4,
                  (const char *)0x80000ADC);
    slot->record = record;
    *(RenderRecord **)slot->owner = record;
    slot->lifetime = 60;
    renderSlotCount++;

    CLEAR_NAME(elements, 0, elementCount * 36);
    record->elements = elements;
    record->initialValue = initialValue;
    record->indices = 0;
    record->field5C = 0;
    ALLOCATE_NAME(runtimeAllocator, &record->indices, elementCount * 16,
                  (const char *)0x80000AD4);
    if (record->indices == 0) {
        return -1000;
    }
    ALLOCATE_NAME(runtimeAllocator, (void **)&record->field5C,
                  elementCount * 16, (const char *)0x80000AD4);
    if (record->field5C == 0) {
        return -1000;
    }

    record->field60 = 0;
    record->count = elementCount;
    record->field6C = 0;
    record->field70 = 0xFFFF;
    record->field74 = 3;
    record->field76 = 3;
    *output = record;
    return 0;
}
