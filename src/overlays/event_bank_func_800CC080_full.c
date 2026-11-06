/* Event-bank state handler (link VRAM 0x80071160), ROM 0xCC080..0xCCD98. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    char pad[0xC0];
    s32 flags;
    char pad2[0xD4 - 0xC4];
} Part;

typedef struct {
    char pad[0x68];
    s32 vol;
} Snd;

extern s32 D_800F2744;
extern u32 D_800F2714;
extern u16 D_80071FB0[];
extern u16 D_80071FBC[];
extern Snd D_800F1AE0;
extern char D_800F26E0[];

extern void func_8008350C(u8 *);
extern void func_80083AD8(u8 *);
extern void func_80082A84(u8 *, s32, s32, s32, s32, s32);
extern void func_80083624(u8 *, s32, s32, s32, s32, s32);
extern void func_80082BEC(u8 *, s32, s32);
extern void func_80083580(u8 *, s32);
extern void func_8000F420(void);
extern void func_800B9FA4(void *, s32, s32, f32, s32, s32);
extern void func_800B9E9C(void *, s32, s32, f32, s32);
extern s32 func_800B9BD4(void *, void *, void *, void *, void *, s32);
extern void func_800B9964(void *, void *, void *, void *);
extern void func_800B8C70(void *, f32);
extern void func_800C9EF8(void *, s32);
extern s32 func_8001D4B8(Snd *, s32, s32, s32);
extern void func_8001D640(Snd *, s32, s32);
extern void func_800AD434(void *, f32, s32);
extern void func_80082618(u8 *);
extern void func_800AB2A4(char *, s32, s32, u8 *, s32, s32);

#define F32(o) (*(s32 *)(obj + (o)))
#define FF(o) (*(f32 *)(obj + (o)))
#define U8(o) (*(u8 *)(obj + (o)))
#define U16(o) (*(u16 *)(obj + (o)))
#define FPTR(o) (*(u8 **)(obj + (o)))
#define K(a) (*(const f32 *)(a))
#define PART(i) (((Part *)(obj + 0x4400))[i])

static __inline__ void sfx(s32 id, s32 vol)
{
    Snd *s = &D_800F1AE0;
    func_8001D640(s, func_8001D4B8(s, id, 0, 1), (s->vol * vol) >> 15);
}

static __inline__ u32 rnd(void)
{
    D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
    return D_800F2714;
}

void func_800CC080(u8 *obj, void *arg)
{
    s32 a[4];
    s32 c[4];
    s32 z[3];
    s32 b[2];
    f32 f;
    u32 m, n;

    if (arg == 0) goto end;
    switch (F32(0x43C8)) {
    case 0: goto L0;
    case 1: goto L1;
    case 2: goto L2;
    case 3: goto L3;
    case 4: goto L4;
    case 5: goto L5;
    case 6: goto L6;
    case 7: goto L7;
    default: goto end;
    }
L0:
    {
        u8 *p = obj + 0x11C8;
        F32(0xF0C) -= 0x100;
        if (func_800B9BD4(p, arg, a, b, c, 0)) {
            func_800B8C70(p, 0);
        }
        func_800B9964(p, a, b, c);
    }
    if (F32(0xF14) == 0) goto end;
    if (F32(0xF0C) >= 0) goto end;
    func_8008350C(obj);
    func_80083AD8(obj);
    func_80082A84(obj, 16, 0, 0, 0, 0);
    func_80082A84(obj, 47, U8(0x43F4), 0, 0, 0);
    func_80082A84(obj, 48, U8(0x43F8) - U8(0x43F7), 0, 0, 0);
    func_80082A84(obj, 31, 0, 0, 0, 0);
    F32(0xF0C) = 0x5A00;
    F32(0x43C8) = 1;
    F32(0x1048) = 0;
    goto end;
L1:
    {
        s32 t = F32(0xF0C) - 0x100;
        F32(0xF0C) = t;
        if (t <= 0) {
            u8 *p = obj + 0x11C8;
            f = 1.0f;
            func_800B9FA4(p, 2, -1, f, 0, 1);
            func_80083580(obj, 32);
            func_8000F420();
            F32(0x43C8) = 2;
            F32(0xF0C) = 0x3C00;
            func_800B8C70(p, f);
            {
                u32 x = (D_800F2714 * 16807) & 0x7FFFFFFF;
                u32 m = (x >> 15) * U8(0x43EC);
                D_800F2714 = x;
                U8(0x43F6) = m >> 16;
                U16(0x43D8) = D_80071FB0[U8(0x43F6)];
            }
            FPTR(0xF1C)[3] = 0;
            FPTR(0xF1C)[2] = 0;
            F32(0x43DC) = 0;
            F32(0x43D4) = 0;
            F32(0x43F0) = 1;
        } else if (t < 0xF01) {
            if (t < 0xC01) {
                func_80082BEC(obj, 31, 32);
            }
        }
    }
    goto end;
L2:
    {
        u8 *p = obj + 0x11C8;
        s32 t;
        if (func_800B9BD4(p, arg, a, b, c, 0)) {
            func_800B9E9C(p, 4, -1, 1.0f, 0);
            func_800B8C70(p, 0);
        }
        func_800B9964(p, a, b, c);
        t = F32(0xF0C) - 0x100;
        F32(0xF0C) = t;
        if (t <= 0) {
            sfx(D_80071FBC[U8(0x43F6)], 0x7FFF);
            PART(U8(0x43F6)).flags &= ~4;
            F32(0x43C8) = 3;
            FPTR(0xF1C)[3] = 0;
            FPTR(0xF1C)[2] = 0;
            F32(0xF0C) = 0x1E00;
            func_800B8C70(p, 0.6f);
            F32(0x43E0) = 0;
            F32(0x43D0) = 0;
            F32(0x43F0) = 0;
        }
        if (F32(0x43F0) != 0) goto end;
        if (F32(0x43DC) == 0 && F32(0x43D4) == 0) goto end;
        F32(0xF0C) = 0x1E00;
        F32(0x43C8) = 3;
        func_800B9FA4(p, 4, -1, 0.6f, 0, 1);
        F32(0x43CC) = 1;
        F32(0x43D4) = 0;
    }
    goto end;
L3:
    F32(0xF0C) -= 0x100;
    F32(0x43E0) += 0x100;
    if (F32(0x43DC) != 0) {
        u8 *p = obj + 0x11C8;
        func_800B9BD4(p, arg, a, b, c, 0);
        func_800B9964(p, a, b, c);
        if (F32(0x43D0) == 0) {
            PART(U8(0x43F6)).flags |= 4;
            F32(0x43D0) = 1;
            F32(0x43E4) += F32(0x43E0);
            F32(0x43E4) += F32(0x43FC);
        }
    } else if (F32(0x43D4) != 0) {
        F32(0xF0C) = 0;
        PART(U8(0x43F6)).flags |= 4;
        F32(0x43CC) = 1;
        F32(0x43D4) = 0;
    }
    if (F32(0xF0C) > 0) goto end;
    if (F32(0x43D0) == 0) {
        u8 *p;
        F32(0x43E4) += F32(0x43E0);
        func_80083624(obj, 47, U8(0x43F5), 0, 0, 0);
        p = obj + 0x11C8;
        z[0] = 0;
        z[1] = 0;
        z[2] = 0;
        F32(0x43C8) = 5;
        F32(0xF0C) = 0x5A00;
        F32(0x43CC) = 1;
        PART(U8(0x43F6)).flags |= 4;
        func_800B9FA4(p, 0, -1, 1.0f, 0, 1);
        func_800B9E9C(p, 2, -1, 1.0f, 0);
    } else if (F32(0x43CC) == 0) {
        sfx(196, 0x7FFF);
    }
    F32(0x43C8) = 4;
    F32(0xF0C) = 0x1E00;
    func_800B8C70(obj + 0x11C8, 0);
    goto end;
L4:
    {
        s32 t = F32(0xF0C) - 0x100;
        F32(0xF0C) = t;
        if (t > 0) goto end;
    }
    if (F32(0x43CC) != 0) {
        U8(0x43F7)++;
        func_80083624(obj, 48, U8(0x43F8) - U8(0x43F7), 0, 0, 0);
    } else {
        U8(0x43F5)--;
    }
    func_800C9EF8(obj + 0x2598, (u8)(U8(0x43F4) - U8(0x43F5)));
    if (U8(0x43F5) == 0 || U8(0x43F7) > U8(0x43F8)) {
        F32(0x43C8) = 6;
        F32(0xF0C) = 0;
        goto end;
    }
    func_80083624(obj, 47, U8(0x43F5), 0, 0, 0);
    {
        u8 *mtx = obj + 0x11DC;

        F32(0x43C8) = 5;
        F32(0xF0C) = 0x5A00;
        F32(0x1340) = 0;
        *(f32 *)(mtx + 36) = 0;
        *(f32 *)(mtx + 32) = 0;
        *(f32 *)(mtx + 24) = 0;
        *(f32 *)(mtx + 16) = 0;
        *(f32 *)(mtx + 8) = 0;
        *(f32 *)(mtx + 4) = 0;
        *(f32 *)(mtx + 72) = 0;
        *(f32 *)(mtx + 68) = 0;
        *(f32 *)(mtx + 64) = 0;
        *(f32 *)(mtx + 40) = 1.0f;
        *(f32 *)(mtx + 20) = 1.0f;
        *(f32 *)(mtx + 0) = 1.0f;
        func_800AD434(mtx, 1.5707961f, 3);
    }
    {
        u8 *p = obj + 0x11C8;
        func_800B9FA4(p, 0, -1, 1.0f, 0, 1);
        func_800B9E9C(p, 2, -1, 1.0f, 0);
    }
    goto end;
L5:
    {
        u8 *p = obj + 0x11C8;
        s32 t;
        if (func_800B9BD4(p, arg, a, b, c, 0)) {
            func_800B8C70(p, 0);
        }
        func_800B9964(p, a, b, c);
        t = F32(0xF0C) - 0x100;
        F32(0xF0C) = t;
        if (t > 0) goto end;
        F32(0x43C8) = 2;
        F32(0x43DC) = 0;
        F32(0x43D4) = 0;
        F32(0x43CC) = 0;
        F32(0xF0C) = 0x3C00;
        func_800B8C70(p, 1.0f);
    }
    F32(0x1340) = 0;
    {
        u32 x = (D_800F2714 * 16807) & 0x7FFFFFFF;
        u32 m = (x >> 15) * U8(0x43EC);
        D_800F2714 = x;
        U8(0x43F6) = m >> 16;
        U16(0x43D8) = D_80071FB0[U8(0x43F6)];
    }
    goto end;
L6:
    f = (f32)F32(0x43E4) / K(0x80070914) * K(0x80070918);
    f /= (f32)U8(0x43F4);
    func_8008350C(obj);
    func_80082A84(obj, 16, 0, 0, 0, 0);
    func_80082A84(obj, 20, 0, 0, 0, 0);
    if (FF(0x43E8) < f) {
        F32(0x43CC) = 1;
    }
    if (U8(0x43F7) > U8(0x43F8)) {
        F32(0x43CC) = 1;
    }
#define F2U(x, k) ({ u32 _r; f32 _x = (x); if (!(_x >= K(k))) _r = (s32)_x; else { _r = (s32)(_x - K(k)); _r |= 0x80000000; } _r; })
    if (F32(0x43CC) == 0) {
        m = F2U(FF(0x43E8), 0x8007091C);
        n = F2U(FF(0x43E8) * K(0x80070920), 0x80070924);
        func_80082A84(obj, 49, m, n - m * 100, 0, 0);
        m = F2U(f, 0x80070928);
        n = F2U(f * K(0x8007092C), 0x80070930);
        func_80082A84(obj, 50, m, n - m * 100, 0, 0);
        {
            f32 g = FF(0x43E8);
            f32 p1 = g * K(0x80070934);
            f32 p2 = g * K(0x80070938);
        if (f <= p1) {
            U16(0x11C4) = 100;
        } else if (f <= p2) {
            U16(0x11C4) = 90;
        } else {
            U16(0x11C4) = 80;
        }
        }
    } else {
        if (U8(0x43F7) > U8(0x43F8)) {
            func_80082A84(obj, 51, 0, 0, 0, 0);
        } else {
            m = F2U(FF(0x43E8), 0x8007093C);
            n = F2U(FF(0x43E8) * K(0x80070940), 0x80070944);
            func_80082A84(obj, 49, m, n - m * 100, 0, 0);
            m = F2U(f, 0x80070948);
            n = F2U(f * K(0x8007094C), 0x80070950);
            func_80082A84(obj, 50, m, n - m * 100, 0, 0);
        }
        U16(0x11C4) = 0;
    }
    func_80082618(obj);
    F32(0xF0C) = 0x7800;
    F32(0x43C8) = 7;
    F32(0xF14) = 0;
    goto end;
L7:
    {
        s32 t = F32(0xF0C) - 0x100;
        s32 u = F32(0xF14);
        F32(0xF0C) = t;
        if (u == 0) goto end;
        if (t > 0) goto end;
        func_800AB2A4(D_800F26E0, D_800F2744, 7, obj, 0, 7);
    }
end:;
}
