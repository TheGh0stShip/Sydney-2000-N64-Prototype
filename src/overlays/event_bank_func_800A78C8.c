typedef unsigned char u8;
typedef int s32;
typedef float f32;

typedef struct Vec { f32 x, y, z; } Vec;
typedef struct G {
    u8 pad[1284];
    f32 h0;
    u8 pad1[1328 - 1288];
    f32 h1;
    u8 pad2[2560 - 1332];
    s32 mode;
    u8 pad3[3564 - 2564];
    f32 h2;
} G;
extern G *D_800FC270;

extern void func_800ADC1C(u8 *p);
extern void func_800AD9E8(u8 *p);
extern void func_800ADC38(u8 *p);

static inline void vcopy(Vec *d, Vec *s)
{
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

typedef struct O { u8 pad[64]; Vec pos; } O;

static inline void getpos(Vec *d, O *o)
{
    d->x = o->pos.x;
    d->y = o->pos.y;
    d->z = o->pos.z;
}

static inline void setpos(O *o, Vec *s)
{
    o->pos.x = s->x;
    o->pos.y = s->y;
    o->pos.z = s->z;
}


void func_800A78C8(u8 *p)
{
    Vec a;
    Vec b;

    getpos(&a, (O *)(p + 12264));
    a.x += 137.621384f;
    a.y += 16.3835f;
    vcopy(&b, &a);
    b.x += 13.1067991f;
    func_800ADC1C(p + 12668);
    func_800ADC1C(p + 12880);
    func_800ADC1C(p + 13092);
    if (D_800FC270->mode == 4) {
        b.z -= D_800FC270->h1 * 32.767f;
        setpos((O *)(p + 12688), &b);
        func_800AD9E8(p + 12668);
        func_800ADC38(p + 12668);
    }
    if (D_800FC270->mode == 5) {
        a.z -= D_800FC270->h2 * 32.767f;
        setpos((O *)(p + 13112), &a);
        func_800AD9E8(p + 13092);
        func_800ADC38(p + 13092);
    } else if (D_800FC270->mode == 4 || D_800FC270->mode == 0 ||
               D_800FC270->mode == 1 || D_800FC270->mode == 2) {
        if (p[31919] != 4) {
            a.z -= D_800FC270->h0 * 32.767f;
            setpos((O *)(p + 12900), &a);
            func_800AD9E8(p + 12880);
            func_800ADC38(p + 12880);
        }
    }
}
