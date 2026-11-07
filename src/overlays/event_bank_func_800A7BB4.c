typedef unsigned char u8;
typedef int s32;

extern u8 *D_800FC270;
extern char D_800F3BC0[];

extern void func_800C0110(char *a, s32 b, s32 c, s32 d);
extern void func_80075838(u8 *a);

void func_80076BB4(u8 *p)
{
    u8 *o;
    u8 a;
    s32 x;
    s32 base;
    s32 r;

    o = *(u8 **)(p + 12212);
    a = o[0x1A9];
    *(s32 *)(p + 31912) = 0;
    if (o[0x1AA] != 3 && *(s32 *)(D_800FC270 + 0xA00) == 5) {
        base = 0;
        x = o[0x1A8];
    } else {
        base = 31;
        x = a;
    }
    r = x + base;
    if (p[31919] != 3 && p[31919] != 4) {
        func_800C0110(D_800F3BC0, r, 15360, 0x12C00);
    }
    if (*(s32 *)(D_800FC270 + 0xA00) == 4) {
        func_80075838(p);
    }
}
