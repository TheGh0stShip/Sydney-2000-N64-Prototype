#include "sydney_types.h"

/* Advances state 1 to 2 and starts dependent subsystems; otherwise updates the sub-object at 0x3684. */
typedef struct Ctx {
    u8 pad0[0xF08];
    u16 unk_F08;
    u8 padF0A[0x1048 - 0xF0A];
    s32 unk_1048;
    u8 pad104C[0x33F4 - 0x104C];
    u8 unk_33F4[0x3684 - 0x33F4];
    u8 unk_3684[4];
} Ctx;
void func_800ADC38(void *p);
void func_80082FFC(Ctx *c);
void func_800CB1B0(void *p);
void func_800CB160(void *p);
void func_801240E8(Ctx *c) {
    if (c->unk_F08 == 1) {
        c->unk_1048 = 0;
        c->unk_F08 = 2;
        func_800ADC38(c->unk_33F4);
        func_80082FFC(c);
        func_800CB1B0(c->unk_3684);
    } else {
        func_800CB160(c->unk_3684);
    }
}
