/* Runtime-stage C reconstruction: allocate a link pool and its free stack, then thread every link. */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;

typedef struct RuntimeLinkEntry {
    u32 unk0;
    u32 unk4;
    u32 unk8;
} RuntimeLinkEntry;
typedef char check_link_entry[sizeof(RuntimeLinkEntry) == 0xC ? 1 : -1];

typedef struct RuntimeLinkPool {
    void *heap;
    RuntimeLinkEntry *links;
    void **stack;
    void **top;
    u16 capacity;
} RuntimeLinkPool;
typedef char check_link_pool[sizeof(RuntimeLinkPool) == 0x14 ? 1 : -1];

extern char runtimeLinkStackTag[];
extern char runtimeLinkTag[];
extern s32 func_800AA804(void *heap, void *output, s32 size, const char *tag);
extern void func_800AB66C(RuntimeLinkPool *pool, RuntimeLinkEntry *link);
extern void func_800AB684(RuntimeLinkPool *pool);

s32 func_800AB708(RuntimeLinkPool *pool, void *heap, u16 capacity) {
    RuntimeLinkEntry *link;

    pool->heap = heap;
    pool->capacity = capacity;
    if (func_800AA804(heap, &pool->stack, capacity * 4, runtimeLinkStackTag) == 0
        && func_800AA804(heap, &pool->links, capacity * 12, runtimeLinkTag) == 0) {
        pool->top = pool->stack;
        link = pool->links;
        while (capacity) {
            func_800AB66C(pool, link);
            capacity--;
            link++;
        }
        return 1;
    }
    func_800AB684(pool);
    return 0;
}
