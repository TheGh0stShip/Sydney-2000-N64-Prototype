/* Event-bank state routine (link VRAM 0x80070FE0), ROM 0xCE890..0xCED9C. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef float f32;

extern void *D_800708C8[];
extern s32 D_80071710;
extern s32 D_800F2744;
extern s32 D_800F2778;
extern char D_800F26E0[];

extern void func_800714EC();
extern void func_800B9BD4();
extern void func_800B9964();
extern void func_80083AD8();
extern void func_8008350C();
extern void func_80082A84();
extern void func_80083580();
extern void func_800BBA1C();
extern void func_80082BEC();
extern void func_800BB9C0();
extern void func_800BB8E0();
extern f32 func_800BB8C0();
extern void func_800B8C70(void *, f32);
extern s32 func_800B9BD4b();
extern void func_800B9E9C(void *, s32, s32, f32, s32);
extern void func_800C9EF8();
extern void func_80083624();
extern void func_80082618();
extern void func_800AB2A4();

#define I32(o) (*(s32 *)(obj + (o)))
#define F(o) (*(f32 *)(obj + (o)))
#define U8(o) (*(u8 *)(obj + (o)))
#define PTR(o) (*(u8 **)(obj + (o)))

typedef struct {
    u8 pad[244];
    u8 *anim;       /* 0xF4 */
    u8 pad2[4];
    u16 frame;      /* 0xFC */
    u8 pad3[10];
    s32 idx;        /* 0x108 */
} Sub;

#define DELTA(s) ((u16)((s)->frame - *(u16 *)(*(u8 **)((s)->anim + 28) + (s)->idx * 40 + 2)))

void func_800CE890(u8 *obj, s32 arg)
{
    f32 a[4];
    f32 b[4];
    f32 c[2];
    Sub *s;

    if (arg == 0) goto end;
    func_800714EC();
    {
        static void *const unused_tbl[] = { &&L0, &&L1, &&L2, &&L3, &&L4 };
        unsigned int i = I32(0x43D0);
        if (i >= 5) goto end;
        goto *D_800708C8[i];
    }
L0:
    I32(0xF0C) -= 256;
    func_800B9BD4(obj + 0x11C8, arg, a, c, b, 0);
    func_800B9964(obj + 0x11C8, a, c, b);
    if (I32(0xF14) != 0 && I32(0xF0C) < 0) {
        func_80083AD8(obj);
        func_8008350C(obj);
        func_80082A84(obj, 15, 0, 0, 0, 0);
        func_80082A84(obj, 31, 0, 0, 0, 0);
        I32(0xF0C) = 0x5A00;
        I32(0x43D0) = 1;
        I32(0x1048) = 0;
    }
    goto end;
L1:
    {
    s32 v = I32(0xF0C) - 256;
    I32(0xF0C) = v;
    if (v <= 0) {
        I32(0x43D0) = 2;
        PTR(0xF1C)[3] = 0;
        PTR(0xF1C)[2] = 0;
        I32(0xF0C) = I32(0xF10);
        func_80083580(obj, 32);
        I32(0x2A54) = 1;
        func_800BBA1C(obj + 0x1368);
    } else if (v <= 0xF00) {
        if (v <= 0xC00) {
            func_80082BEC(obj, 31, 32);
        }
    }
    }
    goto end;
L2:
    func_800BB9C0(obj + 0x1368, D_800F2744 - D_800F2778, PTR(0xF1C));
    func_800BB8E0(obj + 0x1368);
    {
    f32 t0 = func_800BB8C0(obj + 0x1368);
    f32 k = (*(const f32 *)0x800708DC);
    F(0x43C4) = t0 * F(0x43CC);
    F(0x43C4) = F(0x43C4) * F(0x43C8);
    if (F(0x43C4) < k) {
        s32 t;
        Sub *q = (Sub *)(obj + 0x11C8);
        unsigned int d = q->frame - *(u16 *)(*(u8 **)(q->anim + 28) + q->idx * 40 + 2);
        t = 0;
        if ((d & 0xFFFF) < 13) {
            t = !((u16)d < 3);
        }
        if (t) {
            F(0x43C4) = k;
        } else if ((u16)d >= 15) {
            F(0x43C4) = k;
        } else {
            F(0x43C4) = 0;
        }
    }
    }
    s = (Sub *)(obj + 0x11C8);
    func_800B8C70(s, F(0x43C4));
    if (func_800B9BD4b(s, arg, a, c, b, 0)) {
        u8 n;
        func_800B9E9C(s, 0, -1, F(0x43C4), 0);
        n = U8(0x43C0) - 1;
        U8(0x43C0) = n;
        func_800C9EF8(obj + 0x2598, (u8)(U8(0x43C1) - n));
        func_80083624(obj, 53, U8(0x43C0), 0, 0, 0);
        if (U8(0x43C0) == 0) {
            I32(0x43D0) = 3;
        }
        D_80071710 = 0;
    }
    s = (Sub *)(obj + 0x11C8);
    func_800B9964(s, a, c, b);
    if (D_80071710 == 0) {
        if (DELTA(s) == 10) {
            D_80071710 = 1;
        }
    }
    I32(0xF0C) -= 256;
    if (I32(0xF0C) > 0) goto end;
    I32(0x43D0) = 3;
    I32(0xF0C) = 0;
    goto end;
L3:
    func_8008350C(obj);
    func_80082A84(obj, 20, 0, 0, 0, 0);
    func_80082A84(obj, 15, 0, 0, 0, 0);
    func_80082A84(obj, 52, U8(0x43C1), 0, 0, 0);
    func_80082A84(obj, 54, U8(0x43C1) - U8(0x43C0), 0, 0, 0);
    if (U8(0x43C0) == 0) {
        f32 r = (f32)I32(0xF0C) / (*(const f32 *)0x800708E0) * (*(const f32 *)0x800708E4)
              / ((f32)I32(0xF10) / (*(const f32 *)0x800708E0) * (*(const f32 *)0x800708E4)) * (*(const f32 *)0x800708E8);
        if (r >= (*(const f32 *)0x800708EC)) {
            *(s16 *)(obj + 0x11C4) = 100;
        } else if (r >= (*(const f32 *)0x800708F0)) {
            *(s16 *)(obj + 0x11C4) = 90;
        } else {
            *(s16 *)(obj + 0x11C4) = 80;
        }
    } else {
        *(s16 *)(obj + 0x11C4) = 0;
    }
    func_80082618(obj);
    I32(0xF0C) = 0x7800;
    I32(0x43D0) = 4;
    I32(0xF14) = 0;
    goto end;
L4:
    {
    s32 v = I32(0xF0C) - 256;
    I32(0xF0C) = v;
    if (I32(0xF14) != 0 && v <= 0) {
        func_800AB2A4(D_800F26E0, D_800F2744, 7, obj, 0, 7);
    }
    }
end:;
}
