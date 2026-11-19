#include "sydney_types.h"

/* Derived-object constructor: base init, set vtable, init sub-object at 0x198, clear fields, type id 0x67; returns obj. */
typedef struct Obj {
    s32 type; u8 pad4[0xB0]; void *vtbl; u8 padB8[0x198 - 0xB8]; u8 unk198[0x1F4 - 0x198];
    s32 unk1F4; s32 unk1F8; s32 unk1FC; s32 pad200[2]; s32 unk208; s32 unk20C;
} Obj;
extern char D_8008A858[];
extern Obj *func_800BA1FC(Obj *obj);
extern void func_800AED80(void *sub);
Obj *func_800D9360(Obj *obj)
{
    register Obj *p __asm__("$2");

    func_800BA1FC(obj);
    obj->vtbl = D_8008A858;
    func_800AED80(obj->unk198);
    p = obj;
    p->unk1F4 = 0;
    p->unk1F8 = 0;
    p->unk1FC = 0;
    p->unk208 = 0;
    p->unk20C = 0;
    p->type = 0x67;
    return p;
}
