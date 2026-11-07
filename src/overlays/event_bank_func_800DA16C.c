typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u8 *D_800FC270;
extern u8 D_800F3BC0[];
extern s32 D_80077630[];
extern u8 D_80077494[];
extern void func_800C0110(void *, s32, s32, s32);
extern s32 func_800D98FC(s32);
extern void func_800D33A0(u8 *, void *, s32, s32);
void func_800755FC(u8 *o)
{
    u8 g = o[1548];
    u8 n = o[1553] + g;
    u8 *p = *(u8 **)(o + (g << 2) + 20188);
    u8 idx = p[425];
    s32 sel;
    u16 v;
    s32 x;
    s32 big;
    s32 small;
    if (p[426] != 3 && *(s32 *)(D_800FC270 + 2560) == 5) {
        v = 1;
        sel = p[424];
        big = 16;
        small = 8;
    } else {
        v = 50;
        sel = idx;
        big = 32;
        small = 64;
    }
    if (o[1555] >= 3 && (o[1548] == 0 || o[1548] == o[1555] - 1)) { if (o[1548] != 0) v += small; } else { v += big; }
    x = sel + v;
    if (*(s32 *)(D_800FC270 + 2564) != 0 && *(s32 *)(o + 24968) == 1) {
        func_800C0110(D_800F3BC0, x, 0, 7680);
    }
    D_80077630[0] = n + 1;
    D_80077630[1] = func_800D98FC(idx + 149);
    func_800D33A0(o + 12884, D_80077494, 0, -1);
}
