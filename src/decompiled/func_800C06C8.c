#include "sydney_types.h"

/* Constructor-like init: base init, handler table, init four parts and a trailer, type id 8. */
typedef struct Part { u8 unk_00[0xD4]; } Part;
typedef struct Obj {
    s32 type;
    u8 unk_04[0xB0];
    void *handler;
    u8 unk_B8;
    u8 unk_B9[3];
    Part parts[4];
    u8 unk_40C[4];
} Obj;
extern u8 D_80088298[];
Obj *func_800AC3D4(Obj *o);
void func_800ADE10(void *p);

Obj *func_800C06C8(Obj *o) {
    Obj *p;
    s32 i;
    Part *pp;
    func_800AC3D4(o);
    o->handler = D_80088298;
    pp = o->parts; i = 3; do { func_800ADE10(pp); i--; pp++; } while (i != -1);
    func_800ADE10(o->unk_40C);
    p = o;
    p->type = 8;
    p->unk_B8 = 1;
    return p;
}
