typedef unsigned char u8;
typedef signed short s16;
typedef int s32;

typedef struct VtEnt {
    s16 off;
    s16 pad;
    void (*fn)(void *);
} VtEnt;

typedef struct Vt {
    VtEnt e[4];
} Vt;

extern u8 D_800F3BC0[];
extern void func_800D29E0(void *);
extern void func_800C013C(void *);
extern void func_800D2328(void *);
extern void func_80074800(void *, s32);
extern void func_800A9BE8(void *, s32);
extern void func_800ADC1C(void *);
extern void func_80072A5C(void *);

#define B(o) (*(u8 *)(p + (o)))
#define W(o) (*(s32 *)(p + (o)))

void func_80073D10(u8 *p)
{
    u8 *o;
    VtEnt *e;

    switch (B(0x5DE9)) {
    case 0:
    case 3:
    case 4:
        switch (B(0x5DE7)) {
        case 1:
        case 3:
            func_800D29E0(p + 0x32DC);
            func_800C013C(D_800F3BC0);
            W(0x5E08) = 0;
            B(0x5DE7) = 3;
            break;
        case 0:
        case 23:
            break;
        case 19:
        case 20:
        case 21:
            W(0x5E08) = 0;
            break;
        case 5:
        case 15:
        case 16:
            if (B(0x5DE9) != 3 && B(0x5E3A) == 0) {
                W(0x5E1C) = 1;
                func_800D2328(p + 0x4694);
                func_800D29E0(p + 0x32DC);
                func_80074800(p, 1);
                func_800A9BE8(p + 0x5CB0, 5);
                W(0x5E08) = 0x7800;
                B(0x5DE7) = 20;
            }
            break;
        }
        break;
    case 5:
        o = p + 0x5BA0;
        func_800ADC1C(o);
        e = &(*(Vt **)(o + 0xB4))->e[3];
        e->fn(o + e->off);
        o[0xB0] = 0;
        W(0x5E08) = 0;
        B(0x5DE7) = 20;
        B(0x5DE9) = B(0x5DEA);
        break;
    case 2:
        func_80072A5C(p);
        break;
    }
}
