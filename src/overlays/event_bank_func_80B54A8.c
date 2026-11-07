typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
extern u8 D_80077660[][4];
extern u8 D_800F3BC0[];
extern void func_800C0110(void *, s32, s32, s32);
void func_800762D8(u8 *o)
{
    s32 a = -1;
    s32 b = -1;
    u8 t = D_80077660[o[23416]][o[23419]];
    if (t == 1 || t == 2) {
        if (*(s32 *)(o + 23456) != 0) {
            a = 482; b = 490;
        } else if (*(s8 *)(o + 23436) == 1) {
            a = 481; b = 489;
        } else {
            a = 485; b = 492;
        }
    } else {
        if (*(s32 *)(o + 23456) != 0) {
            a = 480; b = 488;
        } else if (*(s8 *)(o + 23436) == 2) {
            a = 479; b = 487;
        } else if (*(s8 *)(o + 23436) == 1) {
            a = 484; b = 491;
        } else {
            a = 483;
        }
    }
    if (a != -1 && !(o[23423] == 3 || o[23423] == 4)) {
        func_800C0110(D_800F3BC0, a, 0, 30720);
    }
    if (b != -1 && !(o[23423] == 3 || o[23423] == 4)) {
        func_800C0110(D_800F3BC0, b, 15360, 0xD200);
    }
}
