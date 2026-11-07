typedef int s32;
typedef unsigned char u8;
extern u8 *D_800FC270;
extern void func_80073E8C(u8 *);
extern void func_80077378(u8 *);
extern void func_8009C0D8(s32, s32);
void func_80077404(u8 *o)
{
    s32 st;
    u8 *g;
    o[1550]++;
    g = D_800FC270;
    if (o[1550] < g[2572]) st = 2; else if (*(s32 *)(g + 2560) != 5 || (g[3410] & 4)) st = 0; else st = 1;
    switch (st) {
    case 2:
        func_80077378(o);
        break;
    case 1:
        func_8009C0D8(1, -1);
        break;
    case 0:
        func_80073E8C(o);
        break;
    }
}
