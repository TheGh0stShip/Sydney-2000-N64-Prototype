/* Remove a selected one-based priority-heap entry, recycle it and restore order. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { int first, second; u8 unused[12]; u16 index, reserved; } PriorityEntry;
typedef struct { void *unused; PriorityEntry **entries; PriorityEntry **freeEntries; u16 count, capacity, freeCursor; } PriorityHeap;
extern char runtimeQueueBoundsAssertion[], runtimeQueueIndexAssertion[], runtimeQueueSourceName[];
extern void func_8001C3B8(const char *, const char *, u32);
extern void func_800AAED0(PriorityHeap *, u32);
typedef char check_priority_pointer_width[sizeof(void *) == 4 ? 1 : -1];
typedef char check_priority_entry_width[sizeof(PriorityEntry) == 24 ? 1 : -1];
void func_800AB038(PriorityHeap *heap, PriorityEntry **outputArgument, u32 indexArgument) {
    u32 index = indexArgument;
    PriorityEntry **output = outputArgument;
    u32 selected = (u16)index;
    if (heap->count < selected)
        func_8001C3B8(runtimeQueueBoundsAssertion, runtimeQueueSourceName, 0x1F0);
    if (!selected)
        func_8001C3B8(runtimeQueueIndexAssertion, runtimeQueueSourceName, 0x1F1);
    *output = heap->entries[selected];
    {
        u16 available = heap->freeCursor;
        PriorityEntry **entries = heap->entries;
        PriorityEntry **freeEntries = heap->freeEntries;
        available--;
        heap->freeCursor = available;
        freeEntries[available] = entries[selected];
    }
    heap->entries[selected] = heap->entries[heap->count];
    heap->entries[selected]->index = index;
    heap->count--;
    func_800AAED0(heap, selected);
}
