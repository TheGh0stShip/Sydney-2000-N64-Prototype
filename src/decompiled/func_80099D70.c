#include "sydney_types.h"

/* One-time setup of a scene's animated parts: picks animation parameters by mode, attaches them, then resets the parts. */
typedef struct Vec3 { f32 x, y, z; } Vec3;

typedef struct Xform {
    u8 pad00[0x40];
    Vec3 pos;
} Xform;

typedef struct Part {
    u8 pad00[0x60];
    Xform xf;
    u8 pad[0xD4 - 0x60 - 0x4C];
} Part;

typedef struct Anim {
    u8 pad[0xDC];
} Anim;

typedef struct AnimDesc {
    u8 pad00[0x10];
    s32 id;
    u8 pad14[4];
} AnimDesc;

typedef struct Scene {
    u8 pad000[0x8C];
    Part parts[7];
    u8 pad658[0x770 - 0x658];
    Anim anims[3];
    u8 padA04[0xA04 - 0xA04];
    u8 unk_A04[0x118C - 0xA04];
    u8 flags_118C;
    u8 pad118D[2];
    u8 flags_118F;
} Scene;

typedef struct G {
    u8 pad000[0x38];
    f32 unk_38;
    u8 pad03C[0x4F4 - 0x3C];
    f32 unk_4F4[11];
    f32 unk_520[1];
    u8 pad524[0xA00 - 0x524];
    s32 mode;
    s32 unk_A04;
    u8 padA08[0xDDC - 0xA08];
    f32 unk_DDC[1];
} G;

extern G *D_800FC270;
extern AnimDesc D_800F1388;
extern AnimDesc D_800F13A0;
extern AnimDesc D_800F13B8;
extern s32 D_80100640; /* parameter word read by func_800B360C (holds float bits) */

void func_800B31EC(s32 a);
void func_800B360C(Anim *anim, AnimDesc *desc);
void func_800AC37C(Anim *anim, Part *part);
void func_800ADC38(Part *part);
void func_800CC390(void *p);

static inline void xf_set_pos(Xform *xf, f32 x, f32 y, f32 z) {
    xf->pos.x = x;
    xf->pos.y = y;
    xf->pos.z = z;
}

void func_80099D70(Scene *sc, s32 idx, f32 speed) {
    f32 v;
    s32 id;

    if (sc->flags_118C & 0x1E) {
        return;
    }
    func_800B31EC(0);
    if (D_800FC270->mode == 5) {
        D_80100640 = *(s32 *) &D_800FC270->unk_DDC[idx];
        D_800F1388.id = 0x299;
        func_800B360C(&sc->anims[0], &D_800F1388);
        func_800AC37C(&sc->anims[0], &sc->parts[0]);
    } else {
        if (D_800FC270->mode != 6) {
            v = D_800FC270->unk_38;
        } else {
            v = speed;
        }
        if (v < 0.0f) {
            v = 0.0f;
        }
        D_80100640 = *(s32 *) &v;
        D_800F1388.id = 0x29C;
        func_800B360C(&sc->anims[0], &D_800F1388);
        func_800AC37C(&sc->anims[0], &sc->parts[0]);
        if (D_800FC270->mode != 6) {
            D_80100640 = *(s32 *) &D_800FC270->unk_4F4[idx];
            D_800F13A0.id = 0x29B;
            func_800B360C(&sc->anims[1], &D_800F13A0);
            func_800AC37C(&sc->anims[1], &sc->parts[0]);
        }
        if (D_800FC270->unk_A04 == 0) {
            D_80100640 = *(s32 *) &speed;
            D_800F13B8.id = 0x28B;
            func_800B360C(&sc->anims[2], &D_800F13B8);
            func_800AC37C(&sc->anims[2], &sc->parts[0]);
        } else if (D_800FC270->mode == 4) {
            D_80100640 = *(s32 *) &D_800FC270->unk_520[idx];
            D_800F13B8.id = 0x29A;
            func_800B360C(&sc->anims[2], &D_800F13B8);
            func_800AC37C(&sc->anims[2], &sc->parts[0]);
        }
    }
    xf_set_pos(&sc->parts[0].xf, 0.0f, -16.0f, 0.0f);
    func_800ADC38(&sc->parts[0]);
    func_800ADC38(&sc->parts[1]);
    func_800ADC38(&sc->parts[2]);
    xf_set_pos(&sc->parts[3].xf, 602.0f, 35.0f, 0.0f);
    func_800ADC38(&sc->parts[3]);
    func_800ADC38(&sc->parts[4]);
    func_800ADC38(&sc->parts[5]);
    func_800ADC38(&sc->parts[6]);
    func_800CC390(sc->unk_A04);
    sc->flags_118C |= 0x1E;
    sc->flags_118F |= 0x1E;
}
