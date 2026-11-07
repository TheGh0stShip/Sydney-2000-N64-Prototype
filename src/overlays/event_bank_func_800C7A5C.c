typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

#define F(o, t) (*(t *)(obj + (o)))

typedef struct {
    char pad0[0x28];
    f32 a;
    f32 b;
    f32 c;
} Game;

typedef struct {
    f32 m[4][4];
    f32 t[3];
} Mtx;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec;

typedef struct {
    char pad0[2];
    u16 first;
    u16 count;
    char pad6[40 - 6];
} Grp;

typedef struct {
    char pad0[0x14];
    Vec *v;
    char pad18[2];
    u16 ngrp;
    Grp *grp;
} Mesh;

extern Game *D_800FC270;
extern s32 func_80017D84(char *, s32);
extern void func_80081F08(u8 *, f32 *, f32 *, void *, s32);
extern void func_8008382C(u8 *, s32);
extern void func_800837C0(u8 *, s32, f32);
extern void func_800B8C70(void *, f32);
extern void func_800AD434(Mtx *, f32, s32);
extern void func_80083064(u8 *, Mtx *, s32, s32);
extern void func_80083004(u8 *, Mtx *, s32);
extern void func_800830C4(u8 *, Mtx *, f32);
extern void func_8007160C(u8 *);
extern void func_800BB99C(void *, f32, f32, f32);
extern void func_800BBA1C(void *);
extern void func_80082A84(u8 *, s32, s32, s32, s32, s32);

static inline void setv(f32 *v, f32 x, f32 y, f32 z)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

static inline void ident(Mtx *m)
{
    m->m[2][1] = 0.0f;
    m->m[2][0] = 0.0f;
    m->m[1][2] = 0.0f;
    m->m[1][0] = 0.0f;
    m->m[0][2] = 0.0f;
    m->m[0][1] = 0.0f;
    m->t[2] = 0.0f;
    m->t[1] = 0.0f;
    m->t[0] = 0.0f;
    m->m[2][2] = 1.0f;
    m->m[1][1] = 1.0f;
    m->m[0][0] = 1.0f;
}

void func_8007173C(u8 *obj)
{
    f32 p[3];
    f32 q[3];
    Mtx m;
    Vec c;
    s32 i;
    s32 k;
    Grp *e;
    f32 s;
    u8 *q4;

    if (func_80017D84("GRAPHICS__VIRTUALGYM__ROPECLIMB__ROPECLIMB_BGP", -1) != 0) {
        return;
    }
    setv(p, 16.3834991f, 49.1504974f, -65.5339966f);
    setv(q, 26.2135983f, 32.7669983f, -88.4708939f);
    func_80081F08(obj, p, q, obj + 4552, 0);
    func_8008382C(obj, 12);
    F(0x44C0, Mesh *) = F(0x1330, Mesh *);
    i = 0;
    while (1) {
        if (!(i < F(0x44C0, Mesh *)->ngrp)) {
            break;
        }
        e = &F(0x44C0, Mesh *)->grp[i];
        c.x = F(0x44C0, Mesh *)->v[e->first].x;
        c.y = F(0x44C0, Mesh *)->v[e->first].y;
        c.z = F(0x44C0, Mesh *)->v[e->first].z;
        for (k = e->first; k < e->first + e->count; k++) {
            F(0x44C0, Mesh *)->v[k].x -= c.x;
            F(0x44C0, Mesh *)->v[k].y -= c.y;
            F(0x44C0, Mesh *)->v[k].z -= c.z;
        }
        i++;
    }
    func_800837C0(obj, 0, 1.0f);
    func_800B8C70(obj + 4552, 0.0f);

    F(0x1220, f32) = 34.4053459f;
    F(0x133C, f32) = 34.4053459f;
    ident(&m);
    m.t[0] = -65.5339966f;
    m.t[2] = 16.3834991f;
    func_800AD434(&m, -0.383972406f, 3);
    func_80083064(obj, &m, 10, F(0x44DC, s32));

    ident(&m);
    m.t[0] = -32.7669983f;
    m.t[2] = 32.7669983f;
    func_800AD434(&m, -0.383972406f, 3);
    func_80083004(obj, &m, (u8)(F(0x44BB, s8) * 2));

    ident(&m);
    m.t[0] = 32.7669983f;
    m.t[1] = 32.7669983f;
    m.t[2] = 16.3834991f;
    func_800AD434(&m, 0.383972406f, 3);
    func_800830C4(obj, &m, 0.25f);
    func_8007160C(obj);

    s = D_800FC270->a * 0.75f + D_800FC270->b * 0.25f;
    F(0x4300, f32) = (D_800FC270->c + D_800FC270->c) * 0.5f + 1.0f;
    F(0x4304, f32) = s * 0.5f + 0.5f;
    q4 = obj + 4968;
    func_800BB99C(q4, s * 0.03f + 0.03f, s * 0.0015f + -0.003f, 0.0f);
    func_800BBA1C(q4);

    F(0x44D4, s32) = 0;
    F(0x42EC, s32) = 0;
    F(0x44D0, s32) = 0;
    F(0x44CC, s32) = 0;
    F(0x0F14, s32) = 0;
    F(0x44B9, u8) = 0;
    F(0x0F0C, s32) = 23040;
    F(0x42FC, f32) = 6.8f - F(0x44C4, u8) * 0.01f;
    func_80082A84(obj, 12, 0, 0, 0, 0);
    func_80082A84(obj, 38, F(0x44BB, s8), 0, 0, 0);
    func_80082A84(obj, 26, (u32)((f32)F(0x44DC, s32) / 30.0f * 0.00390625f), 0, 0, 0);
}
