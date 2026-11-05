typedef struct {
    short delta;
    short index;
    void (*fn)(char *, int);
} VEntry;

typedef struct {
    char *heap;
    void *bufA;
    void *bufB;
    char **top;
    unsigned short cap;
    unsigned short count;
    short pad14;
    short flag;
} FreeList;

typedef struct {
    char pad0[232];
    char *items[30];
    FreeList pool;
} Owner;

extern char D_800F26E0[];
extern void func_800AACB0(char *, char *, int);
extern void func_800AA658(char *, void *);

#define VCALL(p, n, arg) \
    (v = &(*(VEntry **)((p) + 180))[n], v->fn((p) + v->delta, (arg)))

static __inline__ void pool_release(FreeList *pool)
{
    char *heap;

    heap = pool->heap;
    if (heap != 0) {
        pool->heap = 0;
        if (pool->bufA != 0) {
            func_800AA658(heap, &pool->bufA);
        }
        if (pool->bufB != 0) {
            func_800AA658(heap, &pool->bufB);
        }
        pool->cap = 0;
        pool->count = 0;
        pool->top = 0;
        pool->heap = 0;
    }
}

void func_800D7F5C(Owner *obj)
{
    unsigned char i;
    char *e;
    FreeList *pool;
    VEntry *v;

    i = 0;
    while (1) {
        if (!(i < 30)) {
            break;
        }
        e = obj->items[i];
        if (e != 0) {
            pool = &obj->pool;
            v = &(*(VEntry **)(e + 180))[3];
            ((void (*)(char *))v->fn)(e + v->delta);
            func_800AACB0(D_800F26E0, e, 0);
            if (pool->count < pool->cap) {
                VCALL(e, 1, 2);
                *pool->top = e;
                pool->top++;
                pool->count++;
            }
            obj->items[i] = 0;
        }
        i++;
    }
    pool_release(&obj->pool);
    obj->pool.flag = 0;
}
