#include "sydney_types.h"

/* Actor movement step: advances animation, updates position, tilts towards vertical speed and handles landing. */
typedef struct Vec3 {
    f32 x, y, z;
} Vec3;

typedef struct Pose {
    u8 unk_00[0x40];
    Vec3 pos;
} Pose;

typedef struct Rider {
    u8 unk_000[0x77C];
    f32 tilt;
} Rider;

typedef struct Actor {
    u8 unk_000[4];
    s32 unk_004;
    u8 unk_008[0xC];
    Pose pose;
    u8 unk_060[0xAC - 0x60];
    s32 state;
    u8 unk_0B0[0x170 - 0xB0];
    Vec3 unk_170;
    u8 unk_17C[0xC];
    Vec3 unk_188;
    u8 unk_194[0x288 - 0x194];
    s32 unk_288;
    u8 unk_28C[0x2E2 - 0x28C];
    u8 unk_2E2;
    u8 unk_2E3;
    u8 unk_2E4;
    u8 unk_2E5[0x2EC - 0x2E5];
    Rider *rider;
    f32 tilt;
    u8 unk_2F4[0x310 - 0x2F4];
    f32 unk_310;
    u8 unk_314[0x32C - 0x314];
    f32 unk_32C;
} Actor;

extern u16 D_8007DD44[];

void func_800BB9C0(void *p, s32 a, s32 b);
void func_800BB8E0(void *p);
void func_8007DB20(Actor *a, f32 x, f32 y);
s32 func_800B9BD4(Actor *a, s32 mode, f32 *b, f32 *c, f32 *d, s32 e);
void func_800B9964(Actor *a, f32 *b, f32 *c, f32 *d);
void func_8007D910(Actor *a);
void func_800B9830(Actor *a, u16 id, Vec3 *out, s32 c, s32 d);
void func_800764EC(s32 h);

void func_8010E990(Actor *a, f32 *p1, f32 *p3, f32 *p2, s32 *anim, f32 *prevX) {
    s32 h = a->unk_004;
    s32 landed;
    f32 t;
    f32 d;
    f32 n;
    f32 prev;
    Vec3 sp18;
    Pose *ps;
    Vec3 *v;

    func_800BB9C0(a->unk_2F4, *anim, a->unk_288);
    func_800BB8E0(a->unk_2F4);
    func_8007DB20(a, 0.2f, 1.5f);
    landed = func_800B9BD4(a, 1, p1, p2, p3, 0);
    *prevX = a->pose.pos.x;
    func_800B9964(a, p1, p2, p3);
    prev = *prevX;
    if (a->rider != NULL) {
        t = (a->pose.pos.x - prev) / 32.767f;
        if (t < 0.0f) {
            t = -t;
        }
        n = t * 30.0f;
        d = n - a->tilt;
        if (d != 0.0f) {
            if (d > 0.0f) {
                if (d > 0.075f) {
                    n = a->tilt + 0.075f;
                }
            } else if (d < -0.075f) {
                n = a->tilt - 0.075f;
            }
        }
        a->rider->tilt = n;
        a->tilt = n;
    }
    if (landed != 0) {
        a->unk_2E4 = 0;
        func_8007D910(a);
        ps = &a->pose;
        v = &a->unk_170;
        v->x = ps->pos.x;
        v->y = ps->pos.y;
        v->z = ps->pos.z;
        v = &a->unk_188;
        v->x = ps->pos.x;
        v->y = ps->pos.y;
        v->z = ps->pos.z;
        a->unk_170.y = 0.0f;
        a->unk_170.z = a->unk_32C;
        func_800B9830(a, D_8007DD44[a->unk_2E2], &sp18, 0, 0);
        a->unk_310 += sp18.z;
        a->state = 0x1A;
        return;
    }
    if (a->pose.pos.y < -3.2766998f) {
        func_800764EC(h);
    }
}
