typedef unsigned char u8;
typedef int s32;
typedef float f32;

typedef struct Vec { f32 x, y, z; } Vec;


extern void func_800B7824(u8 *p, s32 a);
extern void func_800AE72C(u8 *a, u8 *b, s32 c);
extern void func_800AD2A8(u8 *a, u8 *b, u8 *c, s32 d);
extern void func_800ADC38(u8 *a);
extern void func_800AD9E8(u8 *a);

#define W(o) (*(s32 *)(p + (o)))
#define F(o) (*(f32 *)(p + (o)))
#define B(o) (*(u8 *)(p + (o)))
#define V(o) ((Vec *)(p + (o)))

static inline void vcopy(Vec *d, Vec *s)
{
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

static inline void vadd(Vec *d, Vec *s)
{
    d->x += s->x;
    d->y += s->y;
    d->z += s->z;
}

static inline void tset(Vec *t, f32 y)
{
    t->z = 0.0f;
    t->y = y;
}

void func_800E5700(u8 *p)
{
    u8 *q;
    u8 *r;
    Vec t;

    q = *(u8 **)(p + 4);
    F(608) = F(3056);
    func_800B7824(p, 0);
    r = p + 616;
    W(2748) = 0;
    *(s32 *)(r + 12) = 1;
    *(s32 *)(r + 56) = 1;
    func_800AE72C(r, p + 712, W(2892));
    vcopy(V(2788), V(796));
    B(2912) = 0;
    func_800AE72C(r, p + 1984, W(2892));
    func_800AD2A8(p + 2004, p + 2620, p + 2068, 1);
    func_800ADC38(p + 1984);
    func_800AE72C(r, p + 2196, W(2892));
    func_800AD2A8(p + 2216, p + 2632, p + 2280, 1);
    func_800ADC38(p + 2196);
    func_800AE72C(r, p + 2408, W(2892));
    func_800AD2A8(p + 2428, p + 2644, p + 2492, 1);
    func_800ADC38(p + 2408);
    if (*(s32 *)(q + 740) == 0) {
        t.x = 42.597095f;
        tset(&t, 18.021849f);
    } else {
        t.x = -42.597095f;
        tset(&t, 18.021849f);
    }
    vadd(V(2068), &t);
    vadd(V(2280), &t);
    vadd(V(2492), &t);
    func_800AD9E8(p + 1984);
    func_800AD9E8(p + 2196);
    func_800AD9E8(p + 2408);
    F(3036) = F(796);
    if (W(2888) == 0) {
        vcopy(V(2916), V(796));
    }
    W(2940) = 0;
    {
        Vec *v = V(2928);
        v->x = 0.0f;
        v->y = 0.0f;
        v->z = -1.0f;
    }
}
