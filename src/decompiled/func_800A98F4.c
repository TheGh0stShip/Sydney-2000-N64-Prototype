#include "sydney_types.h"

/* Advances a scene by its state byte: starts a sub-sequence, then sets state 4 and plays sound 0xBA. */
typedef struct Snd { u8 p[0x68]; s32 volume; } Snd;
typedef struct Cfg { u8 p[0x1C]; s32 unk_1C; } Cfg;
typedef struct Scene {
    u8 p0[0x2B8]; u8 unk_2B8[0x1C2C - 0x2B8]; s32 unk_1C2C;
    u8 p1[0x790C - 0x1C30]; s32 unk_790C;
    u8 p2[0x7F6C - 0x7910]; u8 unk_7F6C[0x811D - 0x7F6C]; u8 unk_811D; u8 unk_811E;
    u8 p3[0x812C - 0x811F]; s32 unk_812C; s32 unk_8130; s32 unk_8134;
} Scene;
extern void func_800A9BE8(void *, s32);
extern void func_80077454(Scene *, s32, s32, s32);
extern void func_800D33A0(void *, Cfg *, s32, s32);
extern s32 func_8001D4B8(Snd *, s32, s32, s32);
extern void func_8001D640(Snd *, s32, s32);
extern Cfg D_80077C00;
extern Snd D_800F1AE0;
void func_800A98F4(Scene *s) {
    switch (s->unk_811E) {
    case 0:
    case 1:
    case 3:
    case 4:
        func_800A9BE8(s->unk_7F6C, 4);
        break;
    case 2:
        func_800A9BE8(s->unk_7F6C, 0xD);
        s->unk_8134 = 1;
        s->unk_1C2C = 1;
        s->unk_812C = 0x14A00;
        func_80077454(s, 0x1F, 0, 0);
        D_80077C00.unk_1C = s->unk_812C - 0x1E00;
        func_800D33A0(s->unk_2B8, &D_80077C00, 1, -1);
        break;
    case 5:
        func_800A9BE8(s->unk_7F6C, 7);
        break;
    }
    s->unk_811D = 4;
    s->unk_790C = 0x38400;
    if (s->unk_811E != 5) {
        Snd *snd = &D_800F1AE0;
        s32 max = 0x7FFF;
        func_8001D640(snd, func_8001D4B8(snd, 0xBA, 0, 0), (snd->volume * max) >> 15);
    }
}
