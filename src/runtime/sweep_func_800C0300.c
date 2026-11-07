typedef struct { short adj; short pad; void (*fn)(void *); } VEnt;
typedef struct { float x, y, z; } Vec;
typedef struct {
    char p0[0x54];
    Vec pos;
    char p1[0xB4 - 0x60];
    VEnt *vt;
    char p2[0xC0 - 0xB4 - 4];
    int flags;
    int s;
    char p3;
    unsigned char b;
    char p4[212 - 0xCA];
} A212;
typedef struct { char p0[0xBC]; A212 e[4]; } Obj;
typedef struct { char p0[0xD8]; int sh; } Cfg;

extern int D_800F4050[];
extern Cfg *D_800F63F0;
extern void func_80019680(void *, int);
extern void func_8001A1D8(void *, float, float, float, float);
extern void func_8001A210(void *, float, float, float, float, int);
extern void func_800191E0(void *, int);
extern void func_8001A3AC(void *, int);
extern void func_800ADC54(void *, int);

static inline void show(A212 *q, A212 *e)
{
    q->b = 0;
    q->flags |= 0x20000;
    q->vt[8].fn((char *)e + q->vt[8].adj);
}

static inline void vset(Vec *v, float x, float y, float z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

void func_800C0300(Obj *o)
{
    unsigned int i;

    i = 0;
    while (1) {
        A212 *e;
        void *s;
        if (!(i < 4)) {
            break;
        }
        o->e[i].s = 0;
        e = &o->e[i];
        s = &e->s;
        func_80019680(s, D_800F4050[i]);
        func_8001A1D8(s, 0.0f, 0.0f, 301.0f, 82.0f);
        func_8001A210(s, 0.0f, 0.0f, 1.0f, 1.0f, 0);
        func_800191E0(s, 0xC8FFFFFF);
        func_8001A3AC(s, 0x7F00);
        func_800ADC54(e, 1 << D_800F63F0->sh);
        show(&o->e[i], e);
        vset(&o->e[i].pos, (i & 1) * 301, ((i & 2) >> 1) * 82 + 34, 0.0f);
        i++;
    }
}
