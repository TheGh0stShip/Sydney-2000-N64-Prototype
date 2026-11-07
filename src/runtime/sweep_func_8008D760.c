typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct Vec3 { f32 x, y, z; } Vec3;
typedef struct Vtx { Vec3 p; f32 pad[3]; u32 color; f32 pad2[2]; } Vtx;
typedef struct Obj {
    char pad0[0xBC];
    s32 handle;
    char padC0[0x1A0 - 0xC0];
    Vec3 org;
    Vec3 du;
    Vec3 dv;
    u32 nu;
    u32 nv;
} Obj;
extern s32 func_80017C4C(s32, s32, Vtx **);
static inline void vscale(Vec3 *v, Vec3 *o, f32 s)
{
    o->x = v->x * s;
    o->y = v->y * s;
    o->z = v->z * s;
}
static inline void vadd(Vec3 *o, Vec3 *a, Vec3 *b)
{
    o->x = a->x + b->x;
    o->y = a->y + b->y;
    o->z = a->z + b->z;
}
void func_8008D760(Obj *o)
{
    Vec3 a, b, c, d;
    Vtx *buf;
    u32 i, j;

    func_80017C4C(o->handle, 0, &buf);
    i = 0;
    while (1) {
        if (!(i < o->nv)) break;
        j = 0;
        while (1) {
            if (!(j < o->nu)) break;
            vscale(&o->du, &a, (f32)j / (f32)(o->nu - 1));
            vscale(&o->dv, &b, (f32)i / (f32)(o->nv - 1));
            vadd(&c, &a, &o->org);
            vadd(&d, &b, &c);
            buf->p.x = d.x;
            buf->p.y = d.y;
            buf->p.z = d.z;
            buf->color = 0xFF00FF;
            buf++;
            j++;
        }
        i++;
    }
}
