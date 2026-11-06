/* Event-bank state routine (link VRAM 0x80070B58), ROM 0xD2548..0xD2B28. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
} Ent;

typedef struct {
    u8 pad[64];
    s16 off;
    s16 pad42;
    void (*fn)(u8 *);
} VT;

extern void *D_80070868[];
extern Ent D_80071A40[];
extern volatile s32 D_800F2778;
extern s32 D_800F2744;
extern char D_800F26E0[];
extern u8 D_800F1AE0[];

extern void func_800B9BD4();
extern s32 func_800B9BD4b();
extern void func_800B9964();
extern void func_80083AD8();
extern void func_8008350C();
extern void func_80082A84();
extern void func_80082BEC();
extern void func_800B8C70(void *, f32);
extern void func_800B9FA4(void *, s32, s32, f32, s32, s32);
extern void func_80071628();
extern void func_800C9EF8();
extern s32 func_8001D4B8();
extern void func_8001D640();
extern void func_80082618();
extern void func_800AB2A4();

typedef struct {
    u8 pad[0xB4];
    VT *vt;
    u8 pad2[212 - 0xB8];
} El;

#define I32(o) (*(s32 *)(obj + (o)))
#define F(o) (*(f32 *)(obj + (o)))
#define U8(o) (*(u8 *)(obj + (o)))
#define U16(o) (*(u16 *)(obj + (o)))
#define PTR(o) (*(u8 **)(obj + (o)))
#define CPTR(o) (*(signed char **)(obj + (o)))

void func_800D2548(u8 *obj, s32 arg)
{
    f32 a[4];
    f32 b[4];
    f32 c[2];
    s32 unused;

    if (arg == 0) goto end;
    unused = D_800F2778;
    {
        static void *const unused_tbl[] = { &&L0, &&L1, &&L2, &&L3, &&L4 };
        unsigned int i = I32(0x42E4);
        if (i >= 5) goto end;
        goto *D_80070868[i];
    }
L0:
    {
        u8 *s = obj + 0x11C8;
        s32 v;
        s32 f;
        u8 k;
        func_800B9BD4(s, arg, a, c, b, 0);
        func_800B9964(s, a, c, b);
        v = I32(0xF0C) - 256;
        f = I32(0xF14);
        I32(0xF0C) = v;
        if (f != 1 || v > 0) goto end;
        func_80083AD8(obj);
        func_800B8C70(s, F(0x472C));
        func_800B9FA4(s, D_80071A40[CPTR(0x4720)[U8(0x471E)]].w0, -1, F(0x472C), 0, 1);
        func_800B9BD4(s, 1, a, c, b, 0);
        func_800B9964(s, a, c, b);
        for (k = 0; k < 2; k++) {
            VT *e = *(VT **)(obj + k * 212 + 0x447C);
            e->fn(obj + (k * 212 + 0x43C8) + e->off);
        }
        func_8008350C(obj);
        func_80082A84(obj, 17, 0, 0, 0, 0);
        func_80082A84(obj, 31, 0, 0, 0, 0);
        I32(0x42E4) = 1;
        I32(0x1048) = 0;
        I32(0xF0C) = 0x5A00;
    }
    goto end;
L1:
    {
        s32 v = I32(0xF0C) - 256;
        I32(0xF0C) = v;
        if (v <= 0) {
            PTR(0xF1C)[3] = 0;
            PTR(0xF1C)[2] = 0;
            func_8008350C(obj);
            I32(0x4728) = 0;
            I32(0xF0C) = I32(0xF10);
            func_80082A84(obj, 17, 0, 0, 0, 0);
            I32(0x42E4) = 4;
            I32(0x2A54) = 1;
        } else if (v <= 0xF00) {
            if (v <= 0xC00) {
                func_80082BEC(obj, 31, 32);
            }
        }
    }
    goto end;
L4:
    if (I32(0x4728) != 0) {
        if (F(0x4570) < *(const f32 *)0x8007087C) {
            func_80071628(obj);
        }
        if (func_800B9BD4b(obj + 0x11C8, 1, a, c, b, 0)) {
            I32(0x4728) = 0;
            if (U8(0x471E) == I32(0x4718)) {
                I32(0x42E4) = 2;
            }
        }
        func_800B9964(obj + 0x11C8, a, c, b);
    } else {
        u8 ch = CPTR(0x4720)[U8(0x471E)];
        u8 ok = 0;
        if (U8(0x471D) != 0) {
            if (U8(0x471D) & D_80071A40[ch].w4) {
                u8 lo = ch < 4;
                if (lo || I32(0x473C) == 1) {
                    ok = 1;
                    if (lo) {
                        ok = I32(0x473C) != 1;
                    }
                }
            }
            U8(0x471D) = 0;
            if (ok) {
                I32(0x4714)++;
                func_800C9EF8(obj + 0x2598, U8(0x4717));
                func_800B9FA4(obj + 0x11C8, D_80071A40[ch].w0, -1, F(0x472C), 0, 1);
                I32(0x4728) = 1;
                F(0x4570) = 0;
                U8(0x471E) += 1;
            } else {
                s32 r;
                s32 m;
                I32(0x4714)--;
                if (I32(0x4714) < 0) {
                    I32(0x4714) = 0;
                }
                func_800C9EF8(obj + 0x2598, U8(0x4717));
                func_800B9FA4(obj + 0x11C8, 1, -1, F(0x472C), 0, 1);
                {
                    f32 kk = *(const f32 *)0x80070880;
                    I32(0x4728) = 1;
                    F(0x4570) = kk;
                }
                r = func_8001D4B8(D_800F1AE0, 88, 0, 1);
                m = 32767;
                func_8001D640(D_800F1AE0, r, (*(s32 *)(D_800F1AE0 + 104) * m) >> 15);
            }
        }
    }
    I32(0xF0C) -= 256;
    if (I32(0xF0C) >= 0) goto end;
    I32(0x42E4) = 2;
    goto end;
L2:
    func_8008350C(obj);
    func_80082A84(obj, 20, 0, 0, 0, 0);
    func_80082A84(obj, 17, 0, 0, 0, 0);
    func_80082A84(obj, 38, U16(0x4576), 0, 0, 0);
    func_80082A84(obj, 39, I32(0x4714), 0, 0, 0);
    if (I32(0x4714) >= U16(0x457A)) {
        *(s16 *)(obj + 0x11C4) = 100;
    } else if (I32(0x4714) >= U16(0x4578)) {
        *(s16 *)(obj + 0x11C4) = 90;
    } else if (I32(0x4714) >= U16(0x4576)) {
        *(s16 *)(obj + 0x11C4) = 80;
    } else {
        *(s16 *)(obj + 0x11C4) = 0;
    }
    func_80082618(obj);
    I32(0xF0C) = 0x7800;
    I32(0x42E4) = 3;
    I32(0xF14) = 0;
    goto end;
L3:
    {
        s32 v = I32(0xF0C) - 256;
        I32(0xF0C) = v;
        if (I32(0xF14) != 0 && v <= 0) {
            func_800AB2A4(D_800F26E0, D_800F2744, 7, obj, 0, 7);
        }
    }
end:;
}
