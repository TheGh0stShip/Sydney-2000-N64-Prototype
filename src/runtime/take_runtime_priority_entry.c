/* Take the next reusable record after an insertion has grown active count. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct PriorityEntry PriorityEntry;
typedef struct { void *unused; PriorityEntry **entries, **freeEntries; u16 count, capacity, freeCursor; } PriorityHeap;
extern char runtimeQueuePoolAssertion[], runtimeQueueSourceName[];
extern void func_8001C3B8(const char *, const char *, u32);
typedef char check_priority_pointer_width[sizeof(void *) == 4 ? 1 : -1];
PriorityEntry *func_800AB4CC(PriorityHeap *heap) {
    if (heap->freeCursor >= heap->count)
        func_8001C3B8(runtimeQueuePoolAssertion, runtimeQueueSourceName, 0x1DF);
    return heap->freeEntries[heap->freeCursor++];
}
