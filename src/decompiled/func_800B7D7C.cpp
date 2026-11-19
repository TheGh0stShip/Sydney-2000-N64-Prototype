#include "sydney_types.h"

/* Constructor: base init, vtable, two entry members, then type id 0x1F and cleared fields. */
struct Base {
    s32 type;
    u8 unk_04[0xB0];
    Base() __asm__("func_80081C40");
    virtual void v0() __asm__("func_80000010");
};
struct Entry {
    u8 unk_00[0xD4];
    Entry() __asm__("func_800ADED4");
};
extern f32 D_80070974;
struct Obj : Base {
    u8 unk_B8[0xF14 - 0xB8];
    s32 unk_F14;
    u8 unk_F18[0x42F0 - 0xF18];
    f32 unk_42F0;
    u8 unk_42F4[0x4308 - 0x42F4];
    Entry unk_4308;
    Entry unk_43DC;
    s32 unk_44B0;
    Obj();
    virtual void v0() __asm__("func_80000010");
};
Obj::Obj() {
    type = 0x1F;
    unk_44B0 = 0;
    unk_F14 = 0;
    unk_42F0 = D_80070974;
}
