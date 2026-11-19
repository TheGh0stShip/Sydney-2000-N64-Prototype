#include "sydney_types.h"

/* Constructor of an object with five sub-entries (C++). */
struct Base { s32 unk_00; u8 pad04[0xB0]; Base() __asm__("func_800AC3D4"); virtual void v0() __asm__("func_80000010"); };
struct Entry { u8 pad[0xD4]; Entry() __asm__("func_800ADED4"); };
struct Obj : Base {
    s32 unk_B8;
    Entry entries[5];
    s32 unk_4E0;
    u8 pad4E4[0x3C];
    s32 unk_520, unk_524;
    Obj();
    virtual void v0() __asm__("func_80000010");
};
Obj::Obj() {
    unk_00 = 8;
    unk_B8 = 0;
    unk_4E0 = 0;
    unk_520 = 0;
    unk_524 = 0;
}
