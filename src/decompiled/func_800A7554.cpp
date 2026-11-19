#include "sydney_types.h"

/* Constructor of an object with ten entries and four cleared slots (C++). */
struct Base { s32 unk_00; u8 pad04[0xB0]; Base() __asm__("func_800AC3D4"); virtual void v0() __asm__("func_80000010"); };
struct Entry { u8 pad[0xD4]; Entry() __asm__("func_800ADED4"); };
extern f32 D_80085910;
struct Obj : Base {
    s32 unk_B8;
    s32 unk_BC[4];
    Entry entries[10];
    s32 unk_914;
    f32 unk_918;
    Obj();
    virtual void v0() __asm__("func_80000010");
};
Obj::Obj() {
    u16 i;

    unk_00 = 8;
    unk_B8 = 0;
    for (i = 0; i < 4; i++) {
        unk_BC[i] = 0;
    }
    unk_914 = 0;
    unk_918 = 0.2f;
}
