#include "sydney_types.h"

/* Builds the five quads of a framed box (fill plus four border strips) around a rectangle. */
typedef struct VEntry { s16 delta; s16 pad; void (*fn)(void *); } VEntry;
typedef struct Quad {
    u8 unk_00[0xB4];
    VEntry *vtbl;
    u8 unk_B8[0xC0 - 0xB8];
    s32 flags;
    s32 handle;
    u8 unk_C8;
    u8 unk_C9;
    u8 unk_CA[0xD4 - 0xCA];
} Quad;
typedef struct Box { u8 unk_00[0x1E8]; Quad quads[5]; } Box;
typedef struct Rect { u8 unk_00[0xC]; s16 x; s16 y; s16 w; s16 h; } Rect;
typedef struct Cam { u8 unk_00[0xD8]; s32 unk_D8; } Cam;

extern s32 D_8008ACFC;
extern Cam *D_800F63F0;
void func_80019680(s32 *, s32 *);
void func_8001A1D8(s32 *, f32, f32, f32, f32);
void func_8001A210(s32 *, f32, f32, f32, f32, s32);
void func_8001A330(s32 *, s32);
void func_800191E0(s32 *, s32);
void func_800ADC54(Quad *, s32);

void func_800DC178(Box *box, Rect *r) {
    s32 h;
    Quad *q;
    f32 x0, y0, x1, y1;
    u8 i;

    h = 0;
    if (box->quads[0].handle != 0) {
        return;
    }
    q = &box->quads[0];
    h = 0;
    x0 = r->x;
    x1 = x0 + r->w;
    y0 = r->y;
    y1 = y0 + r->h;
    func_80019680(&h, &D_8008ACFC);
    func_8001A1D8(&h, x0, y0, x1, y1);
    y1 = y0;
    y0 = y0 - 1.0f;
    func_8001A210(&h, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&h, -1);
    q->unk_C9 = 3;
    q->flags |= 0x20000;
    func_800ADC54(q, 1 << D_800F63F0->unk_D8);
    q->handle = h;
    h = 0;

    q = &box->quads[1];
    func_8001A330(&h, 0xFFFF);
    func_8001A1D8(&h, x0, y0, x1, y1);
    func_8001A210(&h, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&h, 0xFF000000);
    q->unk_C9 = 0;
    q->flags |= 0x20000;
    func_800ADC54(q, 1 << D_800F63F0->unk_D8);
    q->handle = h;
    h = 0;

    q = &box->quads[2];
    y0 = r->y;
    y0 += r->h;
    y1 = y0 + 1.0f;
    func_8001A330(&h, 0xFFFF);
    func_8001A1D8(&h, x0, y0, x1, y1);
    func_8001A210(&h, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&h, 0xFF000000);
    q->unk_C9 = 0;
    q->flags |= 0x20000;
    func_800ADC54(q, 1 << D_800F63F0->unk_D8);
    q->handle = h;

    x1 = r->x;
    x0 = x1 - 2.0f;
    y0 = r->y - 1.0f;
    q = &box->quads[3];
    h = 0;
    y1 = y0 + r->h + 1.0f + 1.0f;
    func_8001A330(&h, 0xFFFF);
    func_8001A1D8(&h, x0, y0, x1, y1);
    func_8001A210(&h, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&h, 0xFF000000);
    q->unk_C9 = 0;
    q->flags |= 0x20000;
    func_800ADC54(q, 1 << D_800F63F0->unk_D8);
    q->handle = h;

    x0 = r->x;
    x0 += r->w;
    y0 = r->y - 1.0f;
    x1 = x0 + 2.0f;
    q = &box->quads[4];
    h = 0;
    y1 = y0 + r->h + 1.0f + 1.0f;
    func_8001A330(&h, 0xFFFF);
    func_8001A1D8(&h, x0, y0, x1, y1);
    func_8001A210(&h, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&h, 0xFF000000);
    q->unk_C9 = 0;
    q->flags |= 0x20000;
    func_800ADC54(q, 1 << D_800F63F0->unk_D8);
    q->handle = h;

    i = 0;
    while (1) {
        if (!(i < 5)) break;
        q = &box->quads[i];
        i++;
        q->flags |= 2;
        q->vtbl[8].fn((char *)q + q->vtbl[8].delta);
    }
}
