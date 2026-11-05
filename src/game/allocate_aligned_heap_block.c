/* Exact KMC GCC reconstruction of func_80037B30 (ROM 0x38730).
 * Heap pointers and pointer differences follow the N64 o32 ABI.
 * Sampled behavior is checked by tools/validate_aligned_heap.py.
 * Matching compiler: KMC GCC -O1 -G0 -mips3 -mgp32 -mfp32.
 * External symbol: alignedHeap=0x80068460.
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct HeapBlock HeapBlock;
struct HeapBlock {
    HeapBlock *next;
    u32 size;
    u32 allocated;
    u32 reserved;
};
typedef char check_heap_layout[sizeof(HeapBlock) == 16 ? 1 : -1];
extern HeapBlock *volatile alignedHeap;
extern void *func_80037D10(HeapBlock *, u32);

void *func_80037B30(int alignment, u32 requestedSize) {
    register HeapBlock *block __asm__("$6");
    register HeapBlock *bestBlock __asm__("$11");
    register HeapBlock *bestNext __asm__("$12");
    register u32 bestSize __asm__("$10");
    register u32 offset __asm__("$13");
    register u32 blockSize __asm__("$8");
    register u8 *allocation __asm__("$9");
    register u8 *candidate __asm__("$7");
    register HeapBlock *prefix __asm__("$6");
    register HeapBlock *allocated __asm__("$6");
    int distance;
    register int prefixSize __asm__("$2");
    register u8 *end __asm__("$3");
    register HeapBlock *next __asm__("$2");
    register HeapBlock *head __asm__("$4");

    if (alignedHeap != (HeapBlock *)-1) {
        if (requestedSize != 0) {
            if (alignment <= 16) return func_80037D10(alignedHeap, requestedSize);
            requestedSize += 15;
            block = alignedHeap;
            requestedSize &= ~15;
            bestSize = 0;
            bestNext = 0;
            offset = alignment + 15;
            alignment = -alignment;
            do {
                if (!block->allocated) {
                    candidate = (u8 *)(((u32)block + offset) & alignment);
                    if (candidate >= (u8 *)(block + 1)) {
                        blockSize = block->size;
                        end = candidate + requestedSize;
                        if (end < (u8 *)block + blockSize &&
                            (blockSize < bestSize || bestSize == 0)) {
                            allocation = candidate;
                            bestBlock = block;
                            bestSize = blockSize;
                            bestNext = block->next;
                        }
                    }
                }
                next = block->next;
                if (!next) break;
                block = next;
            } while (1);
            if (bestSize != 0) {
                head = alignedHeap;
                if (bestBlock == head) goto head_prefix;
                distance = allocation - (u8 *)bestBlock;
                prefix = bestBlock;
                if (distance < 33) {
                    if ((distance >> 2) < 16) goto allocate;
                    prefix = head;
scan_prefix:
                    if (prefix->next == 0) goto allocate;
                    if (prefix->next == bestBlock) goto found_prefix;
                    prefix = ((volatile HeapBlock *)prefix)->next;
                    goto scan_prefix;
                }
                prefix->next = (HeapBlock *)(allocation - 16);
                prefixSize = allocation - (u8 *)prefix;
                goto size_prefix;
found_prefix:
                prefix->next = (HeapBlock *)(allocation - 64);
                prefix->size += 16;
                goto allocate;
head_prefix:
                prefix = bestBlock;
                prefix->next = (HeapBlock *)(allocation - 16);
                prefixSize = ((allocation - (u8 *)prefix) >> 2) << 2;
size_prefix:
                prefix->size = prefixSize - 32;
                prefix->allocated = 0;
allocate:
                allocated = (HeapBlock *)(allocation - 16);
                if (bestSize >= requestedSize + 32) {
                    register HeapBlock *remainder __asm__("$6");
                    allocated->next = (HeapBlock *)(allocation + requestedSize);
                    allocated->size = requestedSize;
                    allocated->allocated = 1;
                    remainder = allocated->next;
                    remainder->next = bestNext;
                    remainder->size = bestSize - requestedSize -
                        (((allocation - (u8 *)bestBlock) >> 2) << 2);
                    remainder->allocated = 0;
                } else {
                    allocated->next = bestNext;
                    allocated->size = (int *)bestNext - (int *)allocation;
                    allocated->allocated = 1;
                }
                /* Preserve search values so GCC uses scratch registers for splits. */
                __asm__("" : : "r"(bestSize), "r"(bestNext), "r"(bestBlock));
                return allocation;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}
