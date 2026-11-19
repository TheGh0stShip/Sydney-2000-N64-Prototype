#include "sydney_types.h"

/* Constructor: base Entry init, vtable, member at 0xF0, type 0x51. */
struct Base { s32 unk_00; u8 pad04[0xB0]; Base() __asm__("func_800ADED4"); virtual void v0() __asm__("func_80000010"); };
struct Member { u8 pad[4]; Member() __asm__("func_800A03F8"); };
struct Obj : Base {
    u8 padB8[0x38];
    Member unk_F0;
    Obj();
    virtual void v0() __asm__("func_80000010");
};
Obj::Obj() {
    unk_00 = 0x51;
}
