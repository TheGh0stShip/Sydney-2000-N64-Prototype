#include "sydney_types.h"

/* Empties a stack of 7-object slot records, returning each object to its free pool. */
typedef struct VEntry { s16 delta; s16 pad; void *fn; } VEntry;
typedef struct Obj { u8 unk_00[0xB4]; VEntry *vtbl; } Obj;
typedef struct Pool { u8 unk_00[0xC]; Obj **top; u16 cap; u16 count; } Pool;
typedef struct Slot { Obj *unk_00; Obj *unk_04; Obj *unk_08; Obj *unk_0C; Obj *unk_10; Obj *unk_14; Obj *unk_18; } Slot;
typedef struct Mgr {
    Pool pool0; Pool pool14; Pool pool28; Pool pool3C; Pool pool50; Pool pool64; Pool pool78;
    u8 unk_8C[0x690 - 0x8C];
    Slot slots[(0x118D - 0x690) / 0x1C];
    u8 unk_1180[0xD];
    u8 n;
} Mgr;

extern s32 D_800F26E0;
void func_800AACB0(s32 *, Obj *, s32);
void func_800CE024(Obj *);
void func_800B35F0(Obj *);
void func_800CD840(Obj *);

#define VCALL0(o, i) (((void (*)(void *))(o)->vtbl[i].fn)((char *)(o) + (o)->vtbl[i].delta))
#define VCALL1(o, i, a) (((void (*)(void *, s32))(o)->vtbl[i].fn)((char *)(o) + (o)->vtbl[i].delta, a))

static inline void release(Pool *pool, Obj *obj) {
    VCALL0(obj, 3);
    func_800AACB0(&D_800F26E0, obj, 0);
    if (pool->count < pool->cap) {
        VCALL1(obj, 1, 2);
        *pool->top = obj;
        pool->top++;
        pool->count++;
    }
}

void func_80099728(Mgr *m) {
    Slot *s;
    while (1) {
        s32 i = m->n;
        if (i == 0) break;
        m->n = --i;
        s = &m->slots[m->n];
        if (s->unk_10 != NULL) {
            func_800CE024(s->unk_10);
            release(&m->pool50, s->unk_10);
            s->unk_10 = NULL;
        }
        if (s->unk_04 != NULL) {
            func_800B35F0(s->unk_04);
            release(&m->pool14, s->unk_04);
            s->unk_04 = NULL;
        }
        if (s->unk_00 != NULL) {
            VCALL0(s->unk_00, 3);
            release(&m->pool0, s->unk_00);
            s->unk_00 = NULL;
        }
        if (s->unk_18 != NULL) {
            VCALL0(s->unk_18, 3);
            release(&m->pool78, s->unk_18);
            s->unk_18 = NULL;
        }
        if (s->unk_08 != NULL) {
            VCALL0(s->unk_08, 3);
            release(&m->pool28, s->unk_08);
            s->unk_08 = NULL;
        }
        if (s->unk_0C != NULL) {
            func_800CD840(s->unk_0C);
            release(&m->pool3C, s->unk_0C);
            s->unk_0C = NULL;
        }
        if (s->unk_14 != NULL) {
            release(&m->pool64, s->unk_14);
            s->unk_14 = NULL;
        }
    }
}
