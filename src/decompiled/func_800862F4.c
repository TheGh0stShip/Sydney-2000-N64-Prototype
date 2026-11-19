#include "sydney_types.h"

/* Mode-dependent state step: starts a round (sounds, timer, effects) or reacts to the current sub-state. */
typedef struct {
    s16 delta;
    s16 index;
    void (*func)(void *);
} VtEntry;

typedef struct {
    u8 pad00[0xB0];
    u8 unk_B0;
    u8 padB1[3];
    VtEntry *vtable;
} Part;

typedef struct {
    u8 pad00[0x68];
    s32 volume;
} Snd;

typedef struct {
    u8 pad[0xD10];
    s32 unk_D10;
} Global;

typedef struct {
    u8 pad0[0xB8];
    s32 unk_B8;
    u8 padBC[0x45C - 0xBC];
    u8 unk_45C[0x60E - 0x45C];
    u8 unk_60E;
    u8 unk_60F;
    u8 pad610[4];
    u8 unk_614;
    u8 unk_615;
    u8 pad616[0x7E0 - 0x616];
    u8 unk_7E0[0x3254 - 0x7E0];
    u8 unk_3254[0x4034 - 0x3254];
    Part unk_4034;
    u8 pad40EC[0x4140 - 0x40EC];
    u8 unk_4140[0x4B44 - 0x4140];
    u8 unk_4B44[0x5418 - 0x4B44];
    s32 unk_5418;
    u8 pad541C[0x5424 - 0x541C];
    s32 unk_5424;
    u8 pad5428[0x5430 - 0x5428];
    s32 unk_5430;
    u8 pad5434[0x5448 - 0x5434];
    s32 unk_5448;
    u8 pad544C[0x545C - 0x544C];
    s32 unk_545C;
    u8 pad5460[0x5470 - 0x5460];
    u8 unk_5470;
    u8 pad5471[4];
    u8 unk_5475;
} Game;


extern Snd D_800F1AE0;
extern s32 D_800F2728;
extern u8 D_800F3BC0[];
extern Global *D_800FC270;

s32 func_8001D4B8(Snd *, s32, s32, s32);
void func_8001D550(Snd *, s32);
void func_8001D5D8(Snd *, s32, s32, s32, s32, s32);
void func_8001D640(Snd *, s32, s32);
void func_80074068(void *);
void func_80074154(void *);
void func_800763D4(void *);
void func_80099D70(void *, s32, f32);
void func_80099FE4(void *);
void func_8009AC98(s32, u8, void *, s32);
void func_800A9BE8(void *, s32);
void func_800AC25C(void *, s32, s32, s32);
void func_800ADC1C(Part *);
void func_800C013C(void *);
void func_800CC418(void *);
void func_800D29E0(void *);

static inline s32 scale(s32 v, s32 m, s32 sh) {
    return (v * m) >> sh;
}

static inline s32 play(Snd *snd, s32 id, s32 m) {
    s32 h = func_8001D4B8(snd, id, 0, -1);

    func_8001D640(snd, h, 0);
    func_8001D5D8(snd, h, scale(snd->volume, m, 15), 15, 0, 0);
    return h;
}

void func_80074F24(Game *g) {
    Part *p;
    f32 t;

    switch (g->unk_615) {
    case 0:
    case 3:
    case 4:
        switch (g->unk_60F) {
        case 2:
        case 3:
        case 4:
        case 6:
            func_800D29E0(g->unk_3254);
            func_800C013C(D_800F3BC0);
            if (g->unk_615 != 4) {
                func_8001D550(&D_800F1AE0, 1);
            }
            if (g->unk_615 == 0) {
                g->unk_545C = play(&D_800F1AE0, 0x103, 0x3FFF);
                g->unk_5448 = play(&D_800F1AE0, 0x10D, 0x2666);
            }
            if (g->unk_615 == 3) {
                t = g->unk_5430 / 30.0f * 0.00390625f;
            } else {
                t = D_800FC270->unk_D10 / 30.0f * 0.00390625f;
            }
            func_80099D70(g->unk_4140, 7, t);
            func_800AC25C(g, 0x62, 0x11, 0);
            g->unk_5424 = 0;
            g->unk_5475 = 0;
            g->unk_60F = 8;
            break;
        case 9:
        case 10:
        case 13:
        case 15:
        case 27:
        case 28:
        case 38:
            if (g->unk_615 != 3 && g->unk_5470 == 0) {
                g->unk_B8 = 1;
                func_80074154(g);
                func_80099FE4(g->unk_4140);
                func_800D29E0(g->unk_3254);
                func_8009AC98(0xE1, g->unk_60E, g->unk_7E0, 2);
                func_800A9BE8(g->unk_45C, 9);
                g->unk_5424 = 0x1C200;
                g->unk_60F = 0x20;
            }
            break;
        case 31:
        case 32:
        case 33:
        case 37:
        case 44:
            g->unk_5424 = 0;
            break;
        }
        break;
    case 5:
        p = &g->unk_4034;
        func_800ADC1C(p);
        p->vtable[3].func((u8 *) p + p->vtable[3].delta);
        p->unk_B0 = 0;
        if (g->unk_614 == 1) {
            g->unk_60F = 0x25;
            g->unk_5424 = 0;
        } else {
            func_80074068(g);
        }
        break;
    case 2:
        func_800C013C(D_800F3BC0);
        D_800F2728 = 0;
        g->unk_5418 = -0x1E00;
        g->unk_B8 = 0;
        g->unk_5424 = 0;
        g->unk_60F = 0x1F;
        func_800CC418(g->unk_4B44);
        func_800763D4(g);
        break;
    }
}
