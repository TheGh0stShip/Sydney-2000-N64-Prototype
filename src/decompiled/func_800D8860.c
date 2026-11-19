#include "sydney_types.h"

/* Shuts down an event scene: stops subsystems, releases resources and resets its members. */
typedef struct Handle {
    void *owner;
    void *res1;
    void *res2;
    s32 unk_0C;
    s16 unk_10;
    s16 unk_12;
} Handle;
typedef struct Panel {
    u8 unk_00[0xB8];
    s32 slots[8];
} Panel;
typedef struct VtEntry {
    s16 offset;
    s16 unk_02;
    void (*func)(void *self);
} VtEntry;
typedef struct Widget {
    u8 unk_00[0xB0];
    u8 unk_B0;
    u8 unk_B1[3];
    VtEntry *vtbl;
} Widget;
void func_80076F24(void);
void func_8009BDC4(void);
void func_800BC274(void *p);
void func_800BC0B4(void);
void func_800AACB0(void *list, void *item, s32 mode);
void func_800AC25C(void *obj, s32 a, s32 b, s32 c);
s32 func_80017D54(void);
void func_800AEFA0(void *p);
void func_800D7F5C(Panel *p);
void func_800AC334(void *p);
void func_80098D08(void *p);
void func_800ADC1C(Widget *w);
void func_800CCE4C(Widget *w);
void func_800AA658(void *owner, void *slot);
void func_800A8850(void *p);
void func_800D6EA0(void *p);
void func_800D29E0(void *p);
void func_80017B24(s32 h);
void func_800D52A8(void *p);
void func_800BAC24(void);
void func_8007E7A0(void *p);
void func_8009C100(void);
extern u8 D_800F2AD8[];
extern u8 D_800F26E0[];
extern u8 D_800F7270[];
extern u8 D_800F2758[];
extern u8 D_80077600[];
extern u8 D_800F4D00[];
extern Handle D_800F26B0;

typedef struct Scene {
    u8 unk_00[0xAC];
    s32 state;
    u8 unk_B0[0xC0 - 0xB0];
    s32 unk_C0;
    u8 unk_C4[0x45C - 0xC4];
    u8 unk_45C[0x60F - 0x45C];
    u8 unk_60F;
    u8 unk_610[0x618 - 0x610];
    void *unk_618;
    u8 unk_61C[0x660 - 0x61C];
    Panel panel;
    u8 unk_6D8[0x7E0 - 0x660 - sizeof(Panel)];
    u8 unk_7E0[0x3254 - 0x7E0];
    u8 unk_3254[0x37CC - 0x3254];
    u8 unk_37CC[0x38B8 - 0x37CC];
    u8 unk_38B8[0x4DF0 - 0x38B8];
    Widget widget;
    u8 unk_4DF0[0x4EFC - 0x4DF0 - sizeof(Widget)];
    u8 unk_4EFC[0x61DC - 0x4EFC];
    u8 unk_61DC[4];
} Scene;

void func_800D8860(Scene *scene) {
    u32 i;
    void *owner;
    Panel *pnl;
    Widget *wdg;
    Handle *hnd;

    func_80076F24();
    func_8009BDC4();
    func_800BC274(D_800F2AD8);
    func_800BC0B4();
    func_800AACB0(D_800F26E0, NULL, 2);
    func_800AACB0(D_800F26E0, NULL, 1);
    func_800AC25C(scene, 0x6B, 7, 0);
    if (func_80017D54() != 0) {
        pnl = &scene->panel;
        func_800AEFA0(D_800F7270);
        func_800D7F5C(pnl);
        for (i = 0; i < 8; i++) {
            pnl->slots[i] = 0;
        }
        func_800AC334(&scene->panel);
    }
    func_80098D08(scene->unk_4EFC);
    wdg = &scene->widget;
    func_800ADC1C(wdg);
    wdg->vtbl[3].func((u8 *)wdg + wdg->vtbl[3].offset);
    wdg->unk_B0 = 0;
    func_800CCE4C(wdg);
    if (scene->unk_618 != NULL) {
        func_800AA658(D_800F2758, &scene->unk_618);
    }
    func_800A8850(scene->unk_45C);
    func_800AEFA0(D_80077600);
    func_800D6EA0(scene->unk_37CC);
    func_800AC334(scene->unk_37CC);
    func_800D29E0(scene->unk_3254);
    func_800AC334(scene->unk_3254);
    func_800AC334(scene->unk_7E0);
    func_80017B24(scene->unk_C0);
    func_800D52A8(D_800F4D00);
    hnd = &D_800F26B0;
    owner = hnd->owner;
    if (owner != NULL) {
        hnd->owner = NULL;
        if (hnd->res1 != NULL) {
            func_800AA658(owner, &hnd->res1);
        }
        if (hnd->res2 != NULL) {
            func_800AA658(owner, &hnd->res2);
        }
        hnd->unk_10 = 0;
        hnd->unk_12 = 0;
        hnd->unk_0C = 0;
        hnd->owner = NULL;
    }
    func_800BAC24();
    func_800AEFA0(scene->unk_61DC);
    func_800AC334(scene->unk_38B8);
    func_8007E7A0(scene->unk_38B8);
    func_800AC334(scene->unk_45C);
    func_8009C100();
    func_800AACB0(D_800F26E0, scene, 0);
    scene->unk_60F = 0;
    scene->state = 2;
}
