#include "sydney_types.h"

/* Constructor-like init: base init, vtable, sub-object init, type id 0x51; returns the object. */
typedef struct Obj { s32 type; u8 unk_04[0xB0]; void *vtbl; u8 unk_B8[0x3C]; u8 sub[1]; } Obj;
extern u8 D_80084DC8[];
void func_800ADED4(Obj *o);
void func_800A03F8(void *p);
Obj *func_800A1028(Obj *o) {
    register Obj *p __asm__("$2");
    func_800ADED4(o);
    o->vtbl = D_80084DC8;
    func_800A03F8(o->sub);
    __asm__("" : "=r"(p) : "0"(o));
    p->type = 0x51;
    return p;
}
