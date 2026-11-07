typedef int s32;
typedef unsigned char u8;
typedef struct { u8 pad[104]; s32 vol; } Snd;
typedef struct { float x, y, z; } Vec;
typedef struct { float a; s32 b; s32 c; } Arg;
typedef struct { u8 pad[84]; Vec pos; u8 pad2[176]; u8 tail[76]; } Ent;
extern Snd D_800F1AE0;
extern s32 func_8001D4B8(Snd *, s32, s32, s32);
extern void func_8001D640(Snd *, s32, s32);
extern float func_800AD7D0(Vec *);
extern void func_800AEC30(void *, Arg *, float);
static inline s32 scl(s32 v, s32 m)
{
    return (v * m) >> 15;
}
static inline void vsub(Vec *a, Vec *b, Vec *r)
{
    r->x = a->x - b->x;
    r->y = a->y - b->y;
    r->z = a->z - b->z;
}
static inline void hit(u8 *t, Arg *q)
{
    func_800AEC30(t, q, -0.3571603f);
}
void func_80071774(u8 *o)
{
    Vec d;
    Arg q;
    u8 i;
    i = 0;
    q.b = 0;
    q.c = 0;
    q.a = -1.3652916f;
    while (1) {
        s32 m;
        if (!(i < 8)) break;
        m = 1 << i;
        if (*(s32 *)(o + 17360) & m) {
            vsub((Vec *)(o + 17232), &(*(Ent **)(o + 17364))[i].pos, &d);
            if (func_800AD7D0(&d) < *(float *)(o + 17588) + *(float *)(o + 17584)) {
                func_8001D640(&D_800F1AE0, func_8001D4B8(&D_800F1AE0, 87, 0, 1), scl(D_800F1AE0.vol, 32767));
                o[17654]++;
                hit((*(Ent **)(o + 17364))[i].tail, &q);
                *(s32 *)(o + 17360) &= ~m;
            }
        }
        i++;
    }
}
