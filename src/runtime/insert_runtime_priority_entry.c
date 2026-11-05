/* Insert a deadline/kind event into the one-based runtime priority queue. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed int s32;
typedef struct { s32 kind, deadline; void *object; u32 data[2]; u16 index, reserved; } PriorityEntry;
typedef struct { void *unused; PriorityEntry **entries, **freeEntries; u16 count, capacity, freeCursor; } PriorityHeap;
extern PriorityEntry *func_800AB4CC(PriorityHeap *);
typedef char check_priority_pointer_width[sizeof(void *) == 4 ? 1 : -1];
typedef char check_priority_entry_width[sizeof(PriorityEntry) == 24 ? 1 : -1];
void func_800AB2A4(PriorityHeap *heap, s32 deadline, s32 kind, void *object, u32 first, u32 second) {
    u32 slot;
    u32 parent;
    u32 selected;
    PriorityEntry *entry;
    PriorityEntry *parentEntry;
    int before;
    {
    u32 count = heap->count;
    if (count < heap->capacity) {
    u32 nextIndex = count + 1;
    heap->count = nextIndex;
    slot = nextIndex;
    goto check_parent;
move_parent:
        parentEntry = heap->entries[parent];
        if (parentEntry->deadline == deadline) before = parentEntry->kind < kind;
        else before = parentEntry->deadline < deadline;
        if (before) goto allocate_entry;
        heap->entries[(u16)slot] = heap->entries[parent];
        heap->entries[(u16)slot]->index = slot;
        slot = (u16)slot >> 1;
check_parent:
    selected = (u16)slot;
    if (selected >= 2) {
        parent = selected >> 1;
        goto move_parent;
    }
allocate_entry:
    entry = func_800AB4CC(heap);
    entry->kind = kind;
    entry->deadline = deadline;
    entry->object = object;
    entry->data[0] = first;
    entry->data[1] = second;
    entry->index = slot;
    heap->entries[(u16)slot] = entry;
    }
    }
}
