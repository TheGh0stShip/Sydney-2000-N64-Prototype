#include "sydney_types.h"

/* Constructor of an object holding one embedded entry (C++). */
struct Base { s32 unk_00; u8 pad04[0xB0]; Base() __asm__("func_800AC3D4"); virtual void v0() __asm__("func_80000010"); };
struct Entry { u8 pad[0xD4]; Entry() __asm__("func_800ADED4"); };
struct Zero { s32 v; Zero() { v = 0; } };
struct Obj : Base {
    s32 unk_B8;
    Zero unk_BC;
    Entry unk_C0;
    s32 unk_194;
    s32 unk_198;
    s32 unk_19C;
    Obj();
    virtual void v0() __asm__("func_80000010");
};
Obj::Obj() {
    unk_194 = 0;
    unk_19C = 0;
    unk_B8 = 0;
    unk_00 = 0x33;
}
