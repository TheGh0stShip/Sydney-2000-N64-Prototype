#ifndef LEAF_NAME
#define LEAF_NAME loadResourcePayload
#endif
#ifndef COPY_NAME
#define COPY_NAME copyRomBytes
#endif
#ifndef READ_NAME
#define READ_NAME readRomBytes
#endif
#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocateHandle
#endif
#ifndef RELEASE_NAME
#define RELEASE_NAME releaseHandle
#endif
#ifndef DECODE_NAME
#define DECODE_NAME decodeResource
#endif

typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u32 size;
    u32 offset;
    u8 padding08[68];
} ResourceRecord;

extern ResourceRecord *resourceRecords __asm__("D_80043674");
extern ResourceRecord currentResourceRecord __asm__("D_800436C0");
extern u32 resourceBase __asm__("D_80043684");
extern void *memoryContext __asm__("D_800F2758");
extern char headerTag[] __asm__("D_800004D4");
extern char payloadTag[] __asm__("D_800004D8");

extern void COPY_NAME(u32 source, void *destination, u32 size);
extern void READ_NAME(u32 source, void *destination, u32 size);
extern void ALLOCATE_NAME(void *context, void **output, u32 size, char *tag);
extern void RELEASE_NAME(void *context, void **handle);
extern void DECODE_NAME(void *source, void *destination);

s32 LEAF_NAME(void *unused, s32 index, void *output)
{
    u32 source;
    u32 signature;
    void *allocation;
    u8 header[16];

    (void)unused;
    if (index < 0) {
        return 0;
    }

    COPY_NAME((u32)&resourceRecords[index] + 4, &currentResourceRecord, 76);
    source = resourceBase + currentResourceRecord.offset;
    COPY_NAME(source, &signature, 4);
    if (signature != 0x30325447) {
        READ_NAME(source, output, currentResourceRecord.size);
        return 1;
    }

    allocation = 0;
    ALLOCATE_NAME(memoryContext, &allocation, 16, headerTag);
    COPY_NAME(source, allocation, 16);
    __builtin_memcpy(header, allocation, 16);
    RELEASE_NAME(memoryContext, &allocation);

    allocation = 0;
    ALLOCATE_NAME(memoryContext, &allocation, currentResourceRecord.size,
                  payloadTag);
    READ_NAME(source, allocation, currentResourceRecord.size);
    DECODE_NAME(allocation, output);
    RELEASE_NAME(memoryContext, &allocation);
    return 1;
}
