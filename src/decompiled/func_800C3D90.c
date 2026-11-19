#include "sydney_types.h"

/* Creates the model handles for the eight free slots and builds the two shared marker handles. */
typedef struct { f32 x, y, z; } Vec;
typedef struct {
    f32 m[4][4];
    Vec pos;
} Transform;
typedef struct {
    u8 pad0[0x14];
    Transform xf;
    u8 pad60[0xC0 - 0x60];
    s32 unk_C0;
    s32 unk_C4;
    u8 padC8;
    u8 unk_C9;
    u8 padCA[0xD4 - 0xCA];
} Slot;
typedef struct {
    u8 pad0[0xD8];
    s32 unk_D8;
} Config;
extern Slot D_80101960[];
extern Config *D_800F63F0;
extern s32 D_800F40F0;
extern s32 D_800F40F4;
extern u8 D_800885C0[];
extern void func_800C4008(void);
extern s32 func_80019680(s32 *, void *);
extern s32 func_800DAC08(u32);
extern void func_800191E0(s32 *, s32);
extern void func_8001A1D8(s32 *, f32, f32, f32, f32);
extern void func_8001A210(s32 *, f32, f32, f32, f32, s32);
extern void func_8001A330(s32 *, s32);
extern void func_800ADC54(Slot *, s32);
static inline void mtx_reset(Transform *t) {
    t->m[2][1] = 0.0f;
    t->m[2][0] = 0.0f;
    t->m[1][2] = 0.0f;
    t->m[1][0] = 0.0f;
    t->m[0][2] = 0.0f;
    t->m[0][1] = 0.0f;
    t->pos.z = 0.0f;
    t->pos.y = 0.0f;
    t->pos.x = 0.0f;
    t->m[2][2] = 1.0f;
    t->m[1][1] = 1.0f;
    t->m[0][0] = 1.0f;
}
static inline void slot_enable(Slot *s, u8 state) {
    func_800ADC54(s, 1 << D_800F63F0->unk_D8);
    s->unk_C9 = state;
    s->unk_C0 |= 0x20000;
}
void func_800C3D90(void) {
    u8 i;
    s32 h;
    Slot *s;

    func_800C4008();
    for (i = 0; ({ i < 8; }); i++) {
        s = &D_80101960[i];
        if (s->unk_C4 != 0) {
            continue;
        }
        h = 0;
        func_80019680(&h, D_800885C0);
        func_800191E0(&h, func_800DAC08(i));
        func_8001A1D8(&h, -8.0f, 0.0f, 98.0f, 55.0f);
        func_8001A210(&h, 0.0f, 0.0f, 1.0f, 1.0f, 0);
        s->unk_C4 = h;
        mtx_reset(&s->xf);
        slot_enable(s, 2);
    }
    h = 0;
    func_8001A330(&h, 0xFFFF);
    func_800191E0(&h, 0x40404040);
    func_8001A1D8(&h, -9.0f, -3.0f, 100.0f, 11.0f);
    func_8001A210(&h, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    D_800F40F0 = h;
    h = 0;
    func_8001A330(&h, 0xFFFF);
    func_800191E0(&h, 0x40404040);
    func_8001A1D8(&h, -2.0f, -3.0f, 77.0f, 11.0f);
    func_8001A210(&h, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    D_800F40F4 = h;
}
