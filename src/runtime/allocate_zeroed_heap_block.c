/* Allocate from the runtime heap and clear its rounded payload.
 * Heap headers are 20 bytes; blocks carry byte sentinels at offsets9 and11.
 */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned char u8;
typedef struct {
    u8 unused[9];
    u8 free;
    u8 unused0A;
    u8 last;
    s32 size;
    u32 unused10;
} RuntimeHeapBlock;
typedef struct { RuntimeHeapBlock *first; } RuntimeHeap;
typedef char check_runtime_header[sizeof(RuntimeHeapBlock) == 20 ? 1 : -1];
extern char runtimeHeapSourceName[];
extern char runtimeEmptyHeapAssertion[];
extern char runtimeOutputAssertion[];
extern void func_800AAA60(const char *, u32, const char *);
extern void func_800AA724(RuntimeHeap *, void **, s32, const char *, RuntimeHeapBlock *);
extern u32 func_800AA650(RuntimeHeap *);
extern void func_800B3AFC(void *, u32, u32);

s32 func_800AA804(RuntimeHeap *heap, void **output, s32 size, const char *tag) {
    register s32 largest __asm__("$17");
    RuntimeHeapBlock *block;
    if (!heap->first)
        func_800AAA60(runtimeHeapSourceName, 0x21D, runtimeEmptyHeapAssertion);
    if (*output)
        func_800AAA60(runtimeHeapSourceName, 0x21E, runtimeOutputAssertion);
    size += 0x23;
    size &= -16;
    size -= 0x14;
    largest = -1;
    block = heap->first;
    for (;;) {
        if (block->free == 0xFF) {
            if (block->size >= size) {
                largest = 0;
                func_800AA724(heap, output, size, tag, block);
                break;
            }
            if (largest < block->size) largest = block->size;
        }
        if (block->last == 0xFF) break;
        block = (RuntimeHeapBlock *)((u8 *)block + block->size + 0x14);
    }
    func_800AA650(heap);
    func_800B3AFC(*output, 0, size);
    return largest;
}
