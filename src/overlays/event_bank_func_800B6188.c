typedef int s32;
typedef unsigned char u8;
extern u8 *D_800FC270;
extern u8 D_800F3BC0[];
extern void func_800C0110(void *, s32, s32, s32);
extern void func_80076944(u8 *);
void func_80076FB8(u8 *o)
{
    u8 *p = *(u8 **)(o + 21292);
    u8 idx;
    s32 sel;
    s32 base;
    s32 n;
    o[23422] = 0;
    idx = p[425];
    if (p[426] != 3 && *(s32 *)(D_800FC270 + 2560) == 5) { base = 0; sel = p[424]; } else { base = 28; sel = idx; }
    n = sel + base;
    if (o[23423] != 3 && o[23423] != 4) {
        func_800C0110(D_800F3BC0, n, 0, 0);
    }
    if (*(s32 *)(D_800FC270 + 2560) == 4 && o[23416] == 0) {
        func_80076944(o);
    }
}
