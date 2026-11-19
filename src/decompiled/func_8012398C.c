#include "sydney_types.h"

/* Fades the three panels in (state 2) or out (state 3). */
typedef struct Panel { u8 pad[0x2C]; } Panel;
typedef struct Ctx {
    u8 pad0[0xF08];
    u16 unk_F08;
    u8 padF0A[0x2A80 - 0xF0A];
    Panel panels[3];
    s32 unk_2B04[3];
    u8 pad2B10[0x34C8 - 0x2B10];
    f32 unk_34C8;
    u8 unk_34CC;
} Ctx;
extern f32 D_80081C0C;
extern f32 D_80081C10;
extern f32 D_80081C14;
void func_80083188(Ctx *c, Panel *panel, f32 alpha, s32 a, s32 b);
void func_8012398C(Ctx *c) {
    f32 alpha;
    f32 t;

    switch (c->unk_F08) {
        case 2:
            t = c->unk_34C8;
            alpha = D_80081C0C - t;
            func_80083188(c, &c->panels[0], alpha, c->unk_2B04[0], 0);
            func_80083188(c, &c->panels[1], alpha, c->unk_2B04[1], 0);
            func_80083188(c, &c->panels[2], alpha, c->unk_2B04[2], 0);
            break;
        case 3:
            alpha = D_80081C14 - c->unk_34CC / D_80081C10;
            func_80083188(c, &c->panels[0], alpha, 0, c->unk_2B04[0]);
            func_80083188(c, &c->panels[1], alpha, 0, c->unk_2B04[1]);
            func_80083188(c, &c->panels[2], alpha, 0, c->unk_2B04[2]);
            break;
    }
}
