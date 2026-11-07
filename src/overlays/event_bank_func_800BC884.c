typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct Vec { f32 x, y, z; } Vec;
typedef struct Mtx { f32 m[3][4]; u8 pad[16]; Vec pos; } Mtx;
typedef struct G { u8 pad[40]; f32 a, b, c; } G;
typedef struct Obj { u8 pad[92]; f32 y; u8 pad2[96]; s32 flags; } Obj;
extern G *D_800FC270;

extern s32 func_80017D84(char *s, s32 a);
extern void func_80081F08(u8 *p, Vec *a, Vec *b, u8 *c, s32 d);
extern void func_8008382C(u8 *p, s32 a);
extern void func_800837C0(u8 *p, s32 a, f32 v);
extern void func_80071948(u8 *p);
extern void func_800AD434(Mtx *m, f32 a, s32 b);
extern void func_800830C4(u8 *p, Mtx *m, f32 v);
extern void func_800BB99C(u8 *a, f32 b, f32 c, s32 d);
extern void func_800BBA1C(u8 *a);
extern void func_80071D2C(u8 *p);
extern void func_800AD890(Obj *o, s32 a);
extern void func_800AD9E8(Obj *o);
extern void func_80082A84(u8 *p, s32 a, s32 b, s32 c, s32 d, s32 e);

#define W(o) (*(s32 *)(p + (o)))
#define F(o) (*(f32 *)(p + (o)))
#define B(o) (*(u8 *)(p + (o)))
#define OBJ(i) (((Obj **)(p + 17148))[i])

static inline void vset(Vec *v, f32 x, f32 y, f32 z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void reset(Mtx *m)
{
    m->m[2][1] = 0.0f;
    m->m[2][0] = 0.0f;
    m->m[1][2] = 0.0f;
    m->m[1][0] = 0.0f;
    m->m[0][2] = 0.0f;
    m->m[0][1] = 0.0f;
    m->pos.z = 0.0f;
    m->pos.y = 0.0f;
    m->pos.x = 0.0f;
    m->m[2][2] = 1.0f;
    m->m[1][1] = 1.0f;
    m->m[0][0] = 1.0f;
}

void func_800BC884(u8 *p)
{
    Vec v1;
    Vec v2;
    Mtx m;
    u8 i;
    f32 h;
    f32 s;
    f32 t;
    f32 u;
    u8 *q;

    if (func_80017D84("GRAPHICS__VIRTUALGYM__HEIGHTDEPTHJUMP__HDJUMP_BGP", -1) != 0) {
        return;
    }
    vset(&v2, 98.300995f, 16.3835f, 0.0f);
    vset(&v1, 0.0f, 49.150497f, -163.83499f);
    func_80081F08(p, &v1, &v2, p + 4552, 0);
    func_8008382C(p, 5);
    func_800837C0(p, 0, 1.0f);
    func_80071948(p);
    reset(&m);
    m.pos.x = 40.958748f;
    m.pos.y = 32.767f;
    m.pos.z = 29.490297f;
    func_800AD434(&m, -1.5707961f, 3);
    func_800830C4(p, &m, 0.25f);
    q = p + 4996;
    s = D_800FC270->a * 0.25f + D_800FC270->b * 0.75f;
    h = *(f32 *)(q + 4588);
    t = h / 40.0f * D_800FC270->c;
    F(17464) = 0.007f;
    F(17456) = 0.003f;
    F(17460) = 0.005f;
    F(17452) = h / 35.0f - t;
    F(17468) = s * 0.007f + 0.005f;
    {
        u8 *r = p + 4968;
        func_800BB99C(r, 0.05f, -0.0015f, 0);
        func_800BBA1C(r);
    }
    *(s32 *)(q + 4596) = 0;
    W(17132) = 0;
    W(3860) = 0;
    W(17596) = 0;
    W(17604) = 0;
    W(17592) = 1;
    W(17584) = 0;
    W(17572) = 0;
    W(17588) = 0;
    W(17576) = 0;
    W(17568) = 0;
    W(17600) = 0;
    B(17552) = 0;
    B(17204) = 0;
    B(17208) = 0;
    B(17207) = 0;
    B(17206) = 0;
    B(17205) = 0;
    F(17144) = 0.1f;
    F(17140) = 0.06f;
    func_80071D2C(p);
    OBJ(0)->y = -49.1505f;
    OBJ(0)->flags &= ~4;
    func_800AD890(OBJ(0), 1);
    func_800AD9E8(OBJ(0));
    i = 1;
    while (1) {
        if (!(i < W(17556))) {
            break;
        }
        (*(Obj **)(p + (i << 2) + 17148))->y = i * -29.490301f + -49.1505f;
        (*(Obj **)(p + (i << 2) + 17148))->flags &= ~4;
        func_800AD890((*(Obj **)(p + (i << 2) + 17148)), 1);
        func_800AD9E8((*(Obj **)(p + (i << 2) + 17148)));
        i++;
    }
    W(3852) = 23040;
    func_80082A84(p, 5, 0, 0, 0, 0);
    func_80082A84(p, 38, W(17556), 0, 0, 0);
}
