/* Event-bank state-machine update (link VRAM 0x80070D24), ROM 0xBB764..0xBC388. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct {
    char pad[0x68];
    s32 vol;
} Snd;

extern volatile s32 D_800F2744;
extern volatile s32 D_800F2778;
extern Snd D_800F1AE0;
extern char D_800F26E0[];
extern void *D_80070808[];

extern void func_80072228(u8 *);
extern void func_8007226C(u8 *, f32);
extern void func_800721A0(u8 *, f32);
extern void func_8008350C(u8 *);
extern void func_80082A84(u8 *, s32, s32, s32, s32, s32);
extern void func_80083AD8(u8 *);
extern void func_80082BEC(u8 *, s32, s32);
extern void func_800B9FA4(void *, s32, s32, f32, s32, s32);
extern void func_800B9E9C(void *, s32, s32, f32, s32);
extern s32 func_800B9BD4(void *, void *, void *, void *, void *, s32);
extern void func_800B9964(void *, void *, void *, void *);
extern void func_800AD9E8(void *);
extern void func_800BB9C0(void *, s32, u8 *);
extern void func_800BB8E0(void *);
extern f32 func_800BB8C0(void *);
extern s32 func_8001D4B8(Snd *, s32, s32, s32);
extern void func_8001D640(Snd *, s32, s32);
extern void func_80082618(u8 *);
extern void func_800AB2A4(char *, s32, s32, u8 *, s32, s32);

#define F32(o) (*(s32 *)(obj + (o)))
#define FF(o) (*(f32 *)(obj + (o)))
#define U8(o) (*(u8 *)(obj + (o)))
#define S16(o) (*(s16 *)(obj + (o)))
#define FPTR(o) (*(u8 **)(obj + (o)))
#define K(a) (*(f32 *)(a))

static __inline__ void sfx(s32 id, s32 vol) {
    Snd *s = &D_800F1AE0;
    func_8001D640(s, func_8001D4B8(s, id, 0, 1), (s->vol * vol) >> 15);
}

void func_800BB764(u8 *obj, void *arg)
{
    f32 a[4];
    f32 c[4];
    f32 b[2];
    s32 dt;
    s32 t;

    if (arg == 0) goto end;
    {
        static void *const unused_tbl[] = { &&L0, &&L1, &&L3, &&L5, &&L7, &&L8, &&L9, &&L10 };
        unsigned int i;
        dt = D_800F2744 - D_800F2778;
        i = F32(0x42EC);
        if (i >= 11) goto end;
        goto *D_80070808[i];
    }
L0:
    if (F32(0x44A0) == 0) {
        F32(0x44A0) = 1;
    }
    F32(0xF0C) -= 0x100;
    func_800B9BD4((obj + 0x11C8), arg, a, b, c, 0);
    func_800B9964((obj + 0x11C8), a, b, c);
    func_80072228(obj);
    func_800B9E9C((obj + 0x11C8), 0, -1, 1.0f, 0);
    t = F32(0xF14);
    if (t == 1 && F32(0xF0C) <= 0) {
        func_80083AD8(obj);
        func_8008350C(obj);
        func_80082A84(obj, 5, 0, 0, 0, 0);
        func_80082A84(obj, 31, 0, 0, 0, 0);
        F32(0x1048) = 0;
        F32(0x42EC) = t;
        F32(0xF0C) = 0x5A00;
    }
    goto end;
L1:
    F32(0xF0C) -= 0x100;
    if (func_800B9BD4((obj + 0x11C8), arg, a, b, c, 0) != 0) {
        func_800B9E9C((obj + 0x11C8), 0, -1, 1.0f, 0);
    }
    func_800B9964((obj + 0x11C8), a, b, c);
    {
        s32 t1 = F32(0xF0C);
        if (t1 <= 0) {
            FPTR(0xF1C)[3] = 0;
            FPTR(0xF1C)[2] = 0;
            U8(0x4490) = 0;
            FF(0x4428) = 0.0f;
            F32(0x42EC) = 9;
            F32(0xF0C) = F32(0xF10);
        } else if (t1 < 0xF01) {
            if (t1 < 0xC01) {
                func_80082BEC(obj, 31, 32);
            }
        }
    }
    goto end;
L9:
    {
        u8 *q = obj + 0x1368;
        u8 *r;
        F32(0x449C) -= 0x100;
        func_800BB9C0(q, dt, FPTR(0xF1C));
        func_800BB8E0(q);
        FF(0x4428) += func_800BB8C0(q) * FF(0x443C) * K(0x80070834) / K(0x80070838);
        r = obj + 0x1384;
        if (*(f32 *)(r + 0x11EC) < FF(0x4428)) {
            FF(0x4428) = *(f32 *)(r + 0x11EC);
        }
        *(f32 *)(r + 0x11F0) = FF(0x4428);
        if (F32(0x44C0) == 1 || F32(0x449C) <= 0) {
            *(s32 *)(r + 0x11F4) = 0;
            F32(0x44C4) = 0;
            F32(0x44A4) = 1;
            F32(0x44B0) = 0;
            F32(0x44A8) = 0;
            F32(0x44AC) = 0;
            F32(0x4498) = D_800F2744 + 0xF00;
            func_800B9FA4(obj + 0x11C8, 2, -1, 1.0f, 0, 1);
            F32(0x42EC) = 10;
        }
    }
    if (func_800B9BD4((obj + 0x11C8), arg, a, b, c, 0) != 0 && F32(0x44A4) == 0) {
        func_800B9E9C((obj + 0x11C8), 0, -1, 1.0f, 0);
    }
    goto tail;
L10:
    if (D_800F2744 > F32(0x4498)) {
        if (F32(0x44C0) == 1) {
            F32(0x44C4) = 1;
        }
    } else {
        F32(0x44C4) = 0;
    }
    if (F32(0x44C4) == 1 && F32(0x44AC) == 0) {
        func_8007226C(obj, FF(0x442C));
    }
    if (F32(0x44AC) == 1 && F32(0x44C4) == 0) {
        func_8007226C(obj, FF(0x442C));
    }
    if (func_800B9BD4((obj + 0x11C8), arg, a, b, c, 0) != 0) {
        F32(0x44AC) = 1;
        if (F32(0x44B0) == 1) {
            F32(0x42EC) = 3;
        }
        if (F32(0x44C4) == 1 && F32(0x44B0) == 0) {
            F32(0x44B0) = 1;
                        switch (((s8 *)FPTR(0x42E4) + U8(0x4334)++)[5]) {
            case 1:
                if (FF(0x4428) >= K(0x8007083C)) {
                    func_800B9E9C((obj + 0x11C8), 4, -1, 1.0f, 0);
                    sfx(272, 32767);
                } else {
                    func_800B9E9C((obj + 0x11C8), 8, -1, 1.0f, 0);
                    F32(0x42EC) = 5;
                }
                break;
            case 2:
                if (FF(0x4428) >= K(0x80070840)) {
                    func_800B9E9C((obj + 0x11C8), 5, -1, 1.0f, 0);
                    sfx(272, 32767);
                } else {
                    func_800B9E9C((obj + 0x11C8), 9, -1, 1.0f, 0);
                    F32(0x42EC) = 5;
                }
                break;
            case 3:
                if (FF(0x4428) >= K(0x80070844)) {
                    func_800B9E9C((obj + 0x11C8), 6, -1, 1.0f, 0);
                    sfx(272, 32767);
                } else {
                    func_800B9E9C((obj + 0x11C8), 10, -1, 1.0f, 0);
                    F32(0x42EC) = 5;
                }
                break;
            }
        }
    }
    func_800B9964((obj + 0x11C8), a, b, c);
    func_800721A0(obj, -FF(0x1224));
    FF(0x1224) = 0.0f;
    func_800AD9E8((obj + 0x11C8));
    if (F32(0x42EC) == 3) {
        F32(0x44A8) = 0;
        F32(0x44B4) = 0;
        F32(0x44C0) = 0;
        F32(0x44C4) = 0;
        F32(0x44A4) = 0;
        F32(0x44B0) = 0;
        F32(0x44AC) = 0;
    }
    goto end;
L3:
    if (F32(0x44C0) == 1) {
        F32(0x44A4) = 1;
    }
    if (F32(0x44BC) == 0) {
        if (F32(0x44A4) == 1 && F32(0x44AC) == 0) {
            func_8007226C(obj, FF(0x442C));
        }
        if (F32(0x44AC) == 1 && F32(0x44A4) == 0) {
            func_8007226C(obj, FF(0x442C));
        }
    }
    if (func_800B9BD4((obj + 0x11C8), arg, a, b, c, 0) == 0) goto tail;
    if (F32(0x44B0) == 1) goto X;
    F32(0x44AC) = 1;
    if (F32(0x44BC) == 1) {
        F32(0x42EC) = 5;
        goto tail;
    }
    {
        s32 one = F32(0x44A4);
        f32 k;
        if (one != 1) goto tail;
                switch (({ s8 *tb_ = (s8 *)FPTR(0x42E4) + 5; tb_[U8(0x4334)]; })) {
        case 1:
            if (FF(0x4428) >= K(0x80070848)) {
                k = K(0x8007084C);
                func_800B9E9C((obj + 0x11C8), 4, -1, k, 0);
                sfx(272, 32767);
                if (F32(0x4494) == U8(0x4334) + 1) {
                    F32(0x44BC) = one;
                    func_800B9E9C((obj + 0x11C8), 9, -1, k, 0);
                }
            } else {
                func_800B9E9C((obj + 0x11C8), 8, -1, 1.0f, 0);
                F32(0x42EC) = 5;
            }
            break;
        case 2:
            if (FF(0x4428) >= K(0x80070850)) {
                sfx(272, 32767);
                k = K(0x80070854);
                func_800B9E9C((obj + 0x11C8), 5, -1, k, 0);
                if (F32(0x4494) == U8(0x4334) + 1) {
                    F32(0x44BC) = one;
                    func_800B9E9C((obj + 0x11C8), 10, -1, k, 0);
                }
            } else {
                func_800B9E9C((obj + 0x11C8), 9, -1, 1.0f, 0);
                F32(0x42EC) = 5;
            }
            break;
        case 3:
            if (FF(0x4428) >= K(0x80070858)) {
                sfx(272, 32767);
                k = K(0x8007085C);
                func_800B9E9C((obj + 0x11C8), 6, -1, k, 0);
                if (F32(0x4494) == U8(0x4334) + 1) {
                    F32(0x44BC) = one;
                    func_800B9E9C((obj + 0x11C8), 11, -1, k, 0);
                }
            } else {
                func_800B9E9C((obj + 0x11C8), 10, -1, 1.0f, 0);
                F32(0x42EC) = 5;
            }
            break;
        }
        F32(0x44C4) = 0;
        F32(0x44C0) = 0;
        F32(0x44A4) = 0;
        F32(0x44B0) = 1;
        F32(0x44A8) = 0;
        F32(0x44AC) = 0;
        U8(0x4334)++;
    }
    goto tail;
X:
    {
                switch (({ s8 *tb_ = (s8 *)FPTR(0x42E4) + 5; tb_[U8(0x4334)]; })) {
        case 1:
            func_8007226C(obj, 0.003f);
            break;
        case 2:
            func_8007226C(obj, 0.005f);
            break;
        case 3:
            func_8007226C(obj, 0.007f);
            break;
        }
        F32(0x44B0) = 0;
        goto tail;
    }
L5:
    if (func_800B9BD4((obj + 0x11C8), arg, a, b, c, 0) == 0) goto tail;
    switch (U8(0x4338)) {
    case 0:
        func_800B9E9C((obj + 0x11C8), 1, -1, 1.0f, 0);
        if (F32(0x44BC) == 0) {
            sfx(172, 32767);
            break;
        }
        goto set7;
    case 1:
        func_800B9E9C((obj + 0x11C8), 1, -1, 1.0f, 0);
    case 2:
    set7:
        F32(0x42EC) = 7;
        U8(0x4338) = 0;
        break;
    }
    U8(0x4338)++;
tail:
    func_800B9964((obj + 0x11C8), a, b, c);
    func_800721A0(obj, -FF(0x1224));
    FF(0x1224) = 0.0f;
    func_800AD9E8((obj + 0x11C8));
    goto end;
L7:
    func_8008350C(obj);
    func_80082A84(obj, 20, 0, 0, 0, 0);
    func_80082A84(obj, 5, 0, 0, 0, 0);
    func_80082A84(obj, 38, F32(0x4494), 0, 0, 0);
    if (F32(0x44BC) == 1) {
        func_80082A84(obj, 39, U8(0x4334), 0, 0, 0);
        if (FF(0x4428) >= FF(0x42F8)) {
            S16(0x11C4) = 100;
        } else if (FF(0x4428) >= FF(0x42F4)) {
            S16(0x11C4) = 90;
        } else {
            S16(0x11C4) = 80;
        }
    } else {
        func_80082A84(obj, 39, U8(0x4334) - 1, 0, 0, 0);
        S16(0x11C4) = 0;
    }
    func_80082618(obj);
    F32(0xF0C) = 0x7800;
    F32(0x42EC) = 8;
    F32(0xF14) = 0;
    goto end;
L8:
  {
    s32 t3 = F32(0xF0C) - 0x100;
    F32(0xF0C) = t3;
    if (F32(0xF14) != 0 && t3 <= 0) {
        func_800AB2A4(D_800F26E0, D_800F2744, 7, obj, 0, 7);
    }
  }
end:
    ;
}
