typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef int M2C_UNK;
#define M2C_FIELD(p,t,o) (*(t)((u8 *)(p)+(o)))
typedef struct Obj5E00 { char pad[0x5E00]; s32 f5E00; } Obj5E00;
#define M2C_BITWISE(t,x) (*(t *)&(x))

extern char D_800445F0[];
extern char D_800757D4[];
extern char D_800757E4[];
extern char D_80075824[];
extern char D_8007584C[];
extern char D_800758C4[];
extern char D_80075914[];
extern char D_8007593C[];
extern char D_80075964[];
extern char D_8007598C[];
extern char D_800759B4[];
extern char D_800759F0[];
extern char D_800F13F0[];
extern char D_800F1AE0[];
extern char D_800F2714[];
extern char D_800F2724[];
extern s32 D_800F2728;
extern char D_800F2744[];
extern char D_800F2778[];
extern char D_800F2780[];
extern char D_800F2AD8[];
extern char D_800F4D00[];
extern char D_800FC270[];
M2C_UNK func_80008540(M2C_UNK);                     /* extern */
s32 func_8001d4b8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8001d640(M2C_UNK, s32, s32);           /* extern */
M2C_UNK func_800721ec(void *);                      /* extern */
M2C_UNK func_80072a5c(void *);                      /* extern */
M2C_UNK func_80072e24(void *);                      /* extern */
M2C_UNK func_800732ac(void *, M2C_UNK);             /* extern */
M2C_UNK func_80073438(void *);                      /* extern */
M2C_UNK func_80073b80(void *);                      /* extern */
M2C_UNK func_80074400(void *);                      /* extern */
M2C_UNK func_80074510(void *, s32);                 /* extern */
M2C_UNK func_80074800(void *, M2C_UNK);             /* extern */
M2C_UNK func_80074970(void *);                      /* extern */
M2C_UNK func_80074b9c(void *);                      /* extern */
M2C_UNK func_80074cf4(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80074d14(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80075254(void *);                      /* extern */
M2C_UNK func_8009b0e4(M2C_UNK, u8, void *, M2C_UNK, s32, s32, s32); /* extern */
M2C_UNK func_800a31bc(M2C_UNK);                     /* extern */
M2C_UNK func_800a3394(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800a9be8(void *, M2C_UNK);             /* extern */
M2C_UNK func_800ac25c(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800adc38(void *);                      /* extern */
M2C_UNK func_800adc54(void *, s32);                 /* extern */
M2C_UNK func_800bbd78(s32, M2C_UNK, M2C_UNK, void *, s32); /* extern */
M2C_UNK func_800bc104(M2C_UNK);                     /* extern */
M2C_UNK func_800bc180(M2C_UNK);                     /* extern */
M2C_UNK func_800d2164(void *, f32);                 /* extern */
M2C_UNK func_800d2328(void *);                      /* extern */
M2C_UNK func_800d29e0(void *);                      /* extern */
M2C_UNK func_800d33a0(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800d771c(void *);                      /* extern */

static __inline__ s32 scale_vol(s32 v, s32 m) { return (v * m) >> 15; }

static __inline__ u32 rand_n(u32 n)
{
    u32 r = (*(u32 *)D_800F2714 * 0x41A7) & 0x7FFFFFFF;
    *(u32 *)D_800F2714 = r;
    return ((r >> 15) * n) >> 16;
}

void func_800716F0(void *arg0, s32 arg1) {
    f32 sp20;
    M2C_UNK var_a1;
    M2C_UNK var_a1_2;
    M2C_UNK var_a2;
    s32 var_bits;
    s32 temp_v0;
    s32 temp_v0_10;
    s32 temp_v0_11;
    s32 temp_v0_12;
    s32 temp_v0_13;
    s32 temp_v0_14;
    s32 temp_v0_15;
    s32 temp_v0_18;
    s32 temp_v0_19;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_v0_9;
    s32 temp_v1_3;
    s32 var_s0;
    s32 var_v0;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v1_2;
    s32 var_v1_3;
    u32 temp_a0;
    u32 temp_v1_4;
    u8 temp_v0_16;
    u8 temp_v1;
    u8 temp_v1_2;
    u8 temp_v1_5;
    u8 temp_v1_6;
    u8 var_v0_2;
    void *temp_s1;
    void *temp_v0_17;
    void *var_a0;

    if (arg1 != 0) {
        if (M2C_FIELD(arg0, s32 *, 0x5E24) == 1) {
            temp_v0 = *(s32 *)D_800F2780 - 0x100;
            *(s32 *)D_800F2780 = temp_v0;
            if (temp_v0 <= 0) {
                M2C_FIELD(arg0, u8 *, 0x5DE6) = 0U;
                M2C_FIELD(arg0, s32 *, 0x5CAC) = 0xF;
                M2C_FIELD(arg0, u8 *, 0x5DE5) = (u8) M2C_FIELD(arg0, u8 *, 0x5DE4);
                func_80072a5c(arg0);
            }
        }
        temp_v1 = M2C_FIELD(arg0, u8 *, 0x5DE7);
        switch (temp_v1) {                          /* switch 1 */
        case 0:                                     /* switch 1 */
            func_80075254(arg0);
            break;
        case 1:                                     /* switch 1 */
            temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x5E08) - 0x100;
            M2C_FIELD(arg0, s32 *, 0x5E08) = temp_v0_2;
            if (temp_v0_2 <= 0) {
                temp_v1_2 = M2C_FIELD(arg0, u8 *, 0x5DE9);
                switch (temp_v1_2) {
                case 3:
                case 5:
                    break;
                case 0:
                case 1:
                    func_80074b9c(arg0);
                    var_v0 = 0x9600;
                    goto block_13;
                case 4:
                    func_800d2164(arg0 + 0x4694, ((f32) M2C_FIELD(*(void **)D_800FC270, s32 *, 0xD10) / 30.0f) * 0.00390625f);
                    M2C_FIELD(arg0, s32 *, 0x5E08) = 0;
                    break;
                case 2:
                    func_80074cf4(arg0, 0x1E, 0, 0);
                    func_800d33a0(arg0 + 0x32DC, D_80075914, 1, -1);
                    var_v0 = 0x13B00;
block_13:
                    M2C_FIELD(arg0, s32 *, 0x5E08) = var_v0;
                    break;
                }
                if (M2C_FIELD(arg0, s32 *, 0x5E08) > 0) {
                    func_800a9be8(arg0 + 0x5CB0, 3);
                }
                goto block_96;
            }
            break;
        case 3:                                     /* switch 1 */
            func_800721ec(arg0);
            break;
        case 5:                                     /* switch 1 */
            temp_v0_3 = M2C_FIELD(arg0, s32 *, 0x5E08) - 0x100;
            M2C_FIELD(arg0, s32 *, 0x5E08) = temp_v0_3;
            if (temp_v0_3 <= 0) {
                temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x4690);
                if (temp_v1_3 != 0) {
                    *(s32 *)D_800759F0 = temp_v1_3;
                    func_800d33a0(arg0 + 0x32DC, D_80075824, 0, -1);
                    func_8001d640(D_800F1AE0, func_8001d4b8(D_800F1AE0, 0x54, 0, 1), scale_vol(M2C_FIELD((void *)D_800F1AE0, s32 *, 0x68), 0x7FFF));
                    M2C_FIELD(arg0, s32 *, 0x5E08) = 0x1E00;
                    M2C_FIELD(arg0, s32 *, 0x4690) = (s32) (M2C_FIELD(arg0, s32 *, 0x4690) - 1);
                } else {
                    *(volatile s32 *)&D_800F2728 = 0;
                    *(volatile s32 *)D_800F2724 = 1;
                    ((Obj5E00 *)arg0)->f5E00 = *(volatile s32 *)D_800F13F0;
                    if (D_800F2728 == 0) {
                        do {
                        } while (*(volatile s32 *)&D_800F2728 == 0);
                    }
                    func_8001d640(D_800F1AE0, func_8001d4b8(D_800F1AE0, 0x53, 0, 1), scale_vol(M2C_FIELD((void *)D_800F1AE0, s32 *, 0x68), 0x7FFF));
                    func_800ac25c(arg0, 0x66, 0xF, 0);
                    M2C_FIELD(arg0, s8 *, 0x5E3C) = 1;
                    func_800d33a0(arg0 + 0x32DC, D_8007584C, 0, -1);
                    if (M2C_FIELD(arg0, u8 *, 0x5DE9) != 2) {
                        M2C_FIELD(arg0, u8 *, 0x5DE7) = 0xFU;
                    } else {
                        M2C_FIELD(arg0, s32 *, 0x5E08) = 0x7800;
                        M2C_FIELD(arg0, u8 *, 0x5DE7) = 6U;
                    }
                }
            }
            break;
        case 6:                                     /* switch 1 */
            temp_v0_4 = M2C_FIELD(arg0, s32 *, 0x5E08) - 0x100;
            M2C_FIELD(arg0, s32 *, 0x5E08) = temp_v0_4;
            if (temp_v0_4 <= 0) {
                M2C_FIELD(arg0, s32 *, 0x5E1C) = 1;
                func_80074cf4(arg0, 0x19, 0, 0);
                func_800d33a0(arg0 + 0x32DC, D_8007593C, 1, -1);
                M2C_FIELD(arg0, s32 *, 0x5E08) = 0x16800;
                M2C_FIELD(arg0, u8 *, 0x5DE7) = 7U;
            }
            break;
        case 7:                                     /* switch 1 */
            temp_v0_5 = M2C_FIELD(arg0, s32 *, 0x5E08) - 0x100;
            M2C_FIELD(arg0, s32 *, 0x5E08) = temp_v0_5;
            if (temp_v0_5 <= 0) {
                M2C_FIELD(arg0, s32 *, 0x5E08) = 0xB400;
                var_v0_2 = 8;
                goto block_38;
            }
            break;
        case 8:                                     /* switch 1 */
            temp_v0_6 = M2C_FIELD(arg0, s32 *, 0x5E08) - 0x100;
            M2C_FIELD(arg0, s32 *, 0x5E08) = temp_v0_6;
            if (temp_v0_6 <= 0) {
                M2C_FIELD(arg0, s32 *, 0x5E1C) = 1;
                func_80074cf4(arg0, 0x1A, 0, 0);
                func_800d33a0(arg0 + 0x32DC, D_80075964, 1, -1);
                M2C_FIELD(arg0, s32 *, 0x5E08) = 0x1A400;
                M2C_FIELD(arg0, u8 *, 0x5DE7) = 9U;
            }
            break;
        case 9:                                     /* switch 1 */
            temp_v0_7 = M2C_FIELD(arg0, s32 *, 0x5E08) - 0x100;
            M2C_FIELD(arg0, s32 *, 0x5E08) = temp_v0_7;
            if (temp_v0_7 <= 0) {
                M2C_FIELD(arg0, s32 *, 0x5E08) = 0x3C00;
                var_v0_2 = 0xA;
                goto block_38;
            }
            break;
        case 10:                                    /* switch 1 */
            temp_v0_8 = M2C_FIELD(arg0, s32 *, 0x5E08) - 0x100;
            M2C_FIELD(arg0, s32 *, 0x5E08) = temp_v0_8;
            if (temp_v0_8 <= 0) {
                M2C_FIELD(arg0, s32 *, 0x5E1C) = 1;
                func_80074cf4(arg0, 0x1D, 0, 0);
                func_800d33a0(arg0 + 0x32DC, D_800759B4, 1, -1);
                M2C_FIELD(arg0, s32 *, 0x5E08) = 0x12C00;
                M2C_FIELD(arg0, u8 *, 0x5DE7) = 0xBU;
            }
            break;
        case 11:                                    /* switch 1 */
            temp_v0_9 = M2C_FIELD(arg0, s32 *, 0x5E08) - 0x100;
            M2C_FIELD(arg0, s32 *, 0x5E08) = temp_v0_9;
            if (temp_v0_9 <= 0) {
                M2C_FIELD(arg0, s32 *, 0x5E08) = 0x2400;
                var_v0_2 = 0xC;
block_38:
                M2C_FIELD(arg0, s32 *, 0x5E1C) = 0;
                M2C_FIELD(arg0, u8 *, 0x5DE7) = var_v0_2;
            }
            break;
        case 12:                                    /* switch 1 */
            temp_v0_10 = M2C_FIELD(arg0, s32 *, 0x5E08) - 0x100;
            M2C_FIELD(arg0, s32 *, 0x5E08) = temp_v0_10;
            if (temp_v0_10 <= 0) {
                M2C_FIELD(arg0, s8 *, 0x5E39) = 0x10;
                M2C_FIELD(arg0, s32 *, 0x5E08) = 0x1E00;
                M2C_FIELD(arg0, u8 *, 0x5DE7) = 0xDU;
            }
            break;
        case 13:                                    /* switch 1 */
            temp_v0_11 = M2C_FIELD(arg0, s32 *, 0x5E08) - 0x100;
            M2C_FIELD(arg0, s32 *, 0x5E08) = temp_v0_11;
            if (temp_v0_11 <= 0) {
                M2C_FIELD(arg0, s32 *, 0x5E1C) = 1;
                func_80074cf4(arg0, 0x1B, 0, 0);
                func_800d33a0(arg0 + 0x32DC, D_8007598C, 1, -1);
                M2C_FIELD(arg0, s32 *, 0x5E08) = 0xF000;
                M2C_FIELD(arg0, u8 *, 0x5DE7) = 0xEU;
            }
            break;
        case 14:                                    /* switch 1 */
            temp_v0_12 = M2C_FIELD(arg0, s32 *, 0x5E08) - 0x100;
            M2C_FIELD(arg0, s32 *, 0x5E08) = temp_v0_12;
            if (temp_v0_12 <= 0) {
                M2C_FIELD(arg0, s32 *, 0x5E1C) = 0;
                M2C_FIELD(arg0, s8 *, 0x5E39) = 0;
                M2C_FIELD(arg0, u8 *, 0x5DE7) = 0xFU;
            }
            break;
        case 15:                                    /* switch 1 */
            {
            s32 *p = (s32 *)D_800F2744;
            if (-*(s32 *)D_800F2778 + *p <= 0x464FFF) {
                temp_v0_13 = M2C_FIELD(arg0, s32 *, 0x5E50) - 0x100;
                M2C_FIELD(arg0, s32 *, 0x5E50) = temp_v0_13;
                if (temp_v0_13 <= 0) {
                    if (rand_n(100) >= 0x42U) {
                        var_a1 = 0xB2;
                    } else if (rand_n(100) >= 0x21U) {
                        var_a1 = 0xD7;
                    } else {
                        var_a1 = 0xDC;
                    }
                    func_80074d14(arg0, var_a1, 0, 0);
                    M2C_FIELD(arg0, s32 *, 0x5E50) = 0x1C200;
                }
            } else {
                M2C_FIELD(arg0, s32 *, 0x5E1C) = 1;
                func_800732ac(arg0, 0x44160000);
                func_800d2328(arg0 + 0x4694);
                func_800d29e0(arg0 + 0x32DC);
                func_80074800(arg0, 1);
                func_800a9be8(arg0 + 0x5CB0, 5);
                M2C_FIELD(arg0, s32 *, 0x5E08) = 0x7800;
                M2C_FIELD(arg0, u8 *, 0x5DE7) = 0x14U;
            }
            break;
            }
        case 17:                                    /* switch 1 */
            *(volatile s32 *)&D_800F2728 = 0;
            M2C_FIELD(arg0, s32 *, 0x5E04) = -0x1E00;
            M2C_FIELD(arg0, s8 *, 0x5E3C) = 2;
            if (M2C_FIELD(arg0, u8 *, 0x5DE9) != 2) {
                func_80074800(arg0, 1);
            }
            temp_v1_5 = M2C_FIELD(arg0, u8 *, 0x5DE9);
            switch (temp_v1_5) {                    /* switch 3 */
            case 0:                                 /* switch 3 */
            case 1:                                 /* switch 3 */
                func_80074400(arg0);
            case 2:                                 /* switch 3 */
            case 5:                                 /* switch 3 */
                break;
            case 3:
                sp20 = ((f32) M2C_FIELD(arg0, s32 *, 0x5E14) / 30.0f) * 0.00390625f;
                *(s32 *)D_800759F0 = *(s32 *)&sp20;
                func_800d33a0(arg0 + 0x32DC, D_800758C4, 1, -1);
                break;
            case 4:
                if (M2C_FIELD(*(void **)D_800FC270, s32 *, 0xD10) >= M2C_FIELD(arg0, s32 *, 0x5E14)) {
                    *(s32 *)D_800757E4 = 0x2A0;
                } else {
                    *(s32 *)D_800757E4 = 0x2A1;
                }
                *(s32 *)D_800759F0 = M2C_FIELD(arg0, s32 *, 0x5E14);
                func_800d33a0(arg0 + 0x32DC, D_800757D4, 0, -1);
                break;
            }
            if (M2C_FIELD(arg0, u8 *, 0x5DE9) != 2) {
                func_800a9be8(arg0 + 0x5CB0, 4);
            }
            func_800d2328(arg0 + 0x4694);
            M2C_FIELD(arg0, s32 *, 0x5E08) = 0x3C00;
            M2C_FIELD(arg0, u8 *, 0x5DE7) = 0x12U;
            break;
        case 18:                                    /* switch 1 */
            temp_v0_14 = M2C_FIELD(arg0, s32 *, 0x5E08) - 0x100;
            M2C_FIELD(arg0, s32 *, 0x5E08) = temp_v0_14;
            if (temp_v0_14 <= 0) {
                if ((u8) M2C_FIELD(arg0, u8 *, 0x5DE9) < 2U) {
                    M2C_FIELD(arg0, s32 *, 0x5E08) = 0x12C00;
                } else {
                    M2C_FIELD(arg0, s32 *, 0x5E08) = 0xB400;
                }
                M2C_FIELD(arg0, u8 *, 0x5DE7) = 0x13U;
            }
            break;
        case 19:                                    /* switch 1 */
            temp_v0_15 = M2C_FIELD(arg0, s32 *, 0x5E08) - 0x100;
            M2C_FIELD(arg0, s32 *, 0x5E08) = temp_v0_15;
            if (temp_v0_15 <= 0) {
                if (M2C_FIELD(arg0, u8 *, 0x5DE9) == 2) {
                    goto block_88;
                }
                func_800d29e0(arg0 + 0x32DC);
                temp_v1_6 = M2C_FIELD(arg0, u8 *, 0x5DE9);
                if (temp_v1_6 < 2U) {
                    M2C_FIELD(arg0, u8 *, 0x5DE7) = 2U;
                    break;
                }
                if (temp_v1_6 == 5) {
                    M2C_FIELD(arg0, u8 *, 0x5DE7) = 2U;
                    break;
                }
                if (temp_v1_6 == 4) {
                    if (M2C_FIELD(*(void **)D_800FC270, s32 *, 0xD10) >= M2C_FIELD(arg0, s32 *, 0x5E14)) {
                        func_80072a5c(arg0);
                        break;
                    }
                }
                if ((M2C_FIELD(arg0, u8 *, 0x5DE9) == 3U) && (M2C_FIELD(arg0, s32 *, 0x5E0C) != -0x1E00)) {
                    func_80073b80(arg0);
                }
                var_v1_2 = M2C_FIELD(arg0, s32 *, 0x5E00);
                if (var_v1_2 == 0) {
                    var_v1_2 = 1;
                }
                *(s32 *)D_800F13F0 = var_v1_2;
                M2C_FIELD(arg0, s32 *, 0x5E08) = 0;
                M2C_FIELD(arg0, u8 *, 0x5DE7) = 3U;
                break;
block_88:
                func_80072a5c(arg0);
            }
            break;
        case 2:                                     /* switch 1 */
            func_800d2328(arg0 + 0x4694);
            M2C_FIELD(arg0, s32 *, 0x5E08) = 0;
            if (M2C_FIELD(arg0, s32 *, 0x5E2C) == 0) {
                temp_v0_16 = M2C_FIELD(arg0, u8 *, 0x5DE9);
                if (temp_v0_16 != 5) {
                    M2C_FIELD(arg0, u8 *, 0x5DEA) = temp_v0_16;
                    M2C_FIELD(arg0, u8 *, 0x5DE9) = 5U;
                    func_800a3394(D_800F1AE0, 0x2666, -1, -1);
                    func_800a31bc(D_800F1AE0);
                    {
                        s32 *tm = (s32 *)D_800445F0;
                        if (tm[2] == 0) {
                            tm[1] = tm[0];
                            func_80008540(tm);
                            tm[2] = 1;
                        }
                    }
                }
                func_80074d14(arg0, 0x66, 0, 0);
                {
                    char *pl = D_800F4D00;
                    temp_s1 = arg0 + 0x5BA0;
                    temp_v0_17 = M2C_FIELD(temp_s1, void **, 0xB4);
                    M2C_FIELD(temp_v0_17, M2C_UNK (**)(void *, M2C_UNK), 0x14)(temp_s1 + M2C_FIELD(temp_v0_17, s16 *, 0x10), pl);
                    func_800adc54(temp_s1, 1 << M2C_FIELD((void *)pl, s32 *, 0xD8));
                }
                M2C_FIELD(temp_s1, s8 *, 0xB0) = 1;
                func_800adc38(temp_s1);
                func_800ac25c(arg0, 0x66, 0x12, 0);
                var_v1_3 = M2C_FIELD(arg0, s32 *, 0x5E00);
                if (var_v1_3 == 0) {
                    var_v1_3 = 1;
                }
                *(s32 *)D_800F13F0 = var_v1_3;
block_96:
                M2C_FIELD(arg0, u8 *, 0x5DE7) = 3U;
                break;
            }
        case 20:                                    /* switch 1 */
            temp_v0_18 = M2C_FIELD(arg0, s32 *, 0x5E08) - 0x100;
            M2C_FIELD(arg0, s32 *, 0x5E08) = temp_v0_18;
            if (temp_v0_18 <= 0) {
                M2C_FIELD(arg0, s32 *, 0x5E1C) = 1;
                func_800d29e0(arg0 + 0x32DC);
                if ((s32) M2C_FIELD(arg0, u8 *, 0x5DE6) >= (M2C_FIELD(*(void **)D_800FC270, u8 *, 0xA0C) - 1)) {
                    var_s0 = 0;
                    if ((s32) M2C_FIELD(arg0, u8 *, 0x5DE5) < (M2C_FIELD(arg0, u8 *, 0x5DE4) - 1)) {
                        M2C_FIELD(arg0, s32 *, 0x5E08) = 0x1C200;
                    } else {
                        var_s0 = 1;
                        M2C_FIELD(arg0, s32 *, 0x5E08) = 0x38400;
                        func_80073438(arg0);
                    }
                    func_80074510(arg0, var_s0);
                    func_8009b0e4(0xEC, M2C_FIELD(arg0, u8 *, 0x5DE6), arg0 + 0x868, 2, var_s0, 0, 0);
                    if (M2C_FIELD(arg0, u8 *, 0x5DE9) == 1) {
                        func_800bc180(D_800F2AD8);
                    } else {
                        func_800bc104(D_800F2AD8);
                    }
                    func_800bbd78(D_800F2AD8, 0xD, 0, 0, 8);
                    func_800bbd78(D_800F2AD8, 0xD, 1, arg0, 2);
                    func_800bbd78(D_800F2AD8, 0xC, 1, arg0, 2);
                    func_800a9be8(arg0 + 0x5CB0, 5);
                    M2C_FIELD(arg0, u8 *, 0x5DE7) = 0x15U;
                } else {
                    goto block_110;
                }
            }
            break;
        case 23:
            break;
        case 22:                                    /* switch 1 */
            M2C_FIELD(arg0, u8 *, 0x5DE7) = 0x15U;
            /* fallthrough */
        case 21:                                    /* switch 1 */
            temp_v0_19 = M2C_FIELD(arg0, s32 *, 0x5E08) - 0x100;
            M2C_FIELD(arg0, s32 *, 0x5E08) = temp_v0_19;
            if (temp_v0_19 <= 0) {
                func_800d771c(arg0 + 0x868);
block_110:
                func_80072e24(arg0);
            }
            break;
        }
        func_80074970(arg0);
    }
}
