#include "sydney_types.h"

/* Sets up a results panel and its ten sprite layers (bars and frames). */
typedef struct PanelItem {
    s32 sprite;
    u8 unk_04[0xD4 - 4];
} PanelItem;

typedef struct Panel {
    s32 state;
    u8 unk_0004[0x608 - 4];
    s32 sprites[10];
    u8 panel[0xC34 - 0x630];
    PanelItem items[10];
    u8 unk_147C[0x148C - 0x147C];
    s32 unk_148C;
} Panel;

void func_800CE604(s32 a, s32 b);
void func_800CCEF0(void *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, f32 x, s32 g, s32 h, s32 i);
void func_8001A330(s32 *sprite, s32 mask);
void func_8001A1D8(s32 *sprite, f32 a, f32 b, f32 c, f32 d);
void func_8001A210(s32 *sprite, f32 a, f32 b, f32 c, f32 d, s32 e);
void func_800191E0(s32 *sprite, u32 color);

void func_80097B1C(Panel *p, f32 x, s32 arg2) {
    p->unk_148C = 0;
    func_800CE604(0x2B, 0xF);
    func_800CCEF0(p->panel, 0x12, 0xC8, 0, 0x67, 0xF, 2, x, 0, 0, arg2);

    p->sprites[0] = 0;
    func_8001A330(&p->sprites[0], 0xFFFF);
    func_8001A1D8(&p->sprites[0], 0.0f, 1.0f, 602.0f, 15.0f);
    func_8001A210(&p->sprites[0], 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&p->sprites[0], 0x82000000);
    p->items[0].sprite = p->sprites[0];

    p->sprites[1] = 0;
    func_8001A330(&p->sprites[1], 0xFFFF);
    func_8001A1D8(&p->sprites[1], 0.0f, 0.0f, 602.0f, 1.0f);
    func_8001A210(&p->sprites[1], 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&p->sprites[1], 0xFF000000);
    p->items[1].sprite = p->sprites[1];

    p->sprites[2] = 0;
    func_8001A330(&p->sprites[2], 0xFFFF);
    func_8001A1D8(&p->sprites[2], 0.0f, 15.0f, 602.0f, 16.0f);
    func_8001A210(&p->sprites[2], 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&p->sprites[2], 0xFF000000);
    p->items[2].sprite = p->sprites[2];

    p->sprites[3] = 0;
    func_8001A330(&p->sprites[3], 0xFFFF);
    func_8001A1D8(&p->sprites[3], 0.0f, 1.0f, 451.0f, 18.0f);
    func_8001A210(&p->sprites[3], 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&p->sprites[3], 0x82000000);
    p->items[3].sprite = p->sprites[3];

    p->sprites[4] = 0;
    func_8001A330(&p->sprites[4], 0xFFFF);
    func_8001A1D8(&p->sprites[4], 0.0f, 0.0f, 451.0f, 1.0f);
    func_8001A210(&p->sprites[4], 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&p->sprites[4], 0xFF000000);
    p->items[4].sprite = p->sprites[4];

    p->sprites[5] = 0;
    func_8001A330(&p->sprites[5], 0xFFFF);
    func_8001A1D8(&p->sprites[5], 0.0f, 18.0f, 451.0f, 19.0f);
    func_8001A210(&p->sprites[5], 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&p->sprites[5], 0xFF000000);
    p->items[5].sprite = p->sprites[5];

    p->sprites[6] = 0;
    func_8001A330(&p->sprites[6], 0xFFFF);
    func_8001A1D8(&p->sprites[6], 1.0f, 1.0f, 188.0f, 15.0f);
    func_8001A210(&p->sprites[6], 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&p->sprites[6], 0x82000000);
    p->items[6].sprite = p->sprites[6];

    p->sprites[7] = 0;
    func_8001A330(&p->sprites[7], 0xFFFF);
    func_8001A1D8(&p->sprites[7], 1.0f, 0.0f, 188.0f, 1.0f);
    func_8001A210(&p->sprites[7], 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&p->sprites[7], 0xFF000000);
    p->items[7].sprite = p->sprites[7];

    p->sprites[8] = 0;
    func_8001A330(&p->sprites[8], 0xFFFF);
    func_8001A1D8(&p->sprites[8], 1.0f, 15.0f, 188.0f, 16.0f);
    func_8001A210(&p->sprites[8], 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&p->sprites[8], 0xFF000000);
    p->items[8].sprite = p->sprites[8];

    p->sprites[9] = 0;
    func_8001A330(&p->sprites[9], 0xFFFF);
    func_8001A1D8(&p->sprites[9], 0.0f, 0.0f, 1.0f, 16.0f);
    func_8001A210(&p->sprites[9], 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&p->sprites[9], 0xFF000000);
    p->state = 1;
    p->items[9].sprite = p->sprites[9];
}
