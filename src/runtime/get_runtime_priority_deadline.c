/* Read the signed deadline of the one-based priority heap's root entry. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct { int kind, deadline; unsigned char unused[12]; u16 index, reserved; } PriorityEntry;
typedef struct { void *unused; PriorityEntry **entries, **freeEntries; u16 count, capacity, freeCursor; } PriorityHeap;
int func_800AB024(PriorityHeap *heap) { return heap->entries[1]->deadline; }
