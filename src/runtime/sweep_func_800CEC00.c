typedef struct { float m[19]; } Mtx;
typedef struct { short hi, lo, z; } Dig;
typedef struct {
    char p0[0xD4];
    float ang;
    char p1[0x18C - 0xD8];
    float pos[2];
    char p2[0x43C - 0x194];
    char snd[0x518 - 0x43C];
    Dig d;
} Obj;
typedef struct { char p0[0x68]; int vol; } Aud;

extern Dig *D_800F1270;
extern char D_800F4944[];
extern float D_800F495C;
extern unsigned int D_800F4940;
extern Aud D_800F1AE0;
extern void func_800B31EC(int);
extern void func_800B360C(void *, void *);
extern void func_800AD388(Mtx *, float, int);
extern void func_800AD2A8(Mtx *, float *, void *, int);
extern int func_8001D4B8(Aud *, int, int, int);
extern void func_8001D640(Aud *, int, int);

void func_800CEC00(Obj *o, float a)
{
    float dir[3] = { 48.0f, 0.0f, 0.0f };
    Mtx m;
    Mtx *p;
    unsigned int n;
    int x;

    o->ang = a;
    n = a * 57.29578f + 0.5f;
    o->d.z = 0;
    o->d.hi = n / 10 + 4;
    o->d.lo = n % 10 + 4;
    func_800B31EC(3);
    D_800F1270 = &o->d;
    func_800B360C(o->snd, D_800F4944);
    m.m[9] = 0.0f;
    m.m[8] = 0.0f;
    m.m[6] = 0.0f;
    m.m[4] = 0.0f;
    m.m[2] = 0.0f;
    m.m[1] = 0.0f;
    m.m[18] = 0.0f;
    m.m[17] = 0.0f;
    m.m[16] = 0.0f;
    p = &m;
    p->m[10] = 1.0f;
    p->m[5] = 1.0f;
    m.m[0] = 1.0f;
    func_800AD388(&m, -a, 3);
    m.m[1] *= D_800F495C;
    func_800AD2A8(&m, dir, o->pos, 0);
    o->pos[1] += 29.0f;
    D_800F4940 += 5;
    if (D_800F4940 >= 6) {
        x = D_800F4940 * 32767 / 100;
        func_8001D640(&D_800F1AE0, func_8001D4B8(&D_800F1AE0, 203, 0, 0), x * D_800F1AE0.vol >> 15);
    }
}
