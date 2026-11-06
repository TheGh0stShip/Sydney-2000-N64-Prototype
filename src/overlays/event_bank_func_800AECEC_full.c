typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef unsigned int u32;
#define W(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define B(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define SB(p, o) (*(s8 *)((u8 *)(p) + (o)))
extern u8 *D_800FC270;

s32 func_800AECEC(u8 *g)
{
    u32 i;
    u32 n;
    u8 *e;

    n = i = 0;
    for (; i < B(D_800FC270, 0xa0c); i++) {
        e = (u8 *)W(g + 0x8000, 0x13c) + i * 32;
        if (B(e, 3) < 3 && (u32)W(g, 0x35cc) > (u32)W(e, 0x14) && W(g, 0x35cc) != W(e, 0x18))
            n++;
    }
    return n == 0;
}
