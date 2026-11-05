typedef struct {
    short delta;
    short pad;
    void (*fn)();
} VEntry;

typedef struct {
    VEntry entries[10];
} VTable;

typedef struct {
    char pad0[180];
    VTable *vt;
    char pad184[12];
    int handle;
} Object;

typedef struct {
    char pad0[12];
    Object **next;
    unsigned short capacity;
    unsigned short count;
} FreeList;

typedef struct {
    char pad0[20168];
    FreeList pool;
    char pad20188[0];
    Object *slots[8];
} Owner;

extern char D_800F26E0[];
typedef struct {
    int words[15];
} PlayerSlot;

typedef struct {
    char pad0[72];
    PlayerSlot players[8];
} GameState;

extern GameState *D_800FC270;
extern void func_800AACB0(void *a, void *b, int c);
extern void func_800172CC(int handle, int a);

#define VCALL(o, n) ((o)->vt->entries[n].fn((char *)(o) + (o)->vt->entries[n].delta))

void func_800D95B4(Owner *owner, unsigned char slot)
{
    char *ent;
    Object *sub;
    unsigned char kind;
    Object **p;
    Object *e;
    FreeList *pool;

    ent = (char *)owner->slots[slot];
    if (ent == 0)
        return;
    func_800AACB0(D_800F26E0, ent, 0);
    sub = (Object *)(ent + 1004);
    if (sub != 0) {
        VCALL(sub, 3);
        VCALL(sub, 9);
        if (sub->handle != 0)
            func_800172CC(sub->handle, 1);
    }
    sub = (Object *)(ent + 792);
    if (sub != 0) {
        VCALL(sub, 3);
        VCALL(sub, 9);
    }
    kind = *(unsigned char *)(ent + 424);
    if (kind != 8)
        D_800FC270->players[kind].words[0] = 0;
    p = (Object **)((char *)owner + slot * 4);
    e = p[20188 / 4];
    pool = &owner->pool;
    VCALL(e, 3);
    func_800AACB0(D_800F26E0, e, 0);
    if (pool->count < pool->capacity) {
        e->vt->entries[1].fn((char *)e + e->vt->entries[1].delta, 2);
        *pool->next = e;
        pool->next++;
        pool->count++;
    }
    p[20188 / 4] = 0;
}
