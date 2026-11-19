#include "sydney_types.h"

/* Constructor of an object with a cleared sub-block and three slots (C++). */
extern "C" { extern f32 D_80085A20; }
struct Base {
    s32 unk_0;
    u8 pad4[0xB0];
    Base() __asm__("func_800AC3D4");
    virtual void v0() __asm__("func_80000010");
};
struct Sub {
    s32 unk_0, unk_4, unk_8, unk_C;
    s16 unk_10, unk_12;
    Sub() { unk_0 = 0; unk_4 = 0; unk_8 = 0; unk_C = 0; unk_10 = 0; unk_12 = 0; }
};
struct Obj : Base {
    s32 unk_B8;
    u8 padBC[0xC9 - 0xBC];
    s8 unk_C9;
    u8 padCA[2];
    Sub unk_CC;
    u8 padE0[0x138 - 0xE0];
    s32 unk_138[3];
    f32 unk_144;
    Obj();
    virtual void v0() __asm__("func_80000010");
};
Obj::Obj() {
    u8 i;

    unk_0 = 8;
    unk_B8 = 0;
    for (i = 0; i < 3; i++) {
        unk_138[i] = 0;
    }
    unk_144 = D_80085A20;
    unk_C9 = 0;
}
