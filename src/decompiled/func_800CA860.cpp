#include "sydney_types.h"

/* Constructor: base init, vtable, four arrays of entries, a child object, whose type id is 0x3E. */
struct Base {
    s32 type;
    u8 unk_04[0xAC];
    u8 unk_B0;
    u8 unk_B1[3];
    Base() __asm__("func_800AC3D4");
    virtual void v0() __asm__("func_80000010");
};
struct Entry {
    u8 unk_00[0xD4];
    Entry() __asm__("func_800ADED4");
};
struct ChildBase {
    s32 type;
    u8 unk_04[0xAC];
    u8 unk_B0;
    u8 unk_B1[3];
    ChildBase() __asm__("func_800ADE10");
    virtual void v0() __asm__("func_80000010");
};
struct Child : ChildBase {
    u8 unk_B8[0xD4 - 0xB8];
    s16 unk_D4;
    s16 unk_D6;
    s16 unk_D8;
    Child() {
        type = 0x3E;
        unk_B0 = 1;
        unk_D6 = -1;
        unk_D8 = -1;
        unk_D4 = 4;
    }
    virtual void v0() __asm__("func_80000010");
};
struct Obj : Base {
    u8 unk_B8[4];
    Entry unk_BC[3];
    Entry unk_338[3];
    Entry unk_5B4[2];
    Entry unk_75C[5];
    Child child;
    Obj();
    virtual void v0() __asm__("func_80000010");
};
Obj::Obj() {
}
