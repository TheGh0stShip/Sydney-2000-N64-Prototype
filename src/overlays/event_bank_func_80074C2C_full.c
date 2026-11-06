typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef float f32;

#define W(o) (*(s32 *)((u8 *)p + (o)))
#define B(o) (*(u8 *)((u8 *)p + (o)))
#define SB(o) (*(s8 *)((u8 *)p + (o)))
#define F(o) (*(f32 *)((u8 *)p + (o)))
#define PTR(o) ((void *)((u8 *)p + (o)))

typedef struct VT {
    u8 pad[16];
    s16 delta;
    s16 pad2;
    void (*fn)(void *, void *);
} VT;

typedef struct Timer {
    s32 a;
    s32 b;
    s32 c;
} Timer;

extern s32 D_800F2780;
extern s32 D_800F2728;
extern s32 D_800F2724;
extern s32 D_800F13F0;
extern s32 D_800F2744;
extern u8 D_800F26E0[];
extern u8 *D_800FC270;
extern u8 D_80076550[], D_80076578[], D_800765A0[], D_800765C8[], D_800765F0[], D_80076618[];
extern Timer D_800445F0;
extern u8 D_800F1AE0[];
extern u8 D_800F4D00[];

extern void func_80072EE4(void *);
extern void func_80074034(void *);
extern void func_8009B80C(void *, s32, s32, s32);
extern void func_800D33A0(void *, void *, s32, s32);
extern void func_80075F94(void *, s32, s32, s32);
extern void func_80083440(void *);
extern void func_800833FC(void *);
extern void func_80083298(void *, s32);
extern void func_800834B0(void *);
extern void func_80074118(void *, s32);
extern void func_800833B8(void *);
extern void func_800D29E0(void *);
extern void func_80083484(void *);
extern void func_800AC25C(void *, s32, s32, s32);
extern void func_800ADC1C(void *);
extern void func_80075F4C(void *);
extern void func_8008382C(void *);
extern void func_8009AC98(s32, s32, void *, s32);
extern void func_80074690(void *);
extern void func_80082FAC(void *);
extern void func_80075F20(void *);
extern void func_8009BD48(s32);
extern void func_800AB2A4(void *, s32, s32, void *, s32, s32);
extern void func_80073A44(void *);
extern void func_800D771C(void *);
extern void func_80008540(void *);
extern void func_800A3394(void *, s32, s32, s32);
extern void func_800A31BC(void *);
extern void func_800ADC54(void *, s32);
extern void func_800ADC38(void *);

extern void *D_80070A68[];
extern void *D_80070AE8[];
extern void *D_80070B00[];
extern void *D_80070B18[];

#define LCG() (D_800F13F0 = (D_800F13F0 * 16807) & 0x7FFFFFFF)

void func_80074C2C(u8 *p, s32 arg1)
{
    s32 v;
    u8 *q;
    u8 *r;
    u8 old;

    if (arg1 == 0) {
        return;
    }
    if (W(0x10D48) != 0) {
        if ((D_800F2780 -= 256) <= 0) {
            W(0xD950) = 15;
            func_80072EE4(p);
        }
    }
    { static void *const unused_tbl1[] = { &&L1_1, &&L1_10, &&L1_14, &&L1_15, &&L1_16, &&L1_17, &&L1_18, &&L1_19, &&L1_2, &&L1_20, &&L1_21, &&L1_22, &&L1_25, &&L1_26, &&L1_27, &&L1_28, &&L1_3, &&L1_30, &&L1_8, &&L1_9, &&E1 };
      unsigned int idx1 = W(0x610); if (idx1 >= 31) goto E1; goto *D_80070A68[idx1]; }
L1_1:
    { static void *const unused_tbl2[] = { &&L2_0, &&L2_1, &&L2_2, &&L2_5, &&E2 };
      unsigned int idx2 = B(0x614); if (idx2 >= 6) goto E2; goto *D_80070AE8[idx2]; }
L2_0:
            W(0x610) = 2;
            W(0x4C0) = 0xB400;
            if (B(0x10B05) == 0) {
                func_80074034(p);
                func_8009B80C(PTR(0x103C8), 10, SB(0x10B04), 4);
            }
            goto E2;
L2_5:
            W(0x610) = 30;
            goto E2;
L2_2:
            func_800D33A0(PTR(0x103C8), D_80076550, 1, -1);
            func_80075F94(p, 34, 0, 0);
            W(0x10B10) = 0;
            W(0x4C0) = 0x12C00;
L2_1:
            W(0x610) = 2;
            goto E2;
E2: ;
        if (*(s32 *)(D_800FC270 + 0xA00) == 4 && B(0x614) != 5) {
            if (B(0x10B05) == 0) {
                func_80083440(PTR(0x630));
                if (B(0x10B19) >= 2) {
                    func_80083440(PTR(0x6FC0));
                }
            } else {
                func_800833FC(PTR(0x630));
                if (B(0x10B19) >= 2) {
                    func_800833FC(PTR(0x6FC0));
                }
            }
        } else if (B(0x614) == 2) {
            func_80083298(PTR(0x630), 15);
        } else {
            func_800834B0(PTR(0x630));
            if (B(0x10B19) >= 2) {
                func_800834B0(PTR(0x6FC0));
            }
        }
        goto E1;
L1_2:
        if ((W(0x4C0) -= 256) > 0) {
            goto E1;
        }
    { static void *const unused_tbl3[] = { &&L3_0, &&L3_1, &&L3_2, &&E3 };
      unsigned int idx3 = B(0x614); if (idx3 >= 6) goto E3; goto *D_80070B00[idx3]; }
L3_0:
            func_80074118(p, 0);
            if (B(0x10B19) >= 2) {
                func_80074118(p, 1);
            }
L3_1:
            W(0x4C0) = 0;
            W(0x610) = 3;
            goto E3;
L3_2:
            W(0x610) = 3;
            goto E3;
E3: ;
        func_800833B8(PTR(0x630));
        if (B(0x10B19) >= 2) {
            func_800833B8(PTR(0x6FC0));
        }
        W(0x4C0) = 0x9600;
        func_800D29E0(PTR(0x103C8));
        W(0x10B10) = 0;
        goto E1;
L1_3:
        if ((W(0x4C0) -= 256) > 0) {
            goto E1;
        }
        W(0x610) = 5;
        W(0x618) = D_800F13F0;
        func_80083484(PTR(0x630));
        if (B(0x10B19) >= 2) {
            func_80083484(PTR(0x6FC0));
        }
        goto E1;
L1_8:
        if ((W(0x4C0) -= 256) > 0) {
            goto E1;
        }
        W(0x610) = 5;
        func_800AC25C(p, 56, 12, 0);
        goto E1;
L1_14:
        if ((W(0x4C0) -= 256) > 0) {
            goto E1;
        }
        W(0x10B10) = 0;
        func_800D29E0(PTR(0x103C8));
        W(0x10B10) = 0;
        W(0x610) = 10;
        goto E1;
L1_9:
        {
        u8 *b9;
        u8 *a9;
        b9 = PTR(0x630);
        if (W(0x58C8) != 0) {
            goto E1;
        }
        if (B(0x614) == 2) {
        a9 = PTR(0x58DC);
        func_800ADC1C(a9);
        func_800D29E0(a9);
        func_800D33A0(PTR(0x103C8), D_80076578, 1, -1);
        func_80075F94(p, 37, 0, 0);
        W(0x10B10) = 1;
        W(0x4C0) = 0xB400;
        W(0x610) = 14;
        func_80083298(b9, 16);
        } else {
            W(0x610) = 10;
        }
        }
        goto E1;
L1_10:
        func_800AC25C(p, 56, 15, 0);
        if (D_800F2728 == 0) {
            D_800F2724 = 1;
        }
        if (B(0x614) == 2) {
            W(0x4C0) = 0x6900;
            W(0x610) = 15;
        } else {
            W(0x610) = 12;
        }
        W(0x10B1C) = 1;
        func_80075F4C(p);
        goto E1;
L1_15:
        if ((W(0x4C0) -= 256) > 0) {
            goto E1;
        }
        {
        u8 *a15 = PTR(0x58DC);
        u8 *b15;
        b15 = PTR(0x630);
        func_800ADC1C(a15);
        func_800D29E0(a15);
        func_800D33A0(PTR(0x103C8), D_800765A0, 1, -1);
        func_80083298(b15, 17);
        }
        func_80075F94(p, 33, 0, 0);
        W(0x10B10) = 1;
        W(0x4C0) = 0x10E00;
        W(0x610) = 16;
        goto E1;
L1_16:
        if ((W(0x4C0) -= 256) > 0) {
            goto E1;
        }
        W(0x10B10) = 0;
        func_800D29E0(PTR(0x103C8));
        func_80083298(PTR(0x630), 21);
        W(0x10B10) = 0;
        W(0x4C0) = 0xF600;
        W(0x610) = 17;
        goto E1;
L1_17:
        if ((W(0x4C0) -= 256) > 0) {
            goto E1;
        }
        W(0x10B10) = 1;
        func_800D33A0(PTR(0x103C8), D_800765C8, 1, -1);
        func_80083298(PTR(0x630), 18);
        func_80075F94(p, 35, 0, 0);
        W(0x10B10) = 1;
        W(0x4C0) = 0x12C00;
        W(0x610) = 18;
        goto E1;
L1_18:
        if ((W(0x4C0) -= 256) > 0) {
            goto E1;
        }
        W(0x10B10) = 0;
        func_800D29E0(PTR(0x103C8));
        func_80083298(PTR(0x630), 21);
        W(0x4C0) = 0x1DA00;
        W(0x610) = 19;
        goto E1;
L1_19:
        if ((W(0x4C0) -= 256) > 0) {
            goto E1;
        }
        W(0x10B10) = 1;
        func_800D33A0(PTR(0x103C8), D_800765F0, 1, -1);
        func_80083298(PTR(0x630), 19);
        func_80075F94(p, 36, 0, 0);
        W(0x10B10) = 1;
        W(0x4C0) = 0x9600;
        W(0x610) = 20;
        goto E1;
L1_20:
        if ((W(0x4C0) -= 256) > 0) {
            goto E1;
        }
        W(0x10B10) = 0;
        func_800D29E0(PTR(0x103C8));
        func_80083298(PTR(0x630), 21);
        W(0x4C0) = 0xC300;
        W(0x610) = 21;
        goto E1;
L1_21:
        if ((W(0x4C0) -= 256) > 0) {
            goto E1;
        }
        W(0x10B10) = 1;
        func_800D33A0(PTR(0x103C8), D_80076618, 1, -1);
        func_80083298(PTR(0x630), 20);
        func_80075F94(p, 38, 0, 0);
        W(0x10B10) = 1;
        W(0x4C0) = 0xD200;
        W(0x610) = 22;
        goto E1;
L1_22:
        if ((W(0x4C0) -= 256) > 0) {
            goto E1;
        }
        W(0x10B10) = 0;
        func_800D29E0(PTR(0x103C8));
        func_80083298(PTR(0x630), 21);
        W(0x4C0) = 0x9600;
        W(0x610) = 12;
        goto E1;
L1_25:
        if ((W(0x4C0) -= 256) > 0) {
            goto E1;
        }
        switch (B(0x614)) {
        case 0:
        case 1:
            W(0x4C0) = 0x12C00;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            W(0x4C0) = 0x9600;
            break;
        }
        W(0x610) = 26;
        goto E1;
L1_26:
        if ((W(0x4C0) -= 256) > 0) {
            goto E1;
        }
        {
            unsigned int rr = D_800F13F0 * 16807;
            rr &= 0x7FFFFFFF;
            D_800F13F0 = rr;
            rr >>= 30;
            B(0x10D39) = rr;
        }
        B(0x10D3A) = 0;
        {
        u8 *q1 = PTR(0x630);
        u8 *q2;
        if (*(s32 *)(q1 + 0x2E0) != 0) {
            func_8008382C(q1);
        }
        q2 = PTR(0x6FC0);
        v = *(s32 *)(q2 + 0x2E0) != 0 && q2[0x1AA] != 4;
        if (v) {
            func_8008382C(q2);
        }
        }
    { static void *const unused_tbl4[] = { &&L4_0, &&L4_1, &&L4_2, &&L4_3, &&L4_4, &&E4 };
      unsigned int idx4 = B(0x614); if (idx4 >= 6) goto E4; goto *D_80070B18[idx4]; }
L4_0:
            func_8009AC98(235, B(0x10B04), PTR(0xD954), 4);
            W(0x4C0) = 0x1C200;
            W(0x610) = 27;
            func_80074690(p);
            goto E4;
L4_1:
            W(0x610) = 30;
            goto E4;
L4_2:
            func_800D29E0(PTR(0x103C8));
            func_800AC25C(p, 56, 17, 0);
            F(0x10B0C) = *(f32 *)0x80070B30;
            B(0x614) = 3;
            W(0x4C0) = 0x9600;
            W(0x610) = 8;
            func_80082FAC(PTR(0x630));
            W(0x10B1C) = 0;
            func_80075F20(p);
            func_8009BD48(B(0x614));
            goto E4;
L4_4:
            if (W(0x10D3C) < *(s32 *)(D_800FC270 + 0xD10)) {
                W(0xD950) = 15;
                func_800AB2A4(D_800F26E0, D_800F2744, 7, p, 0, 7);
            } else {
                func_800D29E0(PTR(0x103C8));
                func_800AC25C(p, 56, 17, 0);
                W(0x4C0) = 0x9600;
                W(0x610) = 8;
                func_80082FAC(PTR(0x630));
                W(0x10B1C) = 0;
                func_80075F20(p);
            }
            goto E4;
L4_3:
            if (W(0x10D44) == 0) {
                func_80073A44(p);
            }
            B(0x4BD) = 0;
            F(0x10B0C) = (f32)W(0x10D3C) / *(f32 *)0x80070B34 * *(f32 *)0x80070B38;
            D_800F13F0 = W(0x618) ? W(0x618) : 1;
            W(0x610) = 5;
            W(0x10B1C) = 0;
            func_80082FAC(PTR(0x630));
            func_80082FAC(PTR(0x6FC0));
            func_80075F20(p);
            LCG();
            B(0x10D39) = (unsigned)D_800F13F0 >> 30;
            B(0x10D3A) = 0;
            func_800AC25C(p, 56, 17, 0);
            goto E4;
E4: ;
        goto E1;
L1_27:
        if ((W(0x4C0) -= 256) > 0) {
            goto E1;
        }
        func_800D771C(PTR(0xD954));
        W(0x610) = 30;
        goto E1;
L1_28:
        if ((W(0x4C0) -= 256) > 0) {
            goto E1;
        }
        func_800D771C(PTR(0xD954));
        func_80072EE4(p);
        goto E1;
L1_30:
        if (B(0x614) != 5) {
            old = B(0x614);
            B(0x614) = 5;
            B(0x615) = old;
            if (D_800445F0.c == 0) {
                D_800445F0.b = D_800445F0.a;
                func_80008540(&D_800445F0);
                D_800445F0.c = 1;
            }
            func_800A3394(D_800F1AE0, 9830, -1, -1);
            func_800A31BC(D_800F1AE0);
            func_80075F94(p, 147, 0, 0);
            {
                u8 *g = D_800F4D00;
                VT *vt;
                r = PTR(0x10A2C);
                vt = *(VT **)(r + 180);
                vt->fn(r + vt->delta, g);
                func_800ADC54(r, 1 << *(s32 *)(g + 216));
            }
            r[176] = 1;
            func_800ADC38(r);
        }
        func_80075F20(p);
        B(0x10B18) = 0;
        B(0x4BD) = 0;
        B(0x10D24) = 0;
        B(0x10D25) = 0;
        func_800AC25C(p, 56, 18, 0);
        D_800F13F0 = W(0x618) ? W(0x618) : 1;
        W(0x4C0) = 0;
        W(0x610) = 5;
        goto E1;
E1: ;
}
