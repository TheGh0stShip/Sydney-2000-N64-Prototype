/* Reserve and clear a 64-byte-aligned payload from the runtime heap.
 * Each block has a 16-byte header and a four-byte size footer. */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned char u8;
typedef struct {
    u8 name[9];
    u8 free;
    u8 first;
    u8 last;
    s32 size;
} RuntimeHeapBlock;
typedef struct { RuntimeHeapBlock *first; } RuntimeHeap;
typedef char aligned_heap_header[sizeof(RuntimeHeapBlock) == 16 ? 1 : -1];
typedef char aligned_heap_pointer[sizeof(void *) == 4 ? 1 : -1];
typedef char aligned_heap_size_offset[
    (unsigned long)&((RuntimeHeapBlock *)0)->size == 12 ? 1 : -1];

extern void func_800AA658(RuntimeHeap *, void **);
extern u32 func_800AA650(RuntimeHeap *);
extern void func_800B3AFC(void *, u32, u32);

static __inline__ void claimBlock(void **out, s32 size, const char *tag,
                                 RuntimeHeapBlock *block) {
    u8 i, j;
    register s32 total;
    s32 previousSize;

    *out = (u8 *)block + 0x10;
    block->free = 0;
    j = 0;
    i = 0;
    do {
        block->name[i] = tag[j];
        if (tag[j]) j++;
        i++;
    } while (i < 8);
    if (size + 0x1C < block->size) {
        u8 *footer;
        u8 last;
        register s32 offset __asm__("v0");

        previousSize = block->size;
        offset = size + 0x10;
        last = block->last;
        footer = (u8 *)block + offset;
        block->last = 0;
        block->size = size;
        block = (RuntimeHeapBlock *)(footer + 4);
        *(s32 *)footer = size;
        total = previousSize - 0x14;
        total -= size;
        block->name[0] = 'E';
        /* Keep the header offset in the final footer store. */
        footer = (u8 *)((u32)total + (u32)block);
        block->name[1] = 'M';
        block->name[2] = 'P';
        block->name[3] = 'T';
        block->name[4] = 'Y';
        block->name[5] = 0;
        block->name[6] = 0;
        block->name[7] = 0;
        block->name[8] = 0;
        block->free = 0xFF;
        block->first = 0;
        block->size = total;
        block->last = last;
        *(s32 *)(footer + 0x10) = total;
    }
}

s32 func_800AA100(RuntimeHeap *heap, void **output, s32 size, const char *tag) {
    s32 largest;
    RuntimeHeapBlock *block;
    RuntimeHeapBlock *aligned;
    u32 gap;
    void *lead;

    if (!heap->first) return -1;
    if (*output) return -1;
    size += 0x23;
    size &= -16;
    size -= 0x14;
    largest = -1;
    block = heap->first;
    for (;;) {
        if (block->free == 0xFF) {
            if (block->size < size) {
                if (largest < block->size) largest = block->size;
            } else {
                {
                    register u32 rawAddress = (u32)block + 0x4F;
                    aligned = (RuntimeHeapBlock *)((rawAddress & -0x40) - 0x10);
                    /* Empty constraints preserve the original address lifetimes. */
                    __asm__("" : : "r"(rawAddress));
                }
                gap = (u8 *)aligned - (u8 *)block;
                if (block != aligned) {
                    if (gap < 0x1C) gap += 0x40;
                    if ((u32)block->size >= size + gap) {
                        largest = 0;
                        claimBlock(&lead, gap - 0x14, tag, block);
                        block = (RuntimeHeapBlock *)((u8 *)block + block->size + 0x14);
                        claimBlock(output, size, tag, block);
                        func_800AA658(heap, &lead);
                        break;
                    }
                } else {
                    largest = 0;
                    __asm__("" : "+r"(block));
                    claimBlock(output, size, tag, block);
                    break;
                }
            }
        }
        if (block->last == 0xFF) break;
        block = (RuntimeHeapBlock *)((u8 *)block + block->size + 0x14);
    }
    /* The original performs these calls after unsuccessful searches too. */
    func_800B3AFC(*output, 0, size);
    func_800AA650(heap);
    return largest;
}
