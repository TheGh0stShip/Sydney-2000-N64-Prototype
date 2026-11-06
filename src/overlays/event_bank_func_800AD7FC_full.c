typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef float f32;
#define W(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define B(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))

typedef struct { short a; short h; f32 f; s8 c; s8 d; u8 b; u8 pad; } Rec;
typedef struct { u8 pad[0xa10]; Rec r[1]; } Glob;
extern u8 *D_800FC270;

void func_800AD7FC(u8 *g)
{
    u8 *d = D_800FC270;
    f32 v = ((Glob *)d)->r[*(s8 *)(g + 0x811c)].f;
    s32 st;

    if (W(d, 0xa00) == 5 && F(d, 0xe00) < v)
        F(d, 0xe00) = v;
    st = W(D_800FC270, 0xa00);
    if (st == 4 || st == 0 || st == 1 || st == 2) {
        if (B(g + 0x8000, 0x11e) != 4 && F(D_800FC270, 0x518) < v)
            F(D_800FC270, 0x518) = v;
    }
    if (W(D_800FC270, 0xa00) == 4 && F(D_800FC270, 0x544) < v)
        F(D_800FC270, 0x544) = v;
}
