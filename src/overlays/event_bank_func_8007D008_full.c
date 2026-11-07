typedef unsigned int u32;
typedef unsigned short u16;

typedef struct {
    u32 seed;
} Rng;

extern Rng D_800F13F0;
extern u16 D_8007D960[];

static inline u32 rnd(Rng *g, u32 n)
{
    g->seed = (g->seed * 16807) & 0x7FFFFFFF;
    return ((g->seed >> 15) * n) >> 16;
}
typedef struct {
    char pad0[0x1AE];
    short h[8];
} Obj;

void func_8007D008(Obj *o)
{
    u32 n;
    u32 i;

    n = rnd(&D_800F13F0, 2);
    i = 0;
    while (1) {
        if (i > n) {
            break;
        }
        o->h[i] = D_8007D960[rnd(&D_800F13F0, 3)];
        i++;
    }
    o->h[i] = -1;
}

