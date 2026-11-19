#include "sydney_types.h"

/* Counts a timer down; when it runs out, plays the result sound and queues the result message for the current mode. */
typedef struct Game {
    u8 pad0[0xD10];
    s32 unk_D10;
} Game;
typedef struct Sound {
    u8 pad0[0x68];
    s32 unk_68;
} Sound;
typedef struct Entry {
    s32 unk_0;
    s32 unk_4;
} Entry;
typedef struct Obj {
    u8 pad0[0x60F];
    u8 unk_60F;
    u8 pad610[0x615 - 0x610];
    u8 unk_615;
    u8 pad616[0x3254 - 0x616];
    u8 unk_3254[0x38B8 - 0x3254];
    u8 unk_38B8[0x608C - 0x38B8];
    Entry *unk_608C;
    u8 pad6090[0x6164 - 0x6090];
    s32 unk_6164;
    u8 pad6168[0x616C - 0x6168];
    s32 unk_616C;
} Obj;
extern Game *D_800FC270;
extern Sound D_800F1AE0;
extern u8 D_80077534[];
extern u8 D_80077444[];
extern s32 D_80077454;
extern s32 D_80077630;
extern s32 func_8001D4B8(Sound *snd, s32 id, s32 a, s32 b);
extern void func_8001D640(Sound *snd, s32 voice, s32 vol);
extern void func_800A6308(void *p);
extern s32 func_8009B4D4(s32 a, Entry *e, s32 mode, void *p, s32 b, s32 c);
extern void func_800D33A0(void *p, void *msg, s32 a, s32 b);
extern void func_80075998(Obj *obj);
extern void func_80075B78(Obj *obj);

void func_800D6FAC(Obj *obj) {
    f32 f;

    obj->unk_6164 -= 0x100;
    if (obj->unk_6164 > 0) {
        return;
    }
    func_800A6308(obj->unk_38B8);
    switch (obj->unk_615) {
        case 0:
        case 1:
            if (func_8009B4D4(0, obj->unk_608C, obj->unk_615, obj->unk_3254, 2, 0) != 0) {
                func_8001D640(&D_800F1AE0, func_8001D4B8(&D_800F1AE0, 0xDC, 0, 1),
                              (s32)((s64)D_800F1AE0.unk_68 * 0x7FFF) >> 15);
            } else {
                D_80077630 = obj->unk_608C->unk_4;
                func_800D33A0(obj->unk_3254, D_80077534, 1, -1);
            }
            func_80075998(obj);
            break;
        case 3:
            f = (f32)obj->unk_616C / 30.0f * 0.00390625f;
            D_80077630 = *(s32 *)&f;
            func_800D33A0(obj->unk_3254, D_80077534, 1, -1);
            break;
        case 5:
            func_80075B78(obj);
            break;
        case 4:
            if (D_800FC270->unk_D10 >= obj->unk_616C) {
                func_8001D640(&D_800F1AE0, func_8001D4B8(&D_800F1AE0, 0xD5, 0, 1),
                              (s32)((s64)D_800F1AE0.unk_68 * 0x7FFF) >> 15);
                D_80077454 = 0x2A0;
            } else {
                func_8001D640(&D_800F1AE0, func_8001D4B8(&D_800F1AE0, 0x83, 0, 1),
                              (s32)((s64)D_800F1AE0.unk_68 * 0x7FFF) >> 15);
                D_80077454 = 0x2A1;
            }
            D_80077630 = obj->unk_616C;
            func_800D33A0(obj->unk_3254, D_80077444, 0, -1);
            break;
    }
    obj->unk_60F = 0x18;
}
