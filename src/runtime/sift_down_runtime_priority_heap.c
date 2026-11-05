/* Maintain a one-based runtime priority heap using its signed key pair.
 * Equal right-child key pairs win the tie; left children require strict order.
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;
typedef signed int s32;
typedef struct { s32 first, second; u8 unused[12]; u16 index, reserved; } PriorityEntry;
typedef struct { void *unused; PriorityEntry **entries; void *freeEntries; u16 count, capacity, available; } PriorityHeap;
typedef char check_runtime_pointer_width[sizeof(void *) == 4 ? 1 : -1];
typedef char check_priority_entry_size[sizeof(PriorityEntry) == 24 ? 1 : -1];
/* Empty operand constraints retain the original SN temporary allocation. */
void func_800AAED0(PriorityHeap *heap, u32 best) {
    u32 left, right, original;
    register PriorityEntry *candidate __asm__("$3");
    register PriorityEntry *current __asm__("$5");
    PriorityEntry *temporary;
    int less;
    for (;;) {
        left = best * 2;
        right = left | 1;
        original = best;
        if ((left & 0xFFFE) <= heap->count) {
            register u32 byteOffset __asm__("$3") = (left & 0xFFFE) * 4;
            register u32 selected __asm__("$2");
            __asm__("" : "=r"(byteOffset) : "0"(byteOffset));
            selected = (u16)best;
            __asm__("" : "=r"(selected) : "0"(selected));
            candidate = *(PriorityEntry **)(byteOffset + (u32)heap->entries);
            current = heap->entries[selected];
            __asm__("" : "=r"(candidate), "=r"(current) : "0"(candidate), "1"(current));
            {
                register s32 candidateKey __asm__("$2") = candidate->second;
                register s32 currentKey __asm__("$4") = current->second;
                __asm__("" : "=r"(candidateKey), "=r"(currentKey) : "0"(candidateKey), "1"(currentKey));
                if (candidateKey == currentKey) {
                    register s32 first __asm__("$2") = candidate->first;
                    register s32 second __asm__("$3") = current->first;
                    __asm__("" : "=r"(first), "=r"(second) : "0"(first), "1"(second));
                    less = first < second;
                } else less = candidateKey < currentKey;
            }
            if (less) best = left;
        }
        if ((u16)right <= heap->count) {
            register u32 byteOffset __asm__("$3") = (u16)right * 4;
            register u32 selected __asm__("$2");
            __asm__("" : "=r"(byteOffset) : "0"(byteOffset));
            selected = (u16)best;
            __asm__("" : "=r"(selected) : "0"(selected));
            candidate = *(PriorityEntry **)(byteOffset + (u32)heap->entries);
            current = heap->entries[selected];
            __asm__("" : "=r"(candidate), "=r"(current) : "0"(candidate), "1"(current));
            if (candidate->second == current->second) {
                if (candidate->first <= current->first) best = right;
            } else if (candidate->second < current->second) best = right;
        }
        if ((u16)best == (u16)original) break;
        temporary = heap->entries[(u16)original];
        heap->entries[(u16)original] = heap->entries[(u16)best];
        heap->entries[(u16)best] = temporary;
        heap->entries[(u16)best]->index = best;
        heap->entries[(u16)original]->index = original;
    }
}
