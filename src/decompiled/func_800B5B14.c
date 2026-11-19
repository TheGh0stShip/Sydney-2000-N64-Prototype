#include "sydney_types.h"

/* Play the commentary line for the player's result, chosen by game mode, result class and player kind. */
typedef struct { u8 pad[0x1AA]; u8 kind; } Player;
typedef struct { u8 pad[0xA04]; s32 mode; } Game;
typedef struct {
    u8 pad[0x532C];
    Player *player;
    u8 pad5330[0x5B7A - 0x5330];
    u8 unk_5B7A;
    u8 pad5B7B[4];
    u8 unk_5B7F;
} Race;
extern Game *D_800FC270;
extern u8 D_800F3BC0[];
void func_800DA804(s32, s32, u8 *, s32, s32);
s8 func_8009B670(Player *);
void func_800C0110(void *, s32, s32, s32);
static inline void say(Race *r, s32 id) {
    if (r->unk_5B7F != 3 && r->unk_5B7F != 4) func_800C0110(D_800F3BC0, id, 0, 0);
}
void func_80076944(Race *r) {
    u8 buf[0x80];
    s8 res;
    u8 cls;
    u8 side;
    func_800DA804(0, 0, buf, 0, 0);
    if (D_800FC270->mode == 2 && r->unk_5B7A == 0) return;
    res = func_8009B670(r->player);
    if ((u8)res < 3) cls = res;
    else if ((u8)(res - 3) < 3) cls = 3;
    else if ((u8)(res - 6) < 6) cls = 4;
    else cls = 5;
    if (D_800FC270->mode == 2 || (D_800FC270->mode == 3 && r->unk_5B7A == 0)) {
        switch (cls) {
        case 0: say(r, 0x1C5); break;
        case 1: say(r, 0x1C6); break;
        case 2: say(r, 0x1C7); break;
        case 3: say(r, 0x1C8); break;
        case 4: say(r, 0x1C9); break;
        case 5: say(r, 0x1CA); break;
        }
    } else if (D_800FC270->mode == 3) {
        side = r->player->kind != 3;
        switch (cls) {
        case 0: if (side) say(r, 0x1CC); else say(r, 0x1CB); break;
        case 1: if (side) say(r, 0x1CE); else say(r, 0x1CD); break;
        case 2: if (side) say(r, 0x1D0); else say(r, 0x1CF); break;
        case 3: if (side) say(r, 0x1D2); else say(r, 0x1D1); break;
        case 4: if (side) say(r, 0x1D4); else say(r, 0x1D3); break;
        case 5: if (side) say(r, 0x1D6); else say(r, 0x1D5); break;
        }
    } else {
        switch (res) {
        case 0: say(r, 0x1D7); break;
        case 1: say(r, 0x1D8); break;
        case 2: say(r, 0x1D9); break;
        case 3: say(r, 0x1DA); break;
        case 4: say(r, 0x1DB); break;
        case 5: say(r, 0x1DC); break;
        }
    }
}
