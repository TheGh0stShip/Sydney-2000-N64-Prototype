#ifndef LEAF_NAME
#define LEAF_NAME dispatchEarlyMemoryTransfer
#endif
#ifndef READ_WORD_NAME
#define READ_WORD_NAME readDebugWord
#endif
#ifndef FILL_NAME
#define FILL_NAME fillDebugMemory
#endif
#ifndef COPY_NAME
#define COPY_NAME copyDebugMemory
#endif
#ifndef WRITE_BYTES_NAME
#define WRITE_BYTES_NAME writeDebugBytes
#endif
#ifndef READ_BYTES_NAME
#define READ_BYTES_NAME readDebugBytes
#endif
#ifndef READ_BUFFER_NAME
#define READ_BUFFER_NAME readDebugBuffer
#endif

typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u32 lowerBound;
    u32 upperBound;
    u32 flags;
} MemoryRegion;

extern char mappedMemoryBase[] __asm__("D_8007D080");
extern MemoryRegion memoryRegions[] __asm__("D_8006CC50");
extern u32 READ_WORD_NAME(u32 address);
extern void FILL_NAME(u32 destination, u32 value, u32 size);
extern void COPY_NAME(u32 destination, u32 source, u32 size);
extern void WRITE_BYTES_NAME(u32 destination, u32 source, u32 size);
extern void READ_BYTES_NAME(u32 destination, u32 source, u32 size);
extern void READ_BUFFER_NAME(u32 destination, u32 source, u32 size);

void LEAF_NAME(u32 direction)
{
    u32 destination = 0xB1FE0000;
    u32 address = READ_WORD_NAME(0xB1FFFFF4);
    u32 length = READ_WORD_NAME(0xB1FFFFF8);
    u32 amount;
    u32 flags;
    s32 i;

    if (address > 0xEFFFFFFF) {
        address += (u32)mappedMemoryBase - 0xF1000000;
    }
    while (length != 0) {
        for (i = 0;
             address < memoryRegions[i].lowerBound ||
             memoryRegions[i].upperBound < address;
             i++) {
        }
        amount = memoryRegions[i].upperBound + 1 - address;
        if (length < amount) {
            amount = length;
        }
        flags = memoryRegions[i].flags;
        if ((flags & direction) == 0) {
            if (direction == 1) {
                FILL_NAME(destination, 0, amount);
            }
        } else if ((flags & 4) != 0) {
            if (direction == 1) {
                COPY_NAME(destination, address, amount);
            } else {
                COPY_NAME(address, destination, amount);
            }
        } else if (direction == 1) {
            WRITE_BYTES_NAME(destination, address, amount);
        } else if ((flags & 8) != 0) {
            READ_BYTES_NAME(destination, address, amount);
        } else {
            READ_BUFFER_NAME(destination, address, amount);
        }
        destination += amount;
        length -= amount;
        address += amount;
    }
}
