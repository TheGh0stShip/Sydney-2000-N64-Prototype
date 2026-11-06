typedef unsigned char u8;
typedef struct { int pad[0x344]; int w0d10; } Glob;

extern void func_800D29E0(void *);
extern void func_80075F70(void *);
extern void func_8009AC98(int, int, void *, int);
extern void func_800A9BE8(void *, int);
extern void func_80073AF0(void *);
extern void func_8009BD48(int);
extern void func_80074D28(void *);
extern void func_800AC25C(void *, int, int, int);
extern Glob *D_800FC270;
extern int D_800F13F0;
extern u8 D_80077730;

#define W(o) (*(int *)(p + (o)))
#define BY(o) (*(u8 *)(p + (o)))

void func_800837DC(u8 *p)
{
    u8 v;
    int t;

    W(0x5424) -= 0x100;
    if (W(0x5424) > 0) {
        return;
    }
    v = BY(0x615);
    if (v == 0) {
        func_800D29E0(p + 0x3254);
        func_80075F70(p);
        func_8009AC98(0xE8, BY(0x60E), p + 0x7E0, 2);
        func_800A9BE8(p + 0x45C, 9);
        W(0x5424) = 0x1C200;
        BY(0x60F) = 0x21;
        return;
    }
    if (v == 5 || v == 1) {
        BY(0x60F) = 0x22;
        return;
    }
    if (v == 4 && D_800FC270->w0d10 >= W(0x542C)) {
        func_80073AF0(p);
        return;
    }
    if (BY(0x615) == 2) {
        func_800D29E0(p + 0x3254);
        W(0x5430) = -7680;
        BY(0x615) = 3;
        func_8009BD48(3);
    } else {
        t = W(0x65C);
        if (t == 0) {
            t = 1;
        }
        D_800F13F0 = t;
        if (BY(0x615) == 3) {
            func_80074D28(p);
        }
    }
    func_800AC25C(p, 0x62, 0x11, 0);
    func_800A9BE8(p + 0x45C, 5);
    v = D_80077730;
    BY(0x60F) = 8;
    BY(0x610) = v;
}
