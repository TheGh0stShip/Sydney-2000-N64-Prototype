typedef unsigned char u8;
typedef int s32;
typedef float f32;

extern u8 *D_800FC270;
extern u8 D_800F26E0[];
extern s32 D_800F2744;
extern void func_800D6EA0(u8 *p);
extern void func_800D29E0(u8 *p);
extern void func_800AB2A4(u8 *a, s32 b, s32 c, u8 *d, s32 e, s32 f);

void func_800B5FC0(u8 *o)
{
    u8 i;

    func_800D6EA0(o + 11784);
    func_800D29E0(o + 12020);
    o[23416] = 0;
    o[23417] = 0;
    o[23418] = 0;
    o[23419] = 0;
    if (o[23509] >= o[23500] || o[23492] == 128) {
        for (i = 0; i < 9; i++) {
            (o + i)[23492] = (o + i)[23501];
        }
    }
    for (i = 0; i < 9; i++) {
        (o + i)[23501] = 0;
    }
    if (o[23423] != 4 || (f32)o[23500] < *(f32 *)(D_800FC270 + 3344)) {
        { s32 *q = (s32 *)(D_800FC270 + 2580); *(s32 *)((u8 *)q + o[23417] * 12) = 0; }
        func_800AB2A4(D_800F26E0, D_800F2744, 24, o, 0, 0);
        return;
    }
    func_800D29E0(o + 12020);
    func_800AB2A4(D_800F26E0, D_800F2744, 7, o, 0, 9);
    *(s32 *)(o + 23412) = 0;
    *(s32 *)(o + 23440) = 15;
}
