#include "sydney_types.h"

/* Initialises a scoreboard panel: creates its sprites for the given layout mode, places its two parts and, if requested, its shadow sprite. */
typedef struct Vec3 { f32 x, y, z; } Vec3;

typedef struct Xform {
    u8 pad00[0x40];
    Vec3 pos;
} Xform;

typedef struct Part {
    u8 pad00[0x60];
    Xform xf;
    u8 padAC[4];
    u8 unk_B0;
    u8 padB1[0xF];
    s32 flags;
    void *sprite;
    u8 padC8;
    u8 unk_C9;
    u8 padCA[0xA];
} Part;

typedef struct Board {
    Part base;
    Part sub;
    void *sprA;
    void *sprB;
    u8 pad1B0[8];
    f32 width;
    f32 invWidth;
    f32 unk_1C0;
    u8 pad1C4[8];
    f32 unk_1CC;
    s32 unk_1D0;
    u8 pad1D4[0xC];
    void *shadow;
} Board;

extern u8 D_80089950[];
extern u8 D_8008995C[];
extern u8 D_80089970[];
extern u8 D_80089980[];
extern u8 D_80089990[];

void func_800191E0(void **spr, s32 color);
void func_80019338(void **spr, s32 a, s32 b, s32 c, s32 d);
void func_80019680(void **spr, u8 *desc);
void func_8001A1D8(void **spr, f32 x, f32 y, f32 w, f32 h);
void func_8001A210(void **spr, f32 a, f32 b, f32 sx, f32 sy, s32 f);
void func_800ADC10(Part *p);
void func_800ADC54(Part *p, s32 a);
void func_800CD74C(Board *b);

static inline void xf_set_pos(Xform *xf, f32 x, f32 y, f32 z) {
    xf->pos.x = x;
    xf->pos.y = y;
    xf->pos.z = z;
}

void func_800CCEF0(Board *b, s16 x, s16 y, s32 unused, s32 unused2, s16 depth, s32 arg, f32 f, s32 n, u32 mode, s32 shadow) {
    Part *sub;

    b->unk_1D0 = n;
    b->unk_1CC = f;
    func_80019680(&b->sprA, D_80089950);
    switch (mode) {
    case 0:
        if (shadow) {
            b->width = 101.0f;
            b->unk_1C0 = 1.01f;
            func_8001A1D8(&b->sprA, 0.0f, 0.0f, 101.0f, 12.0f);
            xf_set_pos(&b->sub.xf, 25.0f, 4.0f, 0.0f);
            func_80019680(&b->sprB, D_8008995C);
            func_8001A1D8(&b->sprB, 0.0f, 0.0f, 131.0f, 19.0f);
        } else {
            b->width = 105.0f;
            b->unk_1C0 = 1.05f;
            func_8001A1D8(&b->sprA, 0.0f, 0.0f, 105.0f, 12.0f);
            xf_set_pos(&b->sub.xf, 6.0f, 4.0f, 0.0f);
            func_80019680(&b->sprB, D_80089970);
            func_8001A1D8(&b->sprB, 0.0f, 0.0f, 191.0f, 19.0f);
        }
        break;
    case 1:
        b->width = 101.0f;
        b->unk_1C0 = 1.01f;
        func_8001A1D8(&b->sprA, 0.0f, 0.0f, 101.0f, 11.0f);
        xf_set_pos(&b->sub.xf, 7.0f, 4.0f, 0.0f);
        func_80019680(&b->sprB, D_80089980);
        func_8001A1D8(&b->sprB, 0.0f, 0.0f, 116.0f, 18.0f);
        break;
    case 2:
        func_80019680(&b->sprB, D_80089980);
        func_8001A1D8(&b->sprB, 0.0f, 0.0f, 116.0f, 18.0f);
        break;
    }
    b->invWidth = 1.0f / b->width;
    func_8001A210(&b->sprA, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&b->sprA, -1);
    sub = &b->sub;
    func_800ADC10(sub);
    sub->unk_C9 = 1;
    sub->flags |= 0x20000;
    func_800ADC54(sub, arg);
    sub->flags |= 2;
    b->sub.sprite = b->sprA;
    func_8001A210(&b->sprB, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&b->sprB, -1);
    b->base.sprite = b->sprB;
    if (!shadow) {
        func_800ADC10(&b->base);
    }
    b->base.unk_C9 = 4;
    b->base.flags |= 0x20000;
    func_800ADC54(&b->base, arg);
    b->base.flags |= 2;
    xf_set_pos(&b->base.xf, x, y, 0.0f);
    b->base.unk_B0 = 1;
    if (shadow) {
        func_80019680(&b->shadow, D_80089990);
        func_8001A1D8(&b->shadow, -2.0f, -depth, 2.0f, 0.0f);
        func_8001A210(&b->shadow, 0.0f, 0.0f, 1.0f, 1.0f, 0);
        func_800191E0(&b->shadow, 0xC800FF00);
        func_80019338(&b->shadow, 0, 0xFF, 0, 0xFF);
    } else {
        b->shadow = NULL;
    }
    func_800CD74C(b);
}
