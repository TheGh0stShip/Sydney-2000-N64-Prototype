#include "sydney_types.h"

/* Initialises an object: base init, then sets its handler, state 0x47 and an active flag. */
typedef struct Obj { s32 unk_00; u8 pad[0xAD]; s8 unk_B1; u8 pad2[2]; void *unk_B4; } Obj;
extern void func_800ADE10(Obj *);
extern s32 D_800898F0;
Obj *func_800CCEAC(Obj *arg0) {
    register Obj *o __asm__("$2");
    func_800ADE10(arg0);
    o = arg0;
    o->unk_B4 = &D_800898F0;
    o->unk_00 = 0x47;
    o->unk_B1 = 1;
    return o;
}
