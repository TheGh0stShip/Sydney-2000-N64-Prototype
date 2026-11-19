#include "sydney_types.h"

/* Constructor of an object with two embedded entries and a third part (C++). */
struct Base { s32 unk_00; u8 pad04[0xB0]; Base() __asm__("func_800BA1FC"); virtual void v0() __asm__("func_80000010"); };
struct Entry { s32 unk_00; u8 pad04[0xB0]; Entry() __asm__("func_800ADED4"); virtual void v0() __asm__("func_80000014"); };
struct Mid : Entry { u8 pad[0x1C]; s32 unk_D4; u8 pad2[4]; s32 unk_DC; u8 pad3[0x30]; Mid() { unk_00 = 0x41; unk_D4 = 0; unk_DC = 0; } virtual void v0() __asm__("func_80000018"); };
struct Sub : Mid { Sub() {} virtual void v0() __asm__("func_8000001C"); };
struct Zero { s32 v; Zero() { v = 0; } };
struct Part { u8 pad[0x588]; Part() __asm__("func_800D28B0"); };
struct Obj : Base {
    u8 unk_B8[0xDC];
    Sub unk_194;
    Zero unk_2A4;
    Entry unk_2A8;
    u8 pad[0x11C - sizeof(Entry)];
    Part unk_3C4;
    s32 unk_94C;
    Obj();
    virtual void v0() __asm__("func_80000010");
};
Obj::Obj() {
    unk_94C = 0;
    unk_00 = 0x68;
}
