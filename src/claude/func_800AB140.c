/* Dispatch due one-based priority-heap events through object callback slots.
 * The (unreferenced) check label inside the loop is load-bearing: GCC 2.8
 * refuses to duplicate a loop exit test containing a code label, which keeps
 * the original top-tested, unrotated loop shape. The root entry is taken via
 * a small inline helper so &entry is materialized as its parameter. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed int s32;
typedef struct { void *unused; void **entries, **freeEntries; u16 count, capacity, freeCursor; } PriorityHeap;
typedef struct { u32 kind, key; void *object; u32 data[3]; } DispatchEvent;
typedef struct { u8 unused[0x18]; s32 time; } DispatchContext;
extern DispatchContext runtimeDispatchContext; /* 0x800F272C */
extern s32 func_800AB024(PriorityHeap *);
extern void func_800AB038(PriorityHeap *, void **, u32);
extern void func_800AB004(PriorityHeap *, void *, DispatchEvent *);
static inline void take_root(PriorityHeap *heap, void **out) {
    *out = 0;
    if (heap->count != 0 && heap->count <= heap->capacity)
        func_800AB038(heap, out, 1);
}
void func_800AB140(PriorityHeap *heap, s32 time) {
    DispatchEvent event;
    void *entry;
    int done = 0;
    for (;;) {
    check:
        if (done) break;
        if (heap->count != 0 && func_800AB024(heap) <= time) {
            runtimeDispatchContext.time = func_800AB024(heap);
            take_root(heap, &entry);
            func_800AB004(heap, entry, &event);
            if (event.kind == 2) event.key &= 0xFFFFFF00;
            {
                u8 *vtable = *(u8 **)((u8 *)event.object + 0xB4);
                short adjust = *(short *)(vtable + 0x30);
                void (*callback)(void *, DispatchEvent *) = *(void (**)(void *, DispatchEvent *))(vtable + 0x34);
                callback((u8 *)event.object + adjust, &event);
            }
        } else {
            done = 1;
        }
    }
    runtimeDispatchContext.time = time;
}
