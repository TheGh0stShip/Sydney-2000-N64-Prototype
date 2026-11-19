#include "sydney_types.h"

/* Calls a reset routine, sets a mode word to 0x27, and starts a handler with it. */
extern void func_800E98B0(void);
extern void func_800B18BC(s32, void *, s32, s32, s32, s32);
extern u8 D_800FE204[];
extern s32 D_800FE224;

s32 func_800E50CC(s32 arg0) {
    func_800E98B0();
    D_800FE224 = 0x27;
    func_800B18BC(arg0, D_800FE204, 1, 1, 0, 0);
    return 0x27;
}
