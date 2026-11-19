#include "sydney_types.h"

/* Constructor of an event object derived from the 0xD4-byte entry class: sets type 0x4B and clears fields (C++). */
struct Base { s32 unk_00; u8 pad04[0xB0]; Base() __asm__("func_800ADED4"); virtual void v0() __asm__("func_80000010"); };
struct Obj : Base {
    u8 padB8[0x34];
    s32 unk_EC, unk_F0, unk_F4, unk_F8, unk_FC;
    s16 unk_100, unk_102;
    Obj();
    virtual void v0() __asm__("func_80000010");
};
Obj::Obj() {
    unk_00 = 0x4B;
    unk_EC = 0; unk_F0 = 0; unk_F4 = 0; unk_F8 = 0; unk_FC = 0;
    unk_100 = 0; unk_102 = 0;
}
