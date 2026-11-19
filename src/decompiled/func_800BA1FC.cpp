#include "sydney_types.h"

/* Constructor: base init, vtable, cleared fields, type 0x5A, clears block at 0xF4, zeroed vectors. */
struct Base { s32 unk_00; u8 pad04[0xB0]; Base() __asm__("func_800ADED4"); virtual void v0() __asm__("func_80000010"); };
struct Zero { s32 v; Zero() { v = 0; } };
struct Vec3i { s32 x, y, z; };
extern "C" { void func_800B3AFC(void *p, s32 c, s32 n); }
static inline void Vec_Zero(Vec3i *v) { v->x = 0; v->y = 0; v->z = 0; }
struct Obj : Base {
    u8 padB8[0x20];
    Zero unk_D8, unk_DC, unk_E0, unk_E4, unk_E8;
    s32 unk_EC;
    s32 pad_F0;
    u8 unk_F4[0x24];
    s32 unk_118, unk_11C;
    u8 pad120[0xC];
    s16 unk_12C, unk_12E;
    u8 pad130[0x18];
    Zero unk_148;
    s32 pad14C;
    Zero unk_150, unk_154, unk_158, unk_15C, unk_160;
    s32 pad164;
    s32 unk_168, unk_16C;
    Vec3i unk_170;
    Vec3i unk_17C;
    Vec3i unk_188;
    Obj();
    virtual void v0() __asm__("func_80000010");
};
Obj::Obj() {
    unk_00 = 0x5A;
    unk_168 = 0;
    unk_16C = 0;
    unk_EC = 0;
    func_800B3AFC(unk_F4, 0, 0x54);
    unk_12E = -1;
    unk_12C = -1;
    unk_118 = 0;
    unk_11C = 0;
    Vec_Zero(&unk_188);
    Vec_Zero(&unk_170);
    Vec_Zero(&unk_17C);
}
