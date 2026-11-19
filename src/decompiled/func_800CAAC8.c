#include "sydney_types.h"

/* Sets up the five overlay sprites of a results panel (display list, position, colour) and shows them. */
typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    f32 m[3][4];
    u8 pad30[0x10];
    Vec3f pos;
} Transform;

typedef struct {
    s16 delta;
    s16 pad;
    void (*func)(void *self);
} VtblEntry;

typedef struct {
    u8 pad0[0x14];
    Transform xf;
    u8 pad60[0xB4 - 0x60];
    VtblEntry *vtbl;
    u8 padB8[0xC0 - 0xB8];
    u32 flags;
    s32 dl;
    u8 padC8;
    u8 unk_C9;
    u8 padCA[0xD4 - 0xCA];
} Sprite;

typedef struct {
    u8 pad0[0x75C];
    Sprite sprites[5];
} Panel;

extern void func_8001A330(s32 *dl, s32 arg1);
extern void func_8001A1D8(s32 *dl, s32 arg1, s32 arg2, f32 x, f32 y);
extern void func_8001A210(s32 *dl, s32 arg1, s32 arg2, f32 sx, f32 sy, s32 arg5);
extern void func_800191E0(s32 *dl, s32 color);
extern void func_800ADC54(Sprite *s, s32 arg1);

#define VCALL(obj, off) (obj)->vtbl[(off) / 8].func((u8 *)(obj) + (obj)->vtbl[(off) / 8].delta)

static inline void Transform_Identity(Transform *xf) {
    xf->m[0][1] = xf->m[0][2] = xf->m[1][0] = xf->m[1][2] = xf->m[2][0] = xf->m[2][1] = 0.0f;
    xf->pos.x = xf->pos.y = xf->pos.z = 0.0f;
    xf->m[0][0] = xf->m[1][1] = xf->m[2][2] = 1.0f;
}

static inline void Sprite_Setup(Sprite *s, f32 x, f32 y, f32 px, f32 py) {
    s32 dl = 0;

    func_8001A330(&dl, 0xFFFF);
    func_8001A1D8(&dl, 0, 0, x, y);
    func_8001A210(&dl, 0, 0, 1.0f, 1.0f, 0);
    func_800191E0(&dl, -1);
    s->unk_C9 = 0;
    s->flags |= 0x20000;
    func_800ADC54(s, 2);
    s->flags |= 2;
    s->dl = dl;
    VCALL(s, 0x40);
    Transform_Identity(&s->xf);
    s->xf.pos.x = px;
    s->xf.pos.y = py;
}

static inline void Sprite_Show(Sprite *s) {
    s->flags |= 4;
}

void func_800CAAC8(Panel *p) {
    u8 i;

    Sprite_Setup(&p->sprites[0], 413.0f, 150.0f, 94.0f, 60.0f);
    func_800191E0(&p->sprites[0].dl, 0x82000000);
    Sprite_Setup(&p->sprites[1], 417.0f, 1.0f, 92.0f, 59.0f);
    func_800191E0(&p->sprites[1].dl, 0xFF000000);
    Sprite_Setup(&p->sprites[2], 417.0f, 1.0f, 92.0f, 210.0f);
    func_800191E0(&p->sprites[2].dl, 0xFF000000);
    Sprite_Setup(&p->sprites[3], 2.0f, 150.0f, 92.0f, 60.0f);
    func_800191E0(&p->sprites[3].dl, 0xFF000000);
    Sprite_Setup(&p->sprites[4], 2.0f, 150.0f, 507.0f, 60.0f);
    func_800191E0(&p->sprites[4].dl, 0xFF000000);
    i = 0;
    while (1) {
        if (i >= 5) {
            break;
        }
        Sprite_Show(&p->sprites[i]);
        i++;
    }
}
