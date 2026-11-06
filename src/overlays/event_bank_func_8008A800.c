typedef unsigned char u8;
typedef int s32;

extern u8 D_800F2AD0[];
extern u8 D_800F26E0[];
extern u8 D_800F3BC0[];
extern s32 D_800F2744;
extern volatile s32 D_800F2728;

extern void func_800735F4(u8 *, s32);
extern void func_80074DAC(u8 *, float);
extern void func_80076EB8(u8 *);
extern float func_8007B04C(u8 *);
extern void func_8009C0D8(s32, s32);
extern void func_800AACB0(u8 *, u8 *, s32);
extern void func_800AB2A4(u8 *, s32, s32, u8 *, s32, s32);
extern void func_800AC25C(u8 *, s32, s32, s32);
extern void func_800BC07C(u8 *, s32);
extern void func_800C013C(u8 *);
extern void func_800D29E0(u8 *);

#define PB(o) (*(u8 *)(obj + 0x8000 + (o)))
#define PW(o) (*(s32 *)(obj + 0x8000 + (o)))

void func_80072490(u8 *obj, u8 *evt, s32 arg)
{
    u8 f;
    u8 *o;

    func_800BC07C(D_800F2AD0, evt[0x11]);
    f = D_800F2AD0[3];
    if (f & 0x10) {
        if (PW(0x444) == 0) {
            PW(0x260) = 15;
            func_8009C0D8(2, D_800F2AD0[0] >> 5);
        }
    } else if (f & 2) {
        if (PW(0x444) != 0) {
            PW(0x260) = 0;
            func_800AB2A4(D_800F26E0, D_800F2744, 7, obj, 0, 9);
        } else {
            PW(0x260) = 15;
            func_8009C0D8(0, D_800F2AD0[0] >> 5);
        }
    } else if (f & 8) {
        if (PW(0x444) != 0) {
            PW(0x260) = 0;
            func_800AB2A4(D_800F26E0, D_800F2744, 7, obj, 0, 9);
        } else if (PB(0x416) == 15) {
            PW(0x428) = 0x700;
            func_800C013C(D_800F3BC0);
        } else if (PB(0x417) == 5) {
            PB(0x416) = 0x12;
            D_800F2728 = 0;
            func_800C013C(D_800F3BC0);
        } else if (PB(0x417) == 2) {
            func_800D29E0(obj + 0x2B8);
            PW(0x428) = 0;
            PB(0x416) = 14;
            PW(0x43C) = 0;
            *(s32 *)(obj + 0x2F48) = 0;
        } else if ((o = *(u8 **)(obj + 0x59DC)) != 0) {
            if (o[0x1AA] == 1) {
                switch (PB(0x416)) {
                case 1:
                case 2:
                    func_800D29E0(obj + 0x2B8);
                    func_800D29E0(obj + 0x830);
                    func_800D29E0(obj + 0xDA8);
                    func_800D29E0(obj + 0x1320);
                    func_800AC25C(obj, 0x5E, 0x11, 0);
                    PW(0x428) = 0x700;
                    if (PW(0x42C) > 0) {
                        PW(0x42C) = 0x100;
                    }
                    func_800C013C(D_800F3BC0);
                    break;
                case 13:
                case 14:
                    func_800D29E0(obj + 0x2B8);
                    {
                        u8 *q = obj + 0x8000;
                        if ((u8)(q[0x417] - 3) < 2) {
                            func_80076EB8(obj);
                            func_800AB2A4(D_800F26E0, D_800F2744, 0x18, obj, 0, 0);
                        } else {
                            q[0x416] = 0x10;
                        }
                    }
                    break;
                }
            } else {
                func_800D29E0(obj + 0x830);
                func_800D29E0(obj + 0xDA8);
                func_800D29E0(obj + 0x1320);
                PB(0x418) = PB(0x417);
                if ((u8)(PB(0x416) - 13) >= 2) {
                    func_80074DAC(obj, func_8007B04C(*(u8 **)(obj + 0x59DC)));
                }
                PB(0x416) = 0x12;
                func_800AACB0(D_800F26E0, obj, 0);
            }
        }
    }
    func_800735F4(obj, arg);
}
