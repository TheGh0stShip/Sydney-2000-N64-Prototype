#include "sydney_types.h"

/* Picks a mode from a state byte, runs func_8007B688 with it and accumulates the result into a per-slot timer. */
typedef struct Slot {
    u8 pad00[6];
    s16 unk_06;
    f32 unk_08;
} Slot;

typedef struct G {
    u8 pad[0xA0C];
    Slot slots[1];
} G;

typedef struct Obj {
    u8 pad0000[0x532C];
    s32 unk_532C;
    u8 pad5330[0x5B78 - 0x5330];
    u8 unk_5B78;
    u8 unk_5B79;
    u8 unk_5B7A;
    u8 unk_5B7B;
} Obj;

extern G *D_800FC270;
void func_800752A4(Obj *obj, s32 arg);
f32 func_8007B688(s32 arg, s32 mode);

void func_800B4A18(Obj *obj) {
    s32 mode = 0;

    if (obj->unk_5B7B == 0) {
        switch (obj->unk_5B78) {
            case 0:
            case 1:
            case 5:
                mode = 3;
                break;
            case 2:
            case 3:
            case 4:
                mode = 4;
                break;
            case 6:
            case 7:
                mode = 2;
                break;
        }
    }
    func_800752A4(obj, 1);
    D_800FC270->slots[obj->unk_5B79].unk_08 += func_8007B688(obj->unk_532C, mode);
    D_800FC270->slots[obj->unk_5B79].unk_06 = (s32) D_800FC270->slots[obj->unk_5B79].unk_08 * 60;
}
