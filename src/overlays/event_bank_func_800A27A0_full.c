typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

#define FIELD(p, t, o) (*(t *)((u8 *)(p) + (o)))

extern u8 D_800F26E0[];
extern s32 D_800F2744;
extern u8 *D_800FC270;
extern u8 D_800F1AE0[];
extern u32 D_800F13F0;
extern char D_80077354[];

extern void func_800AB2A4(void *, s32, s32, s32, void *, s32);
extern void func_8009B80C(void *, s32, s32, s32);
extern void func_8009BF6C(void *, s32);
extern void func_8009AEC0(s32, void *);
extern void func_800A9BE8(void *, s32);
extern void func_800750A4(void *);
extern void func_800D33A0(void *, char *, s32, s32);
extern void func_80076C64(void *, s32, s32, s32);
extern void func_800768C8(void *);
extern s32 func_8001D4B8(void *, s32, s32, s32);
extern void func_8001D640(void *, s32, s32);
extern void func_8001D5D8(void *, s32, s32, s32, s32, s32);

static __inline__ s32 scale_vol(s32 v, s32 m) { return (v * m) >> 15; }

static __inline__ u32 rand_n(u32 n)
{
    u32 r = (D_800F13F0 * 0x41A7) & 0x7FFFFFFF;
    D_800F13F0 = r;
    return ((r >> 15) * n) >> 16;
}

void func_800717A0(u8 *arg0)
{
    f32 angle;
    s32 snd;

    angle = *(f32 *)0x8007102C;
    func_800AB2A4(D_800F26E0, D_800F2744, 3, FIELD(arg0, s32, 0x2F8C), arg0 + 0x2F9C, *(s32 *)&angle);
    switch (FIELD(arg0, u8, 0x7CAF)) {
    case 0:
        if ((FIELD(arg0, s32, 0x7CA8) != 0) && (FIELD(arg0, s8, 0x7CAC) == 0)) {
            func_8009B80C(arg0 + 0x2F0, 4, -1, 2);
        } else {
            func_8009BF6C(arg0 + 0x2F0, FIELD(arg0, s32, 0x2FB4));
            func_8009AEC0(2, arg0 + 0x868);
        }
        if (FIELD(arg0, s32, 0x7CA8) != 0) {
            s32 mode = FIELD(D_800FC270, s32, 0xA00);
            switch (mode) {
            case 6:
                func_800A9BE8(arg0 + 0x7AF0, 1);
                FIELD(arg0, s32, 0x7CC0) = 0x38400;
                break;
            case 5:
                func_800A9BE8(arg0 + 0x7AF0, 1);
                FIELD(arg0, s32, 0x7CC0) = 0x14A00;
                break;
            default:
                func_800A9BE8(arg0 + 0x7AF0, 0);
                FIELD(arg0, s32, 0x7CC0) = 0x1C200;
                break;
            }
        } else {
            func_800A9BE8(arg0 + 0x7AF0, 2);
            FIELD(arg0, s32, 0x7CC0) = 0x10E00;
        }
        FIELD(arg0, u8, 0x7CAE) = 1;
        func_800750A4(arg0);
        break;
    case 5:
        func_800A9BE8(arg0 + 0x7AF0, 7);
        FIELD(arg0, s32, 0x7CC0) = 0x9600;
        FIELD(arg0, u8, 0x7CAE) = 1;
        break;
    case 2:
        func_800D33A0(arg0 + 0x2F0, D_80077354, 1, -1);
        func_80076C64(arg0, 0x19, 0, 0);
        func_800A9BE8(arg0 + 0x7AF0, 1);
        FIELD(arg0, s32, 0x7CC0) = 0x25800;
        FIELD(arg0, u8, 0x7CAE) = 1;
        break;
    case 1:
    case 3:
    case 4:
        func_800A9BE8(arg0 + 0x7AF0, 1);
        FIELD(arg0, s32, 0x7CC0) = 0x14A00;
        FIELD(arg0, u8, 0x7CAE) = 1;
        break;
    }
    switch (FIELD(arg0, u8, 0x7CAF)) {
    case 2:
    case 3:
    case 4:
        break;
    case 0:
    case 1:
        func_800768C8(arg0);
        /* fallthrough */
    case 5:
        snd = func_8001D4B8(D_800F1AE0, 0x5F, 0, -1);
        func_8001D640(D_800F1AE0, snd, 0);
        func_8001D5D8(D_800F1AE0, snd, scale_vol(FIELD(D_800F1AE0, s32, 0x68), 0x4CCC), 0x2D, 0, 0);
        FIELD(arg0, s32, 0x7CEC) = snd;
        FIELD(arg0, s32, 0x7D08) = rand_n(0x2D00);
        break;
    }
}
