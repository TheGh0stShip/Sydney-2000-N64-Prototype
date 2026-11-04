#ifndef LEAF_NAME
#define LEAF_NAME loadSpecialRecord
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
#ifndef RESIZE_NAME
#define RESIZE_NAME resizeHandle
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

typedef struct {
    u32 signature;
    u32 outputSize;
    u32 workSize;
    u32 extraSize;
} PackedHeader;

extern ResourceRecord *resourceRecords __asm__("D_80043674");
extern ResourceRecord currentResourceRecord __asm__("D_800436C0");
extern u32 resourceBase __asm__("D_80043684");
extern void *memoryContext __asm__("D_800F2758");
extern char headerTag[] __asm__("D_800004D4");
extern char packedTag[] __asm__("D_800004E8");

extern void COPY_NAME(u32 source, void *destination, u32 size);
extern void READ_NAME(u32 source, void *destination, u32 size);
extern void ALLOCATE_NAME(void *context, void **output, u32 size, char *tag);
extern void RELEASE_NAME(void *context, void **handle);
extern void RESIZE_NAME(void *context, void **handle, u32 size);
extern void DECODE_NAME(void *source, void *destination);

s32 LEAF_NAME(void *unused, s32 index, void **output)
{
    PackedHeader header;
    PackedHeader *allocatedHeader;
    void *allocation;
    u32 source;
    u32 signature;

    u32 packedOffset;

    (void)unused;
    if (index < 0) {
        return 0;
    }

    COPY_NAME((u32)&resourceRecords[index] + 4, &currentResourceRecord, 76);
    source = resourceBase + currentResourceRecord.offset;
    COPY_NAME(source, &signature, 4);
    if (signature != 0x30325447) {
        return 0;
    }

    allocatedHeader = 0;
    ALLOCATE_NAME(memoryContext, (void **)&allocatedHeader, 16, headerTag);
    COPY_NAME(source, allocatedHeader, 16);
    header = *allocatedHeader;
    RELEASE_NAME(memoryContext, (void **)&allocatedHeader);

    allocation = 0;
    packedOffset = (header.outputSize - currentResourceRecord.size + 3 +
                    header.workSize + header.extraSize + 63) & ~63;
    ALLOCATE_NAME(memoryContext, &allocation,
                  header.outputSize + header.workSize + header.extraSize + 67,
                  packedTag);
    READ_NAME(source, (u8 *)allocation + packedOffset, currentResourceRecord.size);
    DECODE_NAME((u8 *)allocation + packedOffset, allocation);
    RESIZE_NAME(memoryContext, &allocation, header.outputSize);
    *output = allocation;
    return 1;
}
