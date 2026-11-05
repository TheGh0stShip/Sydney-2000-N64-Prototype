/* Detach and release the owned child: notify it through several virtual
 * hooks, unregister it, return it to the free pool if there is room, then
 * tear down the pool's backing allocations. */
typedef struct VEntry {
    short delta;
    short index;
    void (*fn)();
} VEntry;

typedef struct Child {
    char pad[180];
    VEntry *vtbl;
    char pad2[196 - 184];
    char node[1];
} Child;

typedef struct Pool {
    Child *head;
    void *blockA;
    void *blockB;
    Child **cursor;
    unsigned short capacity;
    unsigned short count;
} Pool;

typedef struct Owner {
    char pad[692];
    Pool pool;
    Child *child;
} Owner;


extern char D_800F26E0[];
extern void func_8001A248(void *node);
extern void func_800AACB0(void *list, Child *c, int arg);
extern void func_800AA658(Child *c, void **block);

void func_800C3764(Owner *o)
{
    Child *c = o->child;
    Pool *pool;
    Child *h;

    if (c == 0) {
        return;
    }
    c->vtbl[3].fn((char *)c + c->vtbl[3].delta);
    func_8001A248(o->child->node);
    c->vtbl[3].fn((char *)c + c->vtbl[3].delta);
    c->vtbl[9].fn((char *)c + c->vtbl[9].delta);
    pool = &o->pool;
    c->vtbl[3].fn((char *)c + c->vtbl[3].delta);
    func_800AACB0(D_800F26E0, c, 0);
    if (pool->count < pool->capacity) {
        c->vtbl[1].fn((char *)c + c->vtbl[1].delta, 2);
        *pool->cursor = c;
        pool->cursor++;
        pool->count++;
    }
    h = o->pool.head;
    if (h == 0) {
        o->child = 0;
        return;
    }
    o->pool.head = 0;
    if (pool->blockA != 0) {
        func_800AA658(h, &o->pool.blockA);
    }
    if (pool->blockB != 0) {
        func_800AA658(h, &o->pool.blockB);
    }
    pool->capacity = 0;
    pool->count = 0;
    pool->cursor = 0;
    o->pool.head = 0;
    o->child = 0;
}
