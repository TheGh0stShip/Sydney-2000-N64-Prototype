#include "sydney_types.h"

/* Constructor: base init, then type 0x40 and cleared members (C++). */
struct Base { s32 unk_00; u8 pad04[0xA8]; s32 unk_AC; u8 padB0[4]; Base() __asm__("func_800ADE10"); virtual void v0() __asm__("func_80000010"); };
struct Obj : Base {
    u8 padB8[0xC4 - 0xB8];
    s32 unk_C4;
    u8 padC8[0xDC - 0xC8];
    s32 unk_DC;
    s32 unk_E0;
    Obj();
    virtual void v0() __asm__("func_80000010");
};
Obj::Obj() {
    unk_00 = 0x40;
    unk_DC = 0;
    unk_E0 = 0;
    unk_AC = 0;
    unk_C4 = 0;
}
