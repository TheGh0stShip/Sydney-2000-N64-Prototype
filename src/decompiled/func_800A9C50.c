#include "sydney_types.h"

/* Initialises an object: base init, handler table, clears state fields. */
typedef struct Obj {
    u8 pad0[0xB4];
    void *unk_B4;
    s32 unk_B8;
    s32 unk_BC;
    s32 unk_C0;
    s32 unk_C4;
    s32 unk_C8;
    s32 unk_CC;
    s32 unk_D0;
    s32 unk_D4;
    s32 unk_D8;
    u8 padDC[0xE2 - 0xDC];
    s16 unk_E2;
    s16 unk_E4;
    s8 unk_E6;
} Obj;
extern void func_800AC3D4(Obj *obj);
extern u8 D_80085B98[];

Obj *func_800A9C50(Obj *obj) {
    register Obj *ret __asm__("$2"); /* only form found that matches */

    func_800AC3D4(obj);
    ret = obj;
    ret->unk_B4 = D_80085B98;
    ret->unk_B8 = 0;
    ret->unk_BC = 0;
    ret->unk_C0 = 0;
    ret->unk_C4 = 0;
    ret->unk_C8 = 0;
    ret->unk_CC = 0;
    ret->unk_D0 = 0;
    ret->unk_D4 = 0;
    ret->unk_D8 = 0;
    ret->unk_E2 = 0;
    ret->unk_E4 = 0;
    ret->unk_E6 = -1;
    return ret;
}
