/* Reserve the largest available aligned runtime heap, stepping down 16KiB.
 * The allocation is initialized as one free block with matching size footer.
 * Note: as in the original, the previous interrupt mask is only restored when
 * the heap was not already initialized.
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef struct {
    u8 *first;
    s32 size;
    u32 unused[3];
    s32 reservedSize;
} RuntimeHeap;
extern u32 func_80037A10(u32 mask);
extern void func_80037A50(u32 previous);
extern void *func_80037B30(s32 alignment, u32 size);
void func_800AA92C(RuntimeHeap *heap, s32 maximum, s32 minimum) {
    u32 previous = func_80037A10(0x2800);
    u8 *block;
    if (!heap->first) {
        heap->size = 0;
        while (maximum >= minimum) {
            block = func_80037B30(16, maximum);
            if (block == 0 || block == (u8 *)-1) {
                maximum -= 0x4000;
                continue;
            }
            heap->size = maximum;
            heap->reservedSize = maximum;
            maximum -= 20;
            heap->first = block;
            block[0] = 'E';
            block[1] = 'M';
            block[2] = 'P';
            block[3] = 'T';
            block[4] = 'Y';
            block[5] = 0;
            block[6] = 0;
            block[7] = 0;
            block[8] = 0;
            block[9] = 0xFF;
            block[10] = 0xFF;
            block[11] = 0xFF;
            *(s32 *)(block + 12) = maximum;
            *(s32 *)((u32)maximum + (u32)block + 16) = maximum;
            break;
        }
        func_80037A50(previous);
    }
}
