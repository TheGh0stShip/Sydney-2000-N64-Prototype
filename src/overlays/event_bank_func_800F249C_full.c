typedef struct Sub {
    char pad0[0x1AC];
    float value;
} Sub;

typedef struct Actor {
    char pad0[0x2FC];
    int mode;
    char pad300[0x1E];
    unsigned short anim;
    Sub *sub;
} Actor;

extern unsigned int D_800F13F0;
extern unsigned short D_8007C104[];
extern unsigned short D_8007C10C;
extern unsigned short D_8007C110[];
extern float D_80078AE4;

static inline unsigned int rand_next(void)
{
    unsigned int r = (D_800F13F0 * 16807) & 0x7FFFFFFF;
    D_800F13F0 = r;
    return r;
}

static inline unsigned int rand_range(unsigned int n)
{
    return ((rand_next() >> 15) * n) >> 16;
}

static inline unsigned int rand_bits(int bits)
{
    unsigned int r;
    r = (D_800F13F0 * 16807) & 0x7FFFFFFF;
    D_800F13F0 = r;
    r >>= 32 - bits;
    return r;
}

void func_800F249C(Actor *a)
{
    if (a->mode == 1) {
        a->anim = D_8007C110[rand_bits(3)];
        return;
    }
    if (a->sub->value > *(float *)0x80078AE4) {
        if (rand_range(10) >= 6) {
            a->anim = D_8007C10C;
            return;
        }
    }
    a->anim = D_8007C104[rand_bits(3)];
}
