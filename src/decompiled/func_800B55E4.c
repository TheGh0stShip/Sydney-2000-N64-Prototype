#include "sydney_types.h"

/* Plays a sound for the first inactive slot's kind, or a mode-dependent default sound. */
typedef struct {
    s8 unk_0;
    u8 unk_1;
    u8 pad2[6];
    s8 unk_8;
    u8 pad9[3];
} Slot;
typedef struct {
    u8 pad0[0x20];
    u8 unk_20;
    u8 pad21[0x3C - 0x21];
} Kind;
typedef struct {
    Kind kinds[(0xA00) / 0x3C];
    u8 padA00_[0xA00 - (0xA00 / 0x3C) * 0x3C];
    s32 unk_A00;
    u8 padA04[0xA0C - 0xA04];
    u8 unk_A0C;
    u8 padA0D[3];
    Slot unk_A10[1];
} World;
typedef struct {
    u8 pad0[0x5B7F];
    u8 unk_5B7F;
} Game;
extern World *D_800FC270;
extern u8 D_800F3BC0[];
extern void func_800C0110(void *, s32, s32, s32);
static inline void play(Game *game, s32 sound) {
    if ((u8)(game->unk_5B7F - 3) >= 2) {
        func_800C0110(D_800F3BC0, sound, 0x1E00, 0x5A00);
    }
}
void func_800B55E4(Game *game) {
    s32 sound = -1;
    s32 extra = -1;
    u32 i;
    s32 cls;
    Slot *slots = D_800FC270->unk_A10;

    for (i = 0; i < D_800FC270->unk_A0C; i++) {
        if (slots[i].unk_8 == 0) {
            break;
        }
    }
    if (i != D_800FC270->unk_A0C) {
        if (slots[i].unk_0 != 8) {
            cls = D_800FC270->kinds[slots[i].unk_0].unk_20;
        } else {
            cls = 3;
        }
        if (cls == 3) {
            sound = 100;
            extra = slots[i].unk_1;
        }
    }
    if (sound != -1) {
        play(game, sound + extra);
    } else {
        switch (D_800FC270->unk_A00) {
            case 0:
                play(game, 0xA4);
                break;
            case 1:
                play(game, 0xA6);
                break;
            case 2:
                play(game, 0xA8);
                break;
        }
    }
}
