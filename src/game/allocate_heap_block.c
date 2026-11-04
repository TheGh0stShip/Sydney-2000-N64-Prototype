#ifndef LEAF_NAME
#define LEAF_NAME allocateHeapBlock
#endif

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct HeapBlock HeapBlock;
struct HeapBlock {
    HeapBlock *next;
    u32 size;
    u32 allocated;
    u32 reserved;
};

void *LEAF_NAME(HeapBlock *heap, u32 requestedSize) {
    HeapBlock *block;
    HeapBlock *bestBlock = 0;
    HeapBlock *bestNext = 0;
    u32 size;
    u32 totalSize;
    u32 bestSize = 0;

    if (requestedSize == 0) {
        return 0;
    }
    size = (requestedSize + 15) & ~15;
    totalSize = size + 16;

    for (block = heap; block != 0; block = block->next) {
        if (block->allocated == 0 && block->size >= size &&
            (bestSize == 0 || block->size < bestSize)) {
            bestBlock = block;
            bestSize = block->size;
            bestNext = block->next;
        }
    }
    if (bestSize == 0) {
        return 0;
    }

    if (bestSize >= size + 32) {
        HeapBlock *remainder = (HeapBlock *)((u8 *)bestBlock + totalSize);

        bestBlock->next = remainder;
        bestBlock->size = size;
        bestBlock->allocated = 1;
        remainder->next = bestNext;
        remainder->size = bestSize - totalSize;
        remainder->allocated = 0;
    } else {
        bestBlock->next = bestNext;
        bestBlock->size = bestSize;
        bestBlock->allocated = 1;
    }
    return (u8 *)bestBlock + 16;
}
