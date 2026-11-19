#include "sydney_types.h"

/* Sets up a render/link object from the current entry and attaches it to related sub-objects. */
typedef struct { u8 unk_00[0x20]; } Ent;
typedef struct { u8 unk_00[0xB8]; Ent ent[1]; } Table;
typedef struct { s32 unk_00; void *unk_04; } Link;
typedef struct { u8 unk_00[0x14]; u8 unk_14[1]; } Res;
typedef struct Obj {
    s32 unk_000; Table *table; u8 unk_008[0x2E7 - 0x8]; u8 idx; u8 unk_2E8[0x418 - 0x2E8];
    u8 node[0x50C - 0x418]; Link link; u8 unk_514[0xC]; u8 unk_520[0x744 - 0x520]; u8 unk_744[0x6970 - 0x744];
    Res *res;
} Obj;
extern u8 D_800813A8[];
extern u8 D_80076540[];
void func_800AC37C(void *a, void *b);
void func_800AC334(void *a);
void func_800A97D4(void *a, Ent *e, void *b, void *c);
void func_800A9B78(void *a, void *b, s32 c, s32 d, s32 e);
void func_800B3870(void *a, void *b, s32 n);
void func_80126E5C(Obj *o) {
    Res *r;
    Link *l;
    void *node = o->node;
    Table *t = o->table;
    func_800AC37C(node, o);
    func_800A97D4(node, &t->ent[o->idx], D_800813A8, D_80076540);
    func_800A9B78(node, o->res, 0, 1, 2);
    r = o->res;
    func_800B3870(o->unk_520, r->unk_14, 0x4C);
    l = &o->link;
    if (l->unk_04 != NULL)
        func_800AC334(l);
    func_800AC37C(l, r);
    func_800A9B78(node, o->unk_744, 1, 1, 2);
}
