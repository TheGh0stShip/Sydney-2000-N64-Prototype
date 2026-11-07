typedef struct { char pad[0x118F]; unsigned char busy; } Snd;
typedef struct {
    char pad0[0xB8]; int wB8;
} Dummy;
#define B(o,x) (*(unsigned char *)((char *)(o) + (x)))
#define W(o,x) (*(int *)((char *)(o) + (x)))
#define F(o,x) (*(float *)((char *)(o) + (x)))

extern volatile int D_800F2728, D_800F2724;
extern int D_800F2778, D_800F2780, D_800F2714, D_800F2744;
extern int *D_800FC270;
extern char D_800F1AE0[], D_800F26E0[];
extern char D_800774BC[], D_80077584[], D_800775AC[], D_800775D4[];
extern int D_8007735C;
extern unsigned char D_80077610;
extern void func_80073CF0(void *), func_80071CC4(void *), func_80071DE0(void *), func_80071F00(void *);
extern void func_80071FEC(void *), func_800721B0(void *), func_800722AC(void *), func_8007243C(void *);
extern void func_80072668(void *), func_800727D0(void *), func_80072984(void *), func_80072B14(void *);
extern void func_800755FC(void *), func_80075748(void *), func_80075880(void *), func_800760AC(void *);
extern void func_80076674(void *), func_80076E14(void *), func_80076564(void *, int, int, int);
extern void func_800A9BE8(void *, int), func_80099D70(void *, int, float), func_8009B9EC(int, int);
extern int func_8001D4B8(void *, int, int, int);
extern void func_8001D640(void *, int, int);
extern void func_800D33A0(void *, void *, int, int), func_8009A64C(void *), func_800AC25C(void *, int, int, int);
extern int func_80017D54(void);
extern void func_800AB2A4(void *, int, int, int, int, int);
extern void func_800BF394(void *), func_800BEFB4(void *, int, int), func_800BF36C(void *, void *, int);
extern void func_800A9AE4(void *, void *), func_80099FE4(void *), func_8009A190(void *);
extern void func_800D771C(void *);

void func_800D78BC(char *s, int run)
{
    unsigned int k;
    char *snd;
    char *q;

    if (run == 0) {
        goto out;
    }
    if (W(s, 0x6184) == 1) {
        if ((D_800F2780 -= 256) <= 0) {
            W(s, 0x6154) = 15;
            func_80073CF0(s);
        }
    }
    switch (B(s, 0x60F)) {
    case 0:
    default:
        goto c0;
    case 1: goto c1;
    case 2: goto c2;
    case 3: goto c3;
    case 4: goto c4;
    case 5: goto c5;
    case 6: goto c6;
    case 8: goto c8;
    case 9: goto c9;
    case 11: goto c11;
    case 12: goto c12;
    case 13: goto c13;
    case 14: goto c14;
    case 15: goto c15;
    case 16: goto c16;
    case 24: goto c24;
    case 25: goto c25;
    case 26: goto c26;
    case 28: goto c28;
    case 29: goto c29;
    case 30: goto c30;
    case 31: goto c31;
    case 32: goto c32;
    case 33: goto c33;
    case 34: goto c34;
    case 35: goto c35;
    case 36: goto c36;
    case 37: goto c37;
    case 38: goto c38;
    case 39: goto c39;
    }
c1: func_80071CC4(s); goto tail;
c2:
    if ((W(s, 0x6164) -= 256) > 0) goto n5;
    switch (B(s, 0x615)) {
    case 0: case 1: goto n0;
    case 2: case 3: goto n2;
    case 4: goto n4;
    case 5: default: goto n5;
    }
n0:
    func_800755FC(s);
    func_800A9BE8(s + 0x45C, 2);
    W(s, 0x6164) = 0;
    B(s, 0x60F) = 3;
    goto n5;
n4:
    func_80099D70(s + 0x4EFC, 0, (float)W(D_800FC270, 0xD10) / 30.0f * 0.00390625f);
n2:
    func_800A9BE8(s + 0x45C, 5);
    B(s, 0x60F) = 7;
n5:
    func_8009B9EC(11520, 0);
    goto tail;
c3: func_80071DE0(s); goto tail;
c4: func_80071F00(s); goto tail;
c5:
    if ((W(s, 0x6164) -= 256) <= 0) {
        k = func_8001D4B8(D_800F1AE0, 271, 0, 1);
        func_8001D640(D_800F1AE0, k, (int)((long long)W(D_800F1AE0, 104) * 32767) >> 15);
        func_800D33A0(s + 0x3254, D_800774BC, 0, -1);
        W(s, 0x6164) = 11520;
        B(s, 0x60F) = 6;
    }
    func_8009B9EC(23040, 0);
    goto tail;
c6:
    if ((W(s, 0x6164) -= 256) > 0) goto c0;
    D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
    if ((unsigned int)D_800F2714 >> 29) {
        func_80076564(s, 191, 0, 0);
    } else {
        func_80076564(s, 276, 0, 0);
    }
    B(s, 0x60F) = 7;
    goto c0;
c8: func_80071FEC(s); goto tail;
c9: func_800721B0(s); goto tail;
c11:
    if (B(s, 0x610) != 0) goto tail;
    if (B(s, 0x615) == 2) {
        W(s, 0xB8) = 1;
        { char *p = s + 0x5900; p[0x787] ^= 12; }
        func_800D33A0(s + 0x3254, D_80077584, 1, -1);
        func_80076564(s, 44, 0, 0);
        W(s, 0x6164) = 0x10E00;
        B(s, 0x60F) = 35;
    } else {
        B(s, 0x60F) = 12;
    }
    goto c0;
c12:
    D_800F2728 = 0;
    D_800F2724 = 1;
    while (D_800F2728 == 0) {
    }
    B(s, 0x60F) = 13;
c13:
    { int t; int *p = &D_800F2744; t = D_800F2778; if (*p != t) goto tail; }
    func_8009A64C(s + 0x4EFC);
    B(s, 0x61B0) = 0;
    func_800AC25C(s, 91, 12, 0);
    W(s, 0x6158) = D_800F2778;
    W(s, 0x6164) = W(s, 0x6160);
    B(s, 0x60F) = 14;
    goto c0;
c14: func_800722AC(s); goto tail;
c34:
    if ((W(s, 0x6164) -= 256) > 0) goto c0;
    if (func_80017D54()) {
        func_800AB2A4(D_800F26E0, D_800F2744, 12, D_8007735C, 0, 0);
    }
    if (B(s, 0x615) == 0) {
        func_80076674(s);
    }
    func_800BF394(s + 600);
    func_800BEFB4(s + 600, 16, W(s, 0x614C));
    func_800BF36C(s + 600, s + 0x43C, B(s, 0x60D));
    func_800A9AE4(s + 0x45C, s + 600);
    B(s, 0x60F) = 17;
    goto c0;
c15:
    if ((W(s, 0x6164) -= 256) > 0) goto c0;
    func_80075748(s);
    B(s, 0x60F) = 16;
    goto c0;
c16:
    if (!((B(s, 0x61B0) >> B(s, 0x60C)) & 1)) goto tail;
    func_80075880(s);
    B(s, 0x60F) = 17;
    goto c0;
c25: func_8007243C(s); goto tail;
c24:
    if (B(s, 0x610) != D_80077610) goto tail;
    D_800F2728 = 0;
    W(s, 0x6158) = -7680;
    B(s, 0x61B3) = 2;
    if (B(s, 0x615) == 0) {
        func_800A9BE8(s + 0x45C, 10);
    } else {
        func_800A9BE8(s + 0x45C, 15);
    }
    q = s + 0x550;
    q[0xB9] = 0;
    q[0xB8] = 1;
    q[0xBA] = 0;
    q[0xBB] = 0;
    func_80099FE4(s + 0x4EFC);
    W(s, 0x6164) = 15360;
    B(s, 0x60F) = 26;
    goto c0;
c35:
    if ((W(s, 0x6164) -= 256) > 0) goto c0;
    W(s, 0xB8) = 0;
    { char *p = s + 0x5900; p[0x787] ^= 12; }
    B(s, 0x60F) = 12;
    goto c0;
c36:
    if ((W(s, 0x6164) -= 256) > 0) goto c0;
    W(s, 0xB8) = 1;
    { char *p = s + 0x5900; p[0x787] ^= 12; }
    func_800D33A0(s + 0x3254, D_800775AC, 1, -1);
    func_80076564(s, 43, 0, 0);
    func_800A9BE8(s + 0x45C, 20);
    W(s, 0x6164) = 0x12C00;
    B(s, 0x60F) = 37;
    goto c0;
c37:
    if ((W(s, 0x6164) -= 256) > 0) goto c0;
    W(s, 0xB8) = 0;
    { char *p = s + 0x5900; p[0x787] ^= 12; }
    func_800A9BE8(s + 0x45C, 17);
    W(s, 0x6164) = 0xAB00;
    B(s, 0x60F) = 38;
    goto c0;
c38:
    if ((W(s, 0x6164) -= 256) > 0) goto c0;
    W(s, 0xB8) = 1;
    { char *p = s + 0x5900; p[0x787] ^= 12; }
    func_800D33A0(s + 0x3254, D_800775D4, 1, -1);
    func_80076564(s, 41, 0, 0);
    func_800A9BE8(s + 0x45C, 21);
    W(s, 0x6164) = 0x12C00;
    B(s, 0x60F) = 39;
    goto c0;
c39:
    if ((W(s, 0x6164) -= 256) > 0) goto c0;
    W(s, 0xB8) = 0;
    { char *p = s + 0x5900; p[0x787] ^= 12; }
    B(s, 0x60F) = 17;
    goto c0;
c26:
    if ((W(s, 0x6164) -= 256) > 0) goto c0;
    if (B(s, 0x615) < 2) {
        W(s, 0x6164) = 0x12C00;
    } else {
        W(s, 0x6164) = 0x9600;
    }
    B(s, 0x60F) = 28;
    goto c0;
c28: func_80072668(s); goto tail;
c29:
    if ((W(s, 0x6164) -= 256) > 0) goto c0;
    func_800D771C(s + 0x7E0);
    func_80076E14(s);
    goto tail;
c30:
    if ((W(s, 0x6164) -= 256) > 0) goto c0;
    func_800D771C(s + 0x7E0);
    func_800760AC(s);
    B(s, 0x60F) = 31;
    goto c0;
c31: func_800727D0(s); goto tail;
c32: func_80072984(s); goto tail;
c33: func_80072B14(s);
c0:
tail:
    snd = s + 0x4EFC;
    if (B(snd, 0x118F)) {
        func_8009A190(snd);
    }
out:
    ;
}
