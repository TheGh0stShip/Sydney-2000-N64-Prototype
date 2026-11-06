/* Event-bank state-machine update (link VRAM 0x800715D4), ROM 0xC9EC4..0xCA7DC. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct {
    char pad[0xC0];
    s32 flags;
} Obj;

typedef struct {
    char pad[0x68];
    s32 vol;
} Snd;

extern volatile s32 D_800F2778;
extern s32 D_800F2744;
extern s8 D_80072DF4[2];
extern Snd D_800F1AE0;
extern char D_800F26E0[];
extern char D_800707E0[];
extern char D_800707E8[];
extern void *D_800708E0[];

extern void func_800AD4E0(void *, f32, s32);
extern void func_80071104(u8 *);
extern void func_8008350C(u8 *);
extern void func_80082A84(u8 *, s32, s32, s32, s32, s32);
extern void func_80083AD8(u8 *);
extern void func_80082BEC(u8 *, s32, s32);
extern void func_800B9FA4(void *, s32, s32, s32, s32, s32);
extern void func_800B9E9C(void *, s32, s32, s32, s32);
extern s32 func_800B9BD4(void *, void *, void *, void *, void *, s32);
extern void func_800B9964(void *, void *, void *, void *);
extern void func_800709B0(u8 *);
extern void func_800C9EF8(void *, s32);
extern s32 func_8001D4B8(Snd *, s32, s32, s32);
extern void func_8001D640(Snd *, s32, s32);
extern s32 func_8000EB20(char *);
extern void func_80017CF4(s32, s32, s32);
extern void func_80082618(u8 *);
extern void func_800AB2A4(char *, s32, s32, u8 *, s32, s32);

#define F32(o) (*(s32 *)(obj + (o)))
#define FF(o) (*(f32 *)(obj + (o)))
#define U8(o) (*(u8 *)(obj + (o)))
#define S8(o) (*(s8 *)(obj + (o)))
#define U16(o) (*(u16 *)(obj + (o)))
#define S16(o) (*(s16 *)(obj + (o)))
#define FPTR(o) (*(u8 **)(obj + (o)))

static __inline__ void clr(Obj *o) { o->flags &= ~4; }
static __inline__ void set(Obj *o) { o->flags |= 4; }

static __inline__ void sfx(s32 id, s32 vol) {
    Snd *s = &D_800F1AE0;
    func_8001D640(s, func_8001D4B8(s, id, 0, 1), (s->vol * vol) >> 15);
}

void func_800C9EC4(u8 *obj, void *arg)
{
    f32 a[4];
    f32 c[4];
    f32 b[2];
    Obj *o = (Obj *)(obj + 0x42F0);
    s32 t;
    s32 s4;
    s32 r;

    if (arg == 0) goto end;
    if (F32(0x4734) == 1) {
        func_800AD4E0(obj + 0x4304, -FF(0x4728), 3);
        clr(o);
    }
    func_80071104(obj);
    {
        static void *const unused_tbl[] = { &&L0, &&L1, &&L2, &&L3, &&L5, &&L6, &&L7 };
        unsigned int i = F32(0x42E4);
        r = D_800F2778;
        if (i >= 8) goto end;
        goto *D_800708E0[i];
    }
L0:
    F32(0xF0C) -= 0x100;
    t = F32(0xF14);
    if (t == 1 && F32(0xF0C) <= 0) {
        func_8008350C(obj);
        func_80082A84(obj, 14, 0, 0, 0, 0);
        func_80082A84(obj, 31, 0, 0, 0, 0);
        F32(0x1048) = 0;
        F32(0x42E4) = t;
        F32(0xF0C) = 0x5A00;
        func_80083AD8(obj);
    }
    goto end;
L1:
  {
    s32 t1 = F32(0xF0C) - 0x100;
    F32(0xF0C) = t1;
    if (t1 <= 0) {
        u8 *p = obj + 0x11C8;
        FPTR(0xF1C)[3] = 0;
        FPTR(0xF1C)[2] = 0;
        F32(0x42E4) = 5;
        F32(0xF0C) = F32(0xF10);
        func_800B9FA4(p, 1, -1, F32(0x4724), 0, 1);
        func_800B9E9C(p, 6, -1, F32(0x4724), 0);
        {
            f32 f = FF(0x471C) * *(f32 *)0x80070900;
            s32 now = D_800F2744;
            U8(0x4706) = 0;
            F32(0x472C) = now;
            F32(0x473C) = 1;
            F32(0x472C) = now + (s32)f;
        }
        D_80072DF4[0] = 2;
        D_80072DF4[1] = 6;
    } else if (t1 < 0xF01) {
        if (t1 < 0xC01) {
            func_80082BEC(obj, 31, 32);
        }
    }
  }
    goto end;
L7:
    if (func_800B9BD4(obj + 0x11C8, arg, a, b, c, 0) != 0) {
        if (++U8(0x4706) == 2) {
            func_800B9E9C(obj + 0x11C8, 2, -1, F32(0x4724), 0);
            F32(0x42E4) = 5;
        }
    }
    goto tail;
L5:
    if (D_800F2744 > F32(0x472C) && F32(0x4730) == 0) {
        F32(0x4730) = 1;
        if (F32(0x473C) == 0) {
            func_800709B0(obj);
        }
    }
    s4 = F32(0x4730);
    if (s4 == 1 && F32(0x4738) == 0) {
        u8 *p = obj + 0x11C8;
        s32 v;
        D_80072DF4[0] = 10;
        D_80072DF4[1] = 11;
        func_800B9E9C(p, 11, -1, F32(0x4724), 0);
        v = F32(0x4754);
        if (v == s4) {
            F32(0x4754) = 0;
            if (F32(0x4748) == v) {
                if (++U8(0x470D) == 2) {
                    U8(0x4707) = 3;
                    D_80072DF4[0] = 2;
                    D_80072DF4[1] = 6;
                    F32(0x4738) = v;
                    func_800B9E9C(p, D_80072DF4[1], -1, F32(0x4724), 0);
                    U8(0x470D) = 0;
                }
            } else {
                U8(0x4707) = 0;
                D_80072DF4[0] = 2;
                D_80072DF4[1] = 6;
                F32(0x4738) = v;
                func_800B9E9C(p, D_80072DF4[1], -1, F32(0x4724), 0);
            }
        }
        v = F32(0x4750);
        if (v == 1) {
            F32(0x4750) = 0;
            if (F32(0x4748) == v) {
                if (++U8(0x470C) == 2) {
                    U8(0x4707) = 4;
                    D_80072DF4[0] = 5;
                    D_80072DF4[1] = 8;
                    F32(0x4738) = v;
                    func_800B9E9C(obj + 0x11C8, D_80072DF4[1], -1, F32(0x4724), 0);
                    U8(0x470C) = 0;
                }
            } else {
                U8(0x4707) = v;
                D_80072DF4[0] = 5;
                D_80072DF4[1] = 8;
                F32(0x4738) = v;
                func_800B9E9C(obj + 0x11C8, D_80072DF4[1], -1, F32(0x4724), 0);
            }
        }
        v = F32(0x474C);
        if (v == 1) {
            F32(0x474C) = 0;
            if (F32(0x4748) == v) {
                if (++U8(0x470B) == 2) {
                    U8(0x4707) = 5;
                    D_80072DF4[0] = 4;
                    D_80072DF4[1] = 7;
                    F32(0x4738) = v;
                    func_800B9E9C(obj + 0x11C8, D_80072DF4[1], -1, F32(0x4724), 0);
                    U8(0x470B) = 0;
                }
            } else {
                U8(0x4707) = 2;
                D_80072DF4[0] = 4;
                D_80072DF4[1] = 7;
                F32(0x4738) = v;
                func_800B9E9C(obj + 0x11C8, D_80072DF4[1], -1, F32(0x4724), 0);
            }
        }
    }
    if (func_800B9BD4(obj + 0x11C8, arg, a, b, c, 0) != 0) {
        s32 n = S8(0x4704);
        U8(0x470C) = 0;
        U8(0x470B) = 0;
        U8(0x470D) = 0;
        if (n != 0) {
            if (S8(0x4707) == ((s8 *)FPTR(0x4710))[n - 1]) {
                U8(0x4708)++;
                func_800C9EF8(obj + 0x2598, U8(0x4708));
                sfx(230, 32767);
            } else {
                sfx(276, 32767);
                U8(0x4709)--;
            }
        }
        F32(0x42E4) = 6;
        S8(0x4707) = -1;
        F32(0x4730) = 0;
        F32(0x473C) = 0;
        func_800B9E9C(obj + 0x11C8, D_80072DF4[0], -1, F32(0x4724), 0);
        F32(0x4734) = 1;
    }
    goto tail;
L6:
    if (func_800B9BD4(obj + 0x11C8, arg, a, b, c, 0) != 0) {
        func_800B9E9C(obj + 0x11C8, D_80072DF4[1], -1, F32(0x4724), 0);
        F32(0x4738) = 0;
        F32(0x42E4) = 5;
        func_80017CF4(F32(0x449C), 0, func_8000EB20(D_800707E0) & 0xFFFF);
        func_80017CF4(F32(0x4574), 0, func_8000EB20(D_800707E8) & 0xFFFF);
        if (U8(0x4708) == F32(0x4700) - (U8(0x470A) - U16(0x46F8))) {
            F32(0x42E4) = 2;
            S8(0x4704) = 0;
        }
        if (S8(0x4709) < 0) {
            F32(0x42E4) = 2;
            S8(0x4704) = 0;
            F32(0x4740) = 1;
        }
        if (S8(0x4704) >= F32(0x4700)) {
            F32(0x42E4) = 2;
            S8(0x4704) = 0;
        }
        if (((s8 *)FPTR(0x4710))[S8(0x4704)] < 3) {
            F32(0x4748) = 0;
        } else {
            F32(0x4748) = 1;
            func_80082A84(obj, 55, 0, 0, 0, 0);
        }
        {
            f32 f = FF(0x471C) * *(f32 *)0x80070904;
            s32 now = D_800F2744;
            F32(0x472C) = now;
            U8(0x4704)++;
            F32(0x472C) = now + (s32)f;
        }
    }
tail:
    func_800B9964(obj + 0x11C8, a, b, c);
    goto end;
L2:
    F32(0x4734) = 0;
    set((Obj *)(obj + 0x42F0));
    func_8008350C(obj);
    func_80082A84(obj, 20, 0, 0, 0, 0);
    func_80082A84(obj, 14, 0, 0, 0, 0);
    func_80082A84(obj, 38, F32(0x4700) - U16(0x46F4), 0, 0, 0);
    func_80082A84(obj, 39, U8(0x4708), 0, 0, 0);
    U8(0x4708) = U8(0x4703) - U8(0x4708);
    if (F32(0x4740) == 1) {
        S16(0x11C4) = 0;
    } else {
        s32 n = U8(0x470A);
        if (n - U16(0x46F8) >= U8(0x4708)) {
            S16(0x11C4) = 100;
        } else if (n - U16(0x46F6) >= U8(0x4708)) {
            S16(0x11C4) = 90;
        } else {
            S16(0x11C4) = 80;
        }
    }
    func_80082618(obj);
    F32(0xF0C) = 0x7800;
    F32(0x42E4) = 3;
    F32(0xF14) = 0;
    goto end;
L3:
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
