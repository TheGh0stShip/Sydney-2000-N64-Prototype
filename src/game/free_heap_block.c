#ifndef LEAF_NAME
#define LEAF_NAME freeHeapBlock
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

int LEAF_NAME(HeapBlock *heap, void *allocation) {
    HeapBlock *block;
    HeapBlock *next;
    HeapBlock *cursor;
    u32 size;

    if (allocation != 0) {
        block = (HeapBlock *)((u8 *)allocation - 16);
        if (block->allocated != 0) {
            next = block->next;
            size = block->size;
            if (next != 0 && next->allocated == 0) {
                size += next->size + 16;
                next = next->next;
            }

            cursor = heap;
            while (cursor->next != block && cursor < block && cursor->next != 0) {
                cursor = cursor->next;
            }
            if (cursor->next == block && cursor->allocated == 0) {
                block = cursor;
                size += cursor->size + 16;
            }

            block->next = next;
            block->size = size;
            block->allocated = 0;
            return 0;
        }
    }
    return 1;
}
