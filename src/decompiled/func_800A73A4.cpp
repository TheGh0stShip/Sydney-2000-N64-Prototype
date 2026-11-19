#include "sydney_types.h"

/* Constructor: base init, vtable, member object at 0xD0, then clears state and sets the type to 8. */
extern f32 D_800858C8;
struct Base { s32 unk_00; u8 pad04[0xB0]; Base() __asm__("func_800AC3D4"); virtual void v0() __asm__("func_80000010"); };
struct Member { u8 pad[4]; Member() __asm__("func_800ADED4"); };
struct Obj : Base {
    f32 unk_B8;
    s32 unk_BC;
    s32 unk_C0;
    s32 unk_C4;
    u8 unk_C8;
    s32 unk_CC;
    Member unk_D0;
    Obj();
    virtual void v0() __asm__("func_80000010");
};
Obj::Obj() {
    unk_B8 = D_800858C8;
    unk_00 = 8;
    unk_BC = 0;
    unk_C0 = 0;
    unk_CC = 0;
    unk_C4 = 0;
    unk_C8 = 0;
}
