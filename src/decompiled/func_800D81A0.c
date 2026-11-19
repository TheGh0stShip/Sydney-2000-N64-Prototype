#include "sydney_types.h"

/* Event handler for an animated actor: starts/stops animation tracks and, on event 12 in state 6, re-seats the actor's position from measured part heights. */
typedef struct Vec3 { f32 x, y, z; } Vec3;
typedef struct Vec4 { f32 x, y, z, w; } Vec4;

typedef struct Event {
    s32 type;       /* 0x00 */
    s32 time;       /* 0x04 */
    u8 pad08[4];
    Vec3 *pos;      /* 0x0C */
    s32 arg;        /* 0x10 */
} Event;

typedef struct Actor {
    u8 pad00[0x10];
    s32 time;           /* 0x010 */
    u8 xf[0x40];        /* 0x014 */
    Vec3 pos;           /* 0x054 */
    u8 pad60[0x170 - 0x60];
    Vec3 unk_170;       /* 0x170 */
    u8 pad17C[0x188 - 0x17C];
    Vec3 unk_188;       /* 0x188 */
    u8 pad194[0x1E8 - 0x194];
    s32 state;          /* 0x1E8 */
    s32 unk_1EC;        /* 0x1EC */
    s16 unk_1F0;        /* 0x1F0 */
    u8 pad1F2[0x1FC - 0x1F2];
    s32 unk_1FC;        /* 0x1FC */
} Actor;

extern s32 D_800F267C;
extern void func_800D8C50(Actor *, Vec3 *, s32);
extern void func_800D84E8(Actor *, s32);
extern void func_800B9E9C(Actor *, s32, s32, f32, s32);
extern void func_800B9FA4(Actor *, s32, s32, f32, s32, s32);
extern void func_800B9E74(Actor *, s32);
extern void func_800B9830(Actor *, s32, Vec4 *, s32, s32);
extern void func_800AC9B8(Vec3 *, void *, s32);

static inline void vcopy(Vec3 *d, Vec3 *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

void func_800D81A0(Actor *a, Event *ev) {
    Vec3 v;
    Vec4 out;
    f32 h;
    f32 one;
    s32 dt = (ev->time - a->time) >> 8;

    switch (ev->type) {
    case 3:
        func_800D8C50(a, ev->pos, ev->arg);
        break;
    case 14:
        switch (a->state) {
        case 0:
            func_800B9E9C(a, 1, -1, 1.0f, 0);
            a->unk_1EC = 1;
            break;
        case 7:
            if (a->unk_1FC == 0) {
                if (ev->arg == 0) {
                    func_800B9E9C(a, 3, -1, 1.0f, 0);
                } else {
                    func_800B9E9C(a, 1, -1, 1.0f, 0);
                }
                a->unk_1EC = 1;
                a->unk_1FC = 1;
            }
            break;
        }
        break;
    case 12:
        switch (a->state) {
        case 0:
            func_800B9E9C(a, 2, -1, 1.0f, 0);
            a->unk_1EC = 1;
            break;
        case 6:
            vcopy(&v, ev->pos);
            v.x -= 3.2767f;
            v.z += 3.2767f;
            h = 0.0f;
            func_800B9830(a, 4, &out, 0, 0);
            h += out.z;
            func_800B9830(a, 3, &out, 0, 0);
            h += out.z;
            a->unk_1F0 = 1;
            func_800B9830(a, 2, &out, 0, 0);
            h += out.z * a->unk_1F0;
            h += out.z;
            h += 16.3835f;
            v.x -= h;
            vcopy(&a->pos, &v);
            h = 0.0f;
            v.y = h;
            v.z = h;
            v.x = 1.0f;
            func_800AC9B8(&v, a->xf, D_800F267C);
            vcopy(&a->unk_170, &a->pos);
            vcopy(&a->unk_188, &a->pos);
            a->unk_188.y = h;
            a->unk_170.y = h;
            a->unk_1F0 = 10000;
            a->unk_1FC = 0;
            break;
        }
        break;
    case 15:
        if (a->state == 6 && a->unk_1FC == 0) {
            one = 1.0f;
            a->unk_1F0 = 1;
            func_800B9FA4(a, 2, -1, one, 0, 1);
            func_800B9E74(a, 4);
            func_800B9E9C(a, 2, -1, one, 0);
        }
        break;
    case 17:
        if (a->state == 6) {
            a->unk_1FC = 1;
        }
        break;
    case 5:
        func_800D84E8(a, dt);
        break;
    }
    a->time = ev->time;
}
