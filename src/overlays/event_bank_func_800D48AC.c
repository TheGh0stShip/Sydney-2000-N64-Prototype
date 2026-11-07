typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef unsigned int u32;

typedef struct T9 { s8 b[9]; } T9;
extern T9 D_80070850;
extern u32 D_800F2714;

#define B(o) (*(s8 *)(p + (o)))
#define W(o) (*(s32 *)(p + (o)))

static inline u32 rnd(u32 n)
{
    D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
    return ((D_800F2714 >> 15) * n) >> 16;
}

void func_800D48AC(u8 *p)
{
    T9 t;
    u8 i;

    t = D_80070850;
    i = 0;
    if (--W(19780) < 0) {
        W(19812) = 1;
    }
    W(3860) = 0;
    switch (B(19722)) {
    case 1:
        i = rnd(3);
        break;
    case 2:
        i = rnd(6);
        break;
    case 3:
        i = rnd(9);
        break;
    }
    p[19744] = t.b[i];
}
