#include "sydney_types.h"

/* Plays one of several sounds depending on mode flags, if sound is enabled. */
typedef struct Sub {
    u8 unk_000[0x2FC];
    s32 unk_2FC;
    s32 unk_300;
    u8 unk_304[0xC];
    s32 unk_310;
} Sub;

typedef struct Game {
    u8 unk_0000[0x59CC];
    Sub *sub;
    u8 unk_59D0[0x75AB - 0x59D0];
    u8 unk_75AB;
} Game;

typedef struct Cfg {
    u8 unk_000[0xA04];
    s32 unk_A04;
} Cfg;

extern Cfg *D_800FC270;
extern u8 D_800F3BC0[];
void func_800C0110(void *bank, s32 id, s32 arg2, s32 arg3);

void func_80094A54(Game *game) {
    Sub *sub;

    if (game->unk_75AB < 2) {
        sub = game->sub;
        if (sub->unk_2FC == 0) {
            if (sub->unk_310 == 1) {
                if (D_800FC270->unk_A04 != 0) {
                    func_800C0110(D_800F3BC0, 0xBF, 0, 0x5A00);
                }
            } else if (D_800FC270->unk_A04 != 0) {
                func_800C0110(D_800F3BC0, 0xC2, 0, 0x5A00);
            }
        } else if (sub->unk_300 == 1) {
            if (D_800FC270->unk_A04 != 0) {
                func_800C0110(D_800F3BC0, 0xC4, 0, 0x5A00);
            }
        } else if (D_800FC270->unk_A04 != 0) {
            func_800C0110(D_800F3BC0, 0xC3, 0, 0x5A00);
        }
    }
}
