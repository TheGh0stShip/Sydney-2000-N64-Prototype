#include "sydney_types.h"

/* Constructor-like init: base init, then set handler table and type id 0x3A. */
typedef struct Obj {
    s32 type;
    u8 unk_04[0xB0];
    void *handler;
    s32 unk_B8;
    s32 unk_BC;
} Obj;
extern u8 D_8008C140[];
Obj *func_800AC3D4(Obj *o);

Obj *func_800EA560(Obj *o) {
    Obj *p;
    func_800AC3D4(o);
    p = o;
    p->handler = D_8008C140;
    p->unk_B8 = 0;
    p->unk_BC = 0;
    p->type = 0x3A;
    return p;
}
