#include "sydney_types.h"

/* Constructor: base init, vtable, then default state. */
struct Base { s32 unk_00; u8 pad04[0xB0]; Base() __asm__("func_800AC3D4"); virtual void v0() __asm__("func_80000010"); };
struct Obj : Base {
    s32 unk_B8, unk_BC, unk_C0;
    Obj();
    virtual void v0() __asm__("func_80000010");
};
Obj::Obj() {
    unk_C0 = 0x1B;
    unk_B8 = 0;
    unk_BC = 0;
    unk_00 = 0xF;
}
