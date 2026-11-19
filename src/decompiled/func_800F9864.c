#include "sydney_types.h"

/* Picks a value (interpolated between a and b, or a default) and stores and applies it. */
typedef struct { u8 pad[0x278]; f32 unk_278; u8 pad2[0x320-0x27C]; f32 unk_320; u8 pad3[0xC]; f32 unk_330; } Obj;
void func_800B8C70(Obj *o, f32 v);
extern f32 D_80078B90;
void func_800F9864(Obj *o, f32 a, f32 b) {
    f32 t = o->unk_330;
    t *= o->unk_320;
    if (t > 0.0f) {
        t *= b - a;
        t += a;
    } else {
        t = D_80078B90;
    }
    o->unk_278 = t;
    func_800B8C70(o, t);
}
