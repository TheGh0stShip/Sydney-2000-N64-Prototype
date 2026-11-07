typedef int s32;
typedef short s16;
typedef unsigned int u32;
typedef unsigned char u8;
extern u8 *D_800FC270;
extern u32 D_800F2714;
extern u8 D_800F3BC0[];
extern void func_800C0110(void *, s32, s32, s32);
void func_80075748(u8 *o)
{
    u8 *p = *(u8 **)(o + (o[1548] << 2) + 20188);
    u8 k = p[733];
    u8 *e = o + k * 20;
    s32 a;
    s32 b;
    if (*(s16 *)(e + 24766) == 1) {
        return;
    }
    a = 168;
    if (*(s32 *)(e + 24748) <= 0x9000 && *(s32 *)(e + 24752) < 2305) {
        b = 243;
        a = 176;
    } else {
        b = 242;
    }
    a += k;
    if (*(s32 *)(D_800FC270 + 2564) != 0 && *(s32 *)(o + 24968) == 1) {
        func_800C0110(D_800F3BC0, a, 0, 0);
    }
    D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
    if ((D_800F2714 >> 28) < 5 && *(s32 *)(D_800FC270 + 2564) != 0 && *(s32 *)(o + 24968) == 1) {
        func_800C0110(D_800F3BC0, b, 0, 0);
    }
}
