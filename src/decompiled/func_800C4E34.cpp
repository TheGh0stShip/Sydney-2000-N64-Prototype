#include "sydney_types.h"

/* Constructor of an event object (C++). */
extern "C" { extern f32 D_80070918; }
struct Base {
    s32 unk_0;
    u8 pad4[0xB0];
    Base() __asm__("func_80081C40");
    virtual void v0() __asm__("func_80000010");
};
struct Member { u8 pad[0xD4]; Member() __asm__("func_800ADED4"); };
struct Obj : Base {
    u8 padB8[0xF14 - 0xB8];
    s32 unk_F14;
    u8 padF18[0x42F0 - 0xF18];
    f32 unk_42F0;
    u8 pad42F4[0x4300 - 0x42F4];
    Member unk_4300;
    s32 unk_43D4;
    Obj();
    virtual void v0() __asm__("func_80000010");
};
Obj::Obj() {
    unk_0 = 0x27;
    unk_43D4 = 0;
    unk_F14 = 0;
    unk_42F0 = D_80070918;
}
