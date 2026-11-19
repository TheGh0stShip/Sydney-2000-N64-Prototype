#include "sydney_types.h"

/* Sets up the object's pool of 32 sub-objects (0xD4 bytes each), creates them all, and fills a 10-step scale table. */
typedef struct {
    u8 pad[0x28];
    f32 unk_28;
} Shape;

typedef struct {
    u8 pad[8];
    Shape *unk_08;
} Model;

typedef struct Sub {
    u8 pad[0xC0];
    s32 unk_C0;
    s32 unk_C4;
    u8 padC8[0xD0 - 0xC8];
    Model *unk_D0;
} Sub;

typedef struct {
    void *heap;
    u8 *objs;
    void **stack;
    void **sp;
    u16 cap;
    u16 count;
} Pool;

typedef struct {
    u8 pad0[0xB1];
    u8 unk_B1;
    u8 padB2[0xD0 - 0xB2];
    Model *unk_D0;
    s32 unk_D4;
    Pool pool;
    Sub *subs[32];
    u8 unk_16C;
    u8 pad16D[2];
    f32 unk_170;
    f32 unk_174;
    f32 unk_178[10];
    u8 pad1A0_[0x1A0 - 0x1A0];
    s16 unk_1A0;
} Obj;

extern u8 D_8007095C[];
extern u8 D_80070964[];
extern u8 D_8007096C[];
extern u8 D_800F2758[];

u16 func_8000EB20(void *);
void func_80013208(s32 *, f32, f32, s32, s32);
void func_800AA658(void *heap, void *slot);
s32 func_800AA804(void *heap, void *slot, s32 size, void *name);
void *func_800AAA58(s32 size, void *p);
void func_800ADED4(void *);
void func_800AD890(Sub *, s32);
void func_800ADC54(Sub *, s32);

static inline void pool_free(Pool *pool) {
    void *heap = pool->heap;

    if (heap != NULL) {
        pool->heap = NULL;
        if (pool->objs != NULL) {
            func_800AA658(heap, &pool->objs);
        }
        if (pool->stack != NULL) {
            func_800AA658(heap, &pool->stack);
        }
        pool->cap = 0;
        pool->count = 0;
        pool->sp = NULL;
        pool->heap = NULL;
    }
}

static inline void pool_init(Pool *pool, void *heap, u16 n) {
    u8 *obj;

    if (pool->heap != NULL) {
        return;
    }
    pool->heap = heap;
    pool->cap = n;
    if (func_800AA804(heap, &pool->stack, n * 4, D_80070964) == 0
        && func_800AA804(heap, &pool->objs, n * 0xD4, D_8007096C) == 0) {
        obj = pool->objs;
        pool->sp = pool->stack;
        do {
            *pool->sp = obj;
            obj += 0xD4;
            pool->sp++;
            pool->count++;
            n--;
        } while (n != 0);
    } else {
        pool_free(pool);
    }
}

static inline Sub *pool_alloc(Pool *pool) {
    Sub *s = NULL;

    if (pool->sp > pool->stack) {
        pool->count--;
        pool->sp--;
        s = *pool->sp;
        *pool->sp = NULL;
        func_800ADED4(func_800AAA58(0xD4, s));
    }
    return s;
}

void func_800C6650(Obj *o) {
    u8 i;

    o->unk_1A0 = 0;
    o->unk_16C = 0;
    o->unk_D4 = 0;
    func_80013208(&o->unk_D4, 3.2766998f, 3.2766998f, func_8000EB20(D_8007095C), 2);
    pool_init(&o->pool, D_800F2758, 32);
    i = 0;
    while (1) {
        if (i >= 32) {
            break;
        }
        o->subs[i] = pool_alloc(&o->pool);
        o->subs[i]->unk_C4 = o->unk_D4;
        func_800ADC54(o->subs[i], 1);
        func_800AD890(o->subs[i], 1);
        o->subs[i]->unk_C0 |= 0x20;
        o->subs[i]->unk_D0->unk_08->unk_28 = 1.6383499f;
        i++;
    }
    o->unk_170 = o->unk_D0->unk_08->unk_28;
    o->unk_174 = o->unk_170 * 0.1f;
    for (i = 0; i < 10; i++) {
        o->unk_178[i] = o->unk_174 * (i + 1);
    }
    o->unk_B1 = 0;
}
