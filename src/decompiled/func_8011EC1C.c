#include "sydney_types.h"

/* Steps two bouncing pieces under gravity, damping and playing an impact sound on the first one's bounce. */
typedef struct { f32 x, y, z; } Vec;
typedef struct {
    u8 pad0[0x68];
    s32 unk_68;
} SoundBank;
typedef struct Obj {
    u8 pad0[4];
    s32 *unk_4;
    u8 pad8[0x10C8 - 8];
    s32 unk_10C8;
    s32 unk_10CC;
    u8 pad10D0[0x10EC - 0x10D0];
    Vec pos[2];
    Vec vel[2];
    u8 pad111C[0x1160 - 0x111C];
    f32 unk_1160;
    u8 pad1164[4];
    s32 unk_1168;
} Obj;
extern SoundBank D_800F1AE0;
extern s32 D_800F2744;
extern void func_80081ADC(void);
extern void func_800B9BD4(Obj *, s32, void *, void *, void *, s32);
extern s32 func_8001D4B8(SoundBank *, s32, s32, s32);
extern void func_8001D640(SoundBank *, s32, s32);
extern void func_800815C0(Obj *, s32 *, s32);
static inline void vec_add(Vec *a, Vec *b) {
    a->x += b->x;
    a->y += b->y;
    a->z += b->z;
}
static inline void vec_scale(Vec *a, f32 k) {
    a->x *= k;
    a->y *= k;
    a->z *= k;
}
void func_8011EC1C(Obj *obj) {
    s32 *state = obj->unk_4;
    u8 a[0x10];
    u8 b[0x10];
    u8 c[0x8];
    u32 i;
    s32 v;
    s32 h;
    s32 vol;

    func_80081ADC();
    func_800B9BD4(obj, 1, a, c, b, 0);
    if (*state != 100) {
        if (obj->unk_10C8 != 0) {
            SoundBank *bank = &D_800F1AE0;
            f32 damp = 0.65f;

            for (i = 0; ({ i < 2; }); i++) {
                obj->vel[i].y += -0.3571603f;
                vec_add(&obj->pos[i], &obj->vel[i]);
                if (obj->pos[i].y < obj->unk_1160) {
                    if (obj->unk_10CC != 0) {
                        obj->unk_10CC = 0;
                    }
                    if (i == 0) {
                        v = obj->vel[0].y / 0.032767f;
                        if (v < 0) {
                            v = -v;
                        }
                        if (v > 100) {
                            v = 100;
                        }
                        if (v > 10) {
                            vol = v * 0x7FFF / 100;
                            h = func_8001D4B8(bank, 0x115, 0, 0);
                            func_8001D640(bank, h, (vol * bank->unk_68) >> 15);
                        }
                    }
                    obj->pos[i].y = obj->unk_1160;
                    vec_scale(&obj->vel[i], damp);
                    obj->vel[i].y = -obj->vel[i].y;
                }
            }
            func_800815C0(obj, NULL, 0);
        } else {
            func_800815C0(obj, NULL, 0);
        }
    } else {
        func_800815C0(obj, state, 0);
    }
    obj->unk_1168 = D_800F2744;
}
