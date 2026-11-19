#include "sydney_types.h"

/* Constructor-like init: base init, vtable, two arrays of sub-objects and one more; type id 0x31. */
typedef struct { u8 unk_00[0xD4]; } SubA;
typedef struct { u8 unk_00[0xE0]; } SubB;
typedef struct Obj { s32 type; u8 unk_04[0xB0]; void *vtbl; s16 unk_B8; s16 unk_BA; SubA a[2]; s32 unk_264; SubB b[6]; u8 c[1]; } Obj;
extern u8 D_80088CE0[];
void func_800AC3D4(Obj *o);
void func_800ADED4(void *p);
Obj *func_800C9510(Obj *o) {
    register Obj *p __asm__("$2");
    SubA *a;
    SubB *b;
    s32 i;
    func_800AC3D4(o);
    o->vtbl = D_80088CE0;
    for (a = o->a, i = 1; i != -1; i--, a++)
        func_800ADED4(a);
    for (b = o->b, i = 5; i != -1; i--, b++)
        func_800ADED4(b);
    func_800ADED4(o->c);
    __asm__("" : "=r"(p) : "0"(o));
    p->type = 0x31;
    p->unk_B8 = 0;
    p->unk_BA = 0;
    return p;
}
