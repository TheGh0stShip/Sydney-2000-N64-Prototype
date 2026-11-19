#include "sydney_types.h"

/* Derived-object constructor: base init, then set the class vtable and type id 0x47; returns obj. */
typedef struct Obj { s32 type; u8 pad4[0xB0]; void *vtbl; } Obj;
extern char D_80089AD0[];
extern Obj *func_800ADE10(Obj *obj);
Obj *func_800CE3A8(Obj *obj)
{
    register Obj *p __asm__("$2");

    func_800ADE10(obj);
    p = obj;
    p->vtbl = D_80089AD0;
    p->type = 0x47;
    return p;
}
