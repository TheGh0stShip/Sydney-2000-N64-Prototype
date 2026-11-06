typedef struct Entry {
    int a;
    int b;
} Entry;

typedef struct Ctx {
    char pad0[0xD53];
    unsigned char idx;
} Ctx;

typedef struct Inner {
    char pad0[0x811E];
    unsigned char mode;
} Inner;

typedef struct Obj {
    char pad0[4];
    Inner *inner;
    char pad8[0x276];
    unsigned short state;
    int timer;
    char pad284[0x59];
    unsigned char spread;
} Obj;

extern unsigned int D_800F2C14;
extern int D_800F2778;
extern Ctx *D_800FC270;
extern Entry D_8007B540[];
extern Entry D_8007B550;

static inline unsigned int rand_next(void)
{
    unsigned int r = (D_800F2C14 * 16807) & 0x7FFFFFFF;
    D_800F2C14 = r;
    return r;
}

static inline unsigned int rand_range(unsigned int n)
{
    return ((rand_next() >> 15) * n) >> 16;
}

unsigned short func_8010AECC(Obj *a, int now)
{
    Entry *e;
    int k;

    now -= D_800F2778;
    if (a->inner->mode == 2) {
        e = &D_8007B550;
    } else {
        e = &D_8007B540[D_800FC270->idx];
    }
    if (now >= a->timer) {
        if (a->state & 1) {
            a->state = 2;
        } else {
            a->state = 1;
        }
        k = e->b;
        if (a->spread) {
            k += (unsigned int)(k * rand_range(a->spread)) / 100;
        }
        a->timer += k;
    }
    return a->state;
}
