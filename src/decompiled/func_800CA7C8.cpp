#include "sydney_types.h"

/* Constructor of an event object with 20 sub-entries (C++). */
struct Base { s32 unk_00; u8 pad04[0xB0]; Base() __asm__("func_800AC3D4"); virtual void v0() __asm__("func_80000010"); };
struct Entry { u8 pad[0xD4]; Entry() __asm__("func_800ADED4"); };
struct Zero { s32 v; Zero() { v = 0; } };
struct Obj : Base {
    Zero unk_B8;
    Entry entries[20];
    u8 pad114C[0xA0];
    s32 unk_11EC, unk_11F0, unk_11F4, unk_11F8, unk_11FC, unk_1200, unk_1204;
    Obj();
    virtual void v0() __asm__("func_80000010");
};
Obj::Obj() {
    unk_11EC = 0; unk_11F0 = 0; unk_11F4 = 0; unk_11F8 = 0; unk_11FC = 0; unk_1200 = 0; unk_1204 = 0;
    unk_00 = 0x31;
}
