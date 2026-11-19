#include "sydney_types.h"

/* Constructor-like init: base init, vtable, two sub-objects, type id 0x24; returns the object. */
typedef struct Obj { s32 type; u8 unk_04[0xB0]; void *vtbl; u8 unk_B8[0xF14-0xB8]; s32 unk_F14;
  u8 unk_F18[0x42F0-0xF18]; f32 unk_42F0; u8 unk_42F4[0x14]; u8 sub1[0x43DC-0x4308]; u8 sub2[0x44B4-0x43DC]; s32 unk_44B4; } Obj;
extern u8 D_80070948[];
extern f32 D_800709A4;
void func_80081C40(Obj *o);
void func_800ADED4(void *p);
Obj *func_800C1AC0(Obj *o) {
    register Obj *p __asm__("$2");
    func_80081C40(o);
    o->vtbl = D_80070948;
    func_800ADED4(o->sub1);
    func_800ADED4(o->sub2);
    __asm__("" : "=r"(p) : "0"(o));
    p->type = 0x24;
    p->unk_44B4 = 0;
    p->unk_F14 = 0;
    p->unk_42F0 = D_800709A4;
    return p;
}
