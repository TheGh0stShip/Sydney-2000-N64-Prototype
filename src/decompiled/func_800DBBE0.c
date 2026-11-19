#include "sydney_types.h"

/* In state 7, advances by sub-state 0x615: plays a sound/animation step and moves to state 8. */
typedef struct {
    u8 unk_000[0x45C];
    u8 unk_45C[0x60F - 0x45C];
    u8 unk_60F;
    u8 unk_610[5];
    u8 unk_615;
    u8 unk_616[0x6164 - 0x616];
    s32 unk_6164;
} Obj;
void func_80076564(Obj *, s32, s32, s32);
void func_800A9BE8(void *, s32);

void func_800DBBE0(Obj *obj) {
    if (obj->unk_60F == 7) {
        switch (obj->unk_615) {
            case 0:
            case 1:
                func_80076564(obj, 0x31, 0, 0);
            case 5:
                func_800A9BE8(obj->unk_45C, 5);
                obj->unk_6164 = 0x6900;
                obj->unk_60F = 8;
                break;
            case 2:
            case 3:
            case 4:
                func_800A9BE8(obj->unk_45C, 0x13);
                obj->unk_6164 = 0x6900;
                obj->unk_60F = 8;
                break;
            default:
                obj->unk_60F = 8;
                break;
        }
    }
}

