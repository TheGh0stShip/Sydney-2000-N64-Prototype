#include "sydney_types.h"

/* Constructor: base init, vtable, one member object at 0x104, then type id 0x39. */
struct Base {
    s32 type;
    u8 unk_04[0xB0];
    Base() __asm__("func_800AC3D4");
    virtual void v0() __asm__("func_80000010");
};
struct Member {
    u8 unk_00[4];
    Member() __asm__("func_800A03F8");
};
struct Obj : Base {
    u8 unk_B8[0x104 - 0xB8];
    Member unk_104;
    Obj();
    virtual void v0() __asm__("func_80000010");
};
Obj::Obj() {
    type = 0x39;
}
