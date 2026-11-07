typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct { u8 pad[3355]; u8 a; u8 p[3]; u8 b; } G;
extern G *D_800FC270;
extern u8 D_800F2AD8[];
extern u8 D_800F2758[];
extern void func_80015EAC(s32);
extern void func_80070D10(u8 *, s32, s32);
extern void func_800720C8(u8 *);
extern void func_800177AC(void);
extern void func_800BBD78(void *, s32, s32, u8 *, s32);
extern void func_800AA658(void *, u8 *);
extern void func_800828B4(u8 *, s32);
extern void func_80083700(u8 *, s32);
extern void func_800BC07C(void *, s32);
extern void func_80083A0C(u8 *);
extern void func_80070F04(u8 *, s32);
void func_80070B40(u8 *o, s32 *m)
{
    s32 d = (m[1] - *(s32 *)(o + 16)) >> 8;
    u32 s;
    u8 *a;
    switch (m[0]) {
    case 3:
        func_80015EAC(12);
        func_80070D10(o, D_800FC270->a, D_800FC270->b);
        func_800720C8(o);
        func_800177AC();
        break;
    case 7:
        switch ((u32)m[4]) {
        case 8:
        case 15:
            func_800BBD78(D_800F2AD8, 12, 1, o, 0);
            break;
        case 7:
        case 57:
            func_800AA658(D_800F2758, o + 17132);
            func_800828B4(o, m[4]);
            break;
        }
        break;
    case 1:
        func_80083700(o, m[4]);
        break;
    case 2:
        s = *(u32 *)(o + 17124);
        a = (u8 *)(m + 4);
        if (s >= 2 && s != 3) {
            func_800BC07C(*(void **)(o + 3868), a[1]);
            if ((*(u8 **)(o + 3868))[3] & 0x10) {
                *(s32 *)(o + 18348) = 1;
            }
        } else {
            func_800BC07C(*(void **)(o + 3868), a[1]);
            if ((*(u8 **)(o + 3868))[3] != 0) {
                *(s32 *)(o + 3860) = 1;
            }
        }
        func_80070F04(o, d);
        break;
    case 5:
        func_80083A0C(o);
        func_80070F04(o, d);
        break;
    case 12:
        break;
    }
    *(s32 *)(o + 16) = m[1];
}
