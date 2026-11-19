#include "sydney_types.h"

/* Sets up a screen object: creates its sprites/windows and child items. */
typedef struct {
    f32 unk_0; f32 unk_4; f32 unk_8; u8 pad_C[4]; f32 unk_10; f32 unk_14; f32 unk_18; u8 pad_1C[4];
    f32 unk_20; f32 unk_24; f32 unk_28; u8 pad_2C[0x14]; f32 unk_40; f32 unk_44; f32 unk_48; u8 pad_4C[4];
    u8 unk_50; u8 pad_51[0xF];
} Xform;
typedef struct Item {
    u8 pad_0[0x60]; Xform xf; s32 unk_C0; s32 unk_C4; u8 unk_C8; u8 unk_C9; u8 pad_CA[0xA];
} Item;
typedef struct {
    Item base; f32 unk_D4; s32 unk_D8; s32 unk_DC; s32 unk_E0; s32 unk_E4; s32 unk_E8;
    Item items[4]; Item unk_43C;
} Screen;
void func_80019680(s32 *, void *);
void func_8001A1D8(s32 *, f32, f32, f32, f32);
void func_8001A210(s32 *, f32, f32, f32, f32, s32);
void func_8001A330(s32 *, s32);
void func_800191E0(s32 *, u32);
void func_800AC37C(Item *, Screen *);
void func_800ADC10(Screen *);
void func_800ADC54(Item *, s32);
void func_800CEC00(Screen *, f32);
void func_800CEE04(Screen *);
extern u8 D_80089B30[];
extern s32 D_800F4940;

static inline void xf_set_pos(Xform *x, f32 px, f32 py) {
    x->unk_48 = 0.0f;
    x->unk_40 = px;
    x->unk_44 = py;
}

static inline void xf_identity(Xform *x, f32 one) {
    x->unk_40 = x->unk_44 = x->unk_48 = x->unk_4 = x->unk_8 = x->unk_10 = x->unk_18 = x->unk_20 = x->unk_24 = 0.0f;
    x->unk_0 = x->unk_14 = x->unk_28 = one;
}

void func_800CE7B0(Screen *s) {
    f32 a, one, b, c, d;
    union { s32 *h; Item *it; } p;
    Xform *x;

    p.h = &s->unk_D8;
    *p.h = 0;
    func_80019680(p.h, D_80089B30);
    a = 32.0f;
    func_8001A1D8(p.h, 0.0f, 0.0f, 60.0f, a);
    one = 1.0f;
    func_8001A210(p.h, 0.0f, 0.0f, one, one, 0);
    s->base.unk_C4 = s->unk_D8;
    s->base.unk_C9 = 1;
    s->base.unk_C0 |= 0x20000;
    func_800ADC10(s);
    D_800F4940 = 0;
    p.h = &s->unk_DC;
    *p.h = 0;
    func_8001A330(p.h, 0xFFFF);
    func_8001A1D8(p.h, 0.0f, 0.0f, 5.0f, 3.0f);
    func_8001A210(p.h, 0.0f, 0.0f, one, one, 0);
    func_800191E0(p.h, 0xFF000000);
    s->items[0].unk_C4 = s->unk_DC;
    p.it = &s->items[0];
    p.it->unk_C9 = 2;
    p.it->unk_C0 |= 0x20000;
    func_800ADC54(p.it, 2);
    func_800AC37C(p.it, s);
    s->items[0].xf.unk_50 = 1;
    func_800AC37C(&s->unk_43C, s);
    s->unk_43C.xf.unk_50 = 1;
    xf_set_pos(&s->unk_43C.xf, 15.0f, 24.0f);

    p.h = &s->unk_E0;
    *p.h = 0;
    func_8001A330(p.h, 0xFFFF);
    b = 9.0f; c = 43.0f; d = 31.0f;
    func_8001A1D8(p.h, one, b, c, d);
    func_8001A210(p.h, 0.0f, 0.0f, one, one, 0);
    func_800191E0(p.h, 0x82000000);
    s->items[1].unk_C4 = s->unk_E0;
    p.it = &s->items[1];
    p.it->unk_C9 = 0;
    p.it->unk_C0 |= 0x20000;
    func_800ADC54(p.it, 2);
    func_800AC37C(p.it, s);
    s->items[1].xf.unk_50 = 1;
    xf_identity(&s->items[1].xf, one);
    p.h = &s->unk_E4;
    *p.h = 0;
    func_8001A330(p.h, 0xFFFF);
    func_8001A1D8(p.h, 0.0f, b, one, d);
    func_8001A210(p.h, 0.0f, 0.0f, one, one, 0);
    func_800191E0(p.h, 0xFF000000);
    s->items[2].unk_C4 = s->unk_E4;
    p.it = &s->items[2];
    p.it->unk_C9 = 0;
    p.it->unk_C0 |= 0x20000;
    func_800ADC54(p.it, 2);
    func_800AC37C(p.it, s);
    s->items[2].xf.unk_50 = 1;
    xf_identity(&s->items[2].xf, one);
    p.h = &s->unk_E8;
    *p.h = 0;
    func_8001A330(p.h, 0xFFFF);
    func_8001A1D8(p.h, 0.0f, d, c, a);
    func_8001A210(p.h, 0.0f, 0.0f, one, one, 0);
    func_800191E0(p.h, 0xFF000000);
    s->items[3].unk_C4 = s->unk_E8;
    p.it = &s->items[3];
    p.it->unk_C9 = 0;
    p.it->unk_C0 |= 0x20000;
    func_800ADC54(p.it, 2);
    func_800AC37C(p.it, s);
    s->items[3].xf.unk_50 = 1;
    x = &s->items[3].xf;
    x->unk_14 = x->unk_28 = one;
    x->unk_40 = x->unk_44 = x->unk_48 = x->unk_4 = x->unk_8 = x->unk_10 = x->unk_18 = x->unk_20 = x->unk_24 = 0.0f;
    x->unk_0 = one;
    xf_set_pos(&s->base.xf, 376.0f, 100.0f);
    s->unk_D4 = 0.0f;
    func_800CEC00(s, 0.0f);
    func_800CEE04(s);
}
