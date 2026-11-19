#include "sydney_types.h"

/* Constructor: base init, vtable, member at +0xF0, then defaults (C++). */
struct Base { s32 unk_00; u8 pad04[0xAD]; u8 unk_B1; u8 padB2[2]; Base() __asm__("func_800ADE10"); virtual void v0() __asm__("func_80000010"); };
struct Zero { s32 v; Zero() { v = 0; } };
struct Obj : Base {
    u8 padB8[0xD4 - 0xB8];
    s32 unk_D4, unk_D8, unk_DC;
    u8 padE0[0x10];
    Base unk_F0;
    Obj();
    virtual void v0() __asm__("func_80000010");
};
Obj::Obj() {
    unk_00 = 0x54;
    unk_DC = 0;
    unk_D8 = 0;
    unk_D4 = 0;
    unk_B1 = 1;
}
