#include "sydney_types.h"

/* Sets up an object pool of n entries, clears the slot tables and adds the n entries. */
typedef struct { u8 pad[0xD4]; } Item;
typedef struct { f32 x, y, z; } Vec;
typedef struct Heap Heap;
typedef struct {
    Heap *heap;
    Item *items;
    Item **free;
    Item **top;
    u16 cap;
    u16 count;
} Pool;
typedef struct {
    u8 pad0[0xBC];
    u8 unk_BC;
    u8 unk_BD;
    u8 unk_BE[11];
    u8 padC9[0xCC - 0xC9];
    Pool pool;
    u8 padE0[0];
    s32 unk_E0[11];
    s32 unk_10C[11];
} Obj;
extern Heap D_800F2758;
extern char D_80085920[];
extern char D_80085928[];
s32 func_800AA804(Heap *, void *, s32, char *);
void func_800AA658(Heap *, void *);
void func_800A7B40(Obj *, Vec *, s32);
void func_80037F30(void *, s32, s32);

static inline void pool_free(Pool *p) {
    Heap *h = p->heap;
    if (h != NULL) {
        p->heap = NULL;
        if (p->items != NULL) func_800AA658(h, &p->items);
        if (p->free != NULL) func_800AA658(h, &p->free);
        p->cap = 0;
        p->count = 0;
        p->top = NULL;
        p->heap = NULL;
    }
}

static inline void pool_init(Pool *p, u16 n) {
    Item *it;
    Heap *h = &D_800F2758;
    if (p->heap == NULL) {
        p->heap = h;
        p->cap = n;
        if (func_800AA804(h, &p->free, n * sizeof(Item *), D_80085920) == 0
            && func_800AA804(h, &p->items, n * sizeof(Item), D_80085928) == 0) {
            it = p->items;
            p->top = p->free;
            for (; n != 0; n--) {
                *p->top = it;
                it++;
                p->top++;
                p->count++;
            }
        } else {
            pool_free(p);
        }
    }
}

void func_800A7610(Obj *obj, u8 n, Vec *pos, s32 *kind) {
    u8 i;
    Vec zero;

    pool_init(&obj->pool, n);
    for (i = 0; i < 11; i++) {
        obj->unk_BE[i] = 0x20;
        obj->unk_10C[i] = 0;
        obj->unk_E0[i] = 0;
    }
    obj->unk_BD = 0;
    obj->unk_BC = 0;
    if (pos != NULL && kind != NULL) {
        for (i = 0; i < n; i++) func_800A7B40(obj, &pos[i], kind[i]);
    } else if (kind != NULL) {
        func_80037F30(&zero, 0, sizeof(zero));
        for (i = 0; i < n; i++) func_800A7B40(obj, &zero, kind[i]);
    } else if (pos != NULL) {
        for (i = 0; i < n; i++) func_800A7B40(obj, &pos[i], 9);
    } else {
        func_80037F30(&zero, 0, sizeof(zero));
        for (i = 0; i < n; i++) func_800A7B40(obj, &zero, 9);
    }
}
