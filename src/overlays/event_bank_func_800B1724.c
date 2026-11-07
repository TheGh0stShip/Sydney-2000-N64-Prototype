typedef int s32;
typedef unsigned char u8;
extern u8 D_80077660[][4];
extern u8 D_800F26E0[];
extern s32 D_800F272C[];
extern void func_800A9AE4(u8 *, u8 *);
extern void func_800A9BE8(u8 *, s32);
extern void func_800AB2A4(void *, s32, s32, void *, s32, s32);
extern void func_800D29E0(u8 *);
void func_80072554(u8 *o)
{
    u8 v;
    u8 *e;
    v = D_80077660[o[23416]][o[23419]];
    *(s32 *)(o + 23412) = 3;
    *(s32 *)(o + 23428) = 115200;
    o[23450] = 15;
    if (o[23423] != 5) {
        e = *(u8 **)(o + 21292);
        if (e[426] == 1 || o[23423] == 2) {
            func_800A9AE4(o + 22984, e + 820);
        } else if (o[23423] != 5) {
            func_800A9BE8(o + 22984, 11);
        }
    }
    func_800D29E0(o + 12020);
    func_800D29E0(o + 14820);
    func_800D29E0(o + 16220);
    func_800D29E0(o + 17620);
    switch (v) {
    case 0:
        break;
    case 1:
    case 2:
        func_800AB2A4(D_800F26E0, D_800F272C[6], 15, o + 21296, 0, 0);
        if (o[23423] == 5) {
            func_800A9BE8(o + 22984, 13);
        }
        break;
    case 3:
    case 4:
        func_800AB2A4(D_800F26E0, D_800F272C[6], 15, o + 21296, 0, 0);
        func_800AB2A4(D_800F26E0, D_800F272C[6] + 2304, 15, o + 21604, 0, 0);
        if (o[23423] == 5) {
            func_800A9BE8(o + 22984, 15);
        }
        break;
    }
}
