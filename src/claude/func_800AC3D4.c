typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct Xf {
    f32 m[3][4];
    f32 pad30[4];
    f32 t[3];
} Xf;
typedef char assert_xf[(sizeof(Xf) == 0x4C) ? 1 : -1];

typedef struct ObjC3D4 {
    s32 a0;
    s32 a4;
    s32 a8;
    s32 aC;
    s32 clock;
    Xf x1;
    Xf x2;
    u8 padAC[4];
    u8 b0;
    u8 b1;
    u8 padB2[2];
    void *vtable;
} ObjC3D4;
typedef char assert_obj[(sizeof(ObjC3D4) == 0xB8) ? 1 : -1];

extern u8 runtimeObjectVtable[];
typedef struct { s32 clock; } Clock;
extern Clock runtimePropertyClock;

static __inline__ void xfIdentity(Xf *x) {
    x->m[0][1] = x->m[0][2] = x->m[1][0] = x->m[1][2] = x->m[2][0] = x->m[2][1] = 0.0f;
    x->t[0] = x->t[1] = x->t[2] = 0.0f;
    x->m[0][0] = x->m[1][1] = x->m[2][2] = 1.0f;
}

ObjC3D4 *func_800AC3D4(ObjC3D4 *o) {
    o->vtable = runtimeObjectVtable;
    o->a0 = 0;
    o->a4 = 0;
    o->a8 = 0;
    o->aC = 0;
    o->clock = runtimePropertyClock.clock;
    xfIdentity(&o->x1);
    xfIdentity(&o->x2);
    o->b0 = 0;
    o->b1 = 1;
    return o;
}
