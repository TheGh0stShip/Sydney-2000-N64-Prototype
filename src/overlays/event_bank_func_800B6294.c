typedef unsigned char u8;
typedef int s32;
typedef float f32;
#define W(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define P(p, o) (*(u8 **)((u8 *)(p) + (o)))
#define B(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define K1 (*(f32 *)0x80071510)
#define K2 (*(f32 *)0x80071514)
void func_800B6294(u8 *s, u8 a, u8 b, u8 c)
{
    s32 t;
    W(s, 0x5BA0) = 0;
    if (a == 0 || b == 0) return;
    if (B(P(s, 0x532C), 0x1AA) != 1) return;
    if (c != 0) {
        if (F(s, 0x545C) < K1) W(s, 0x5BA0) = 1;
    } else if (a == 2) {
        t = 0; if (F(s, 0x545C) < K2 && F(s, 0x5590) < K2) t = 1;
        if (t) { W(s, 0x5BA0) = 1; } else { t = 2; }
    }
}
