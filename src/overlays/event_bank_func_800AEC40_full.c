typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef unsigned int u32;
#define W(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define B(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define SB(p, o) (*(s8 *)((u8 *)(p) + (o)))
typedef struct { short a; short h; float f; s8 c; s8 d; u8 b; u8 pad; } Rec;
typedef struct { u8 pad[0xa10]; Rec r[1]; } Glob;
extern u8 *D_800FC270;

s32 func_800AEC40(u8 *g)
{
    u8 *h = g + 0x8000;
    u32 n = 0;
    u32 i;
    u8 *e;

    if ((u8)(B(h, 0x11e) - 3) < 2)
        return n;
    for (i = 0; i < B(D_800FC270, 0xa0c); i++) {
        e = (u8 *)W(h, 0x13c) + i * 32;
        if (B(e, 3) < 3)
            n++;
    }
    if (n == 1 && ((Glob *)D_800FC270)->r[SB(g + 0x8000, 0x11c)].c == 0)
        return 1;
    return 0;
}
