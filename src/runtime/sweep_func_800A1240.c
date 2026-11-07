typedef unsigned char u8;
typedef short s16;
typedef signed int s32;
typedef float f32;
typedef struct Vec3 { f32 x, y, z; } Vec3;
typedef struct Sub { char pad[0x40]; Vec3 pos; } Sub;
typedef struct VEnt { s16 d; s16 i; void (*f)(char *); } VEnt;
typedef struct Msg { s32 type; } Msg;
typedef struct Obj {
    char pad0[0x14];
    Sub sub;
    char pad60[0xB4 - 0x60];
    VEnt *vtbl;
    char padB8[0xDC - 0xB8];
    Vec3 base;
    char padE8[0xE8 - 0xE8];
    f32 kx;
    f32 ky;
    char padF0[4];
    f32 g;
    f32 t;
    s32 active;
    u8 state;
    char pad101[0x108 - 0x101];
    Vec3 *out;
    char pad10C[0x110 - 0x10C];
    char node[4];
} Obj;
extern void func_800ADC1C(void *);
extern void func_800AD9E8(Obj *);
static inline void vadd(Vec3 *a, Vec3 *b)
{
    a->x += b->x;
    a->y += b->y;
    a->z += b->z;
}
static inline void getpos(Sub *s, Vec3 *o)
{
    o->x = s->pos.x;
    o->y = s->pos.y;
    o->z = s->pos.z;
}
void func_800A1240(Obj *o, Msg *m)
{
    f32 a, t, tt;
    if (m->type == 5 && o->state >= 2 && o->active != 0) {
        a = o->g * 0.5f;
        o->t += (1.0f / 30.0f);
        if (o->sub.pos.y < 0.0f) {
            o->state = 1;
            o->vtbl[9].f((char *)o + o->vtbl[9].d);
            func_800ADC1C(o->node);
            o->active = 0;
        }
        t = o->t;
        tt = t * t;
        o->sub.pos.x = o->kx * t * 32.767f;
        o->sub.pos.y = (o->ky * t + a * tt) * 32.767f;
        o->sub.pos.z = 0.0f;
        vadd(&o->sub.pos, &o->base);
        getpos(&o->sub, o->out);
        func_800AD9E8(o);
    }
}
