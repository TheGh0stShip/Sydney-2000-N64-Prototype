#include "sydney_types.h"

/* Updates the shared flag block and reacts to its status bits. */
typedef struct { u8 unk_00[3]; u8 unk_03; } Flags;
typedef struct { u8 b[4]; } Arg4;
extern Flags D_800F2AD0;
extern u8 D_800F26E0[];
extern s32 D_800F2744;
extern u8 D_800F4D00[];
void func_800BC07C(Flags *, u8);
void func_800AACB0(void *, s32, s32);
void func_800AB2A4(void *, s32, s32, s32, s32, s32);
void func_800D51A4(void *, s32, s32);

void func_80123D10(s32 arg0, Arg4 arg1) {
    func_800BC07C(&D_800F2AD0, arg1.b[1]);
    if (D_800F2AD0.unk_03 & 4) {
        func_800AACB0(D_800F26E0, arg0, 0);
        func_800AB2A4(D_800F26E0, D_800F2744, 7, arg0, 0, 0x39);
    } else if (D_800F2AD0.unk_03 & 2) {
        func_800D51A4(D_800F4D00, 0, -1);
    } else if (D_800F2AD0.unk_03 & 0x10) {
        func_800D51A4(D_800F4D00, 2, -1);
    }
}
