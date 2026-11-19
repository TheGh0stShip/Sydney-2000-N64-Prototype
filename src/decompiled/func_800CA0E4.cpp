#include "sydney_types.h"

/* Constructor (C++): base init, clear record at 0xB8, construct member at 0x16C, clear fields, type id 0x31. */
struct Base { s32 unk_00; u8 pad04[0xB0]; Base() __asm__("func_800AC3D4"); virtual void v0() __asm__("func_80000010"); };
struct Rec { s32 unk0, unk4, unk8, unkC; s16 unk10, unk12;
    Rec() { unk0 = 0; unk4 = 0; unk8 = 0; unkC = 0; unk10 = 0; unk12 = 0; } };
struct Entry { u8 pad[0xD4]; Entry() __asm__("func_800ADED4"); };
struct Obj : Base {
    Rec unk_B8;
    u8 padCC[0x16C - 0xCC];
    Entry unk_16C;
    s32 unk_240, unk_244;
    u8 pad248[0x25C - 0x248];
    s32 unk_25C, unk_260, unk_264, unk_268;
    Obj();
    virtual void v0() __asm__("func_80000010");
};
Obj::Obj() {
    unk_00 = 0x31;
    unk_240 = 0; unk_244 = 0; unk_25C = 0; unk_264 = 0; unk_268 = 0; unk_260 = 0;
}
