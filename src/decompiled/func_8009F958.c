#include "sydney_types.h"

/* Constructor: base init, an embedded derived sub-object (state 0x41), several members, state 0x48. */
typedef struct Base { s32 unk_00; u8 p0[0xB0]; void *unk_B4; u8 p1[0x1C]; } Base;
typedef struct Sub { Base base; s32 unk_D4; s32 unk_D8; s32 unk_DC; u8 p[0x108 - 0xE0]; } Sub;
typedef struct Obj {
    Base base;
    Sub unk_D4;
    Base unk_1DC;
    s32 unk_2B0; s32 unk_2B4; s32 unk_2B8;
    Base unk_2BC;
    u8 p0[0x3A8 - 0x390];
    s32 unk_3A8;
    Base unk_3AC;
    u8 p1[0x4B4 - 0x480];
    u8 unk_4B4[0xA30 - 0x4B4];
    s32 unk_A30; s32 unk_A34;
} Obj;
extern void func_800ADED4(void *);
extern void func_800D28B0(void *);
extern s32 D_800848D0, D_80084B58, D_80084BD8;
Obj *func_8009F958(Obj *arg0) {
    register Obj *o __asm__("$2");
    Sub *s;
    func_800ADED4(arg0);
    s = &arg0->unk_D4;
    arg0->base.unk_B4 = &D_80084B58;
    func_800ADED4(s);
    s->base.unk_B4 = &D_80084BD8;
    s->base.unk_00 = 0x41;
    s->unk_D4 = 0;
    s->unk_DC = 0;
    s->base.unk_B4 = &D_800848D0;
    func_800ADED4(&arg0->unk_1DC);
    arg0->unk_2B0 = 0;
    arg0->unk_2B8 = 0;
    func_800ADED4(&arg0->unk_2BC);
    arg0->unk_3A8 = 0;
    func_800ADED4(&arg0->unk_3AC);
    func_800D28B0(arg0->unk_4B4);
    o = arg0;
    o->unk_A30 = 0;
    o->unk_A34 = 0;
    o->base.unk_00 = 0x48;
    return o;
}
