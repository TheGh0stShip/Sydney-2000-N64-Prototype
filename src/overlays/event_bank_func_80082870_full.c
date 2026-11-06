/* Event-bank event handler (link VRAM 0x800714A0), ROM 0x82870..0x830FC.
 * 23-entry jump table at link VRAM 0x80070FF0 stays residual data. */
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;
typedef unsigned int u32;

typedef struct {
    s32 type;
    s32 time;
    s32 pad08;
    u8 *ptr;
    s32 arg;
} Event;

typedef struct {
    u8 *obj;
    s32 a;
    s32 b;
    s32 c;
    s16 d;
    s16 e;
} Slot;

extern void *D_80070FF0[];
extern u8 D_80077740;
extern u8 D_800F1AE0[];
extern u8 D_800F2AD0[];
extern u8 D_800F26E0[];
extern s32 D_800F2744;
extern s32 D_800F2714;

extern void func_800B4794(s32);
extern void func_80073318(u8 *);
extern void func_80073D18(u8 *);
extern void func_800A9BE8(u8 *, s32);
extern void func_80072574(u8 *, s32);
extern void func_800AAC84(u8 *, u8 *, u8 *, s32);
extern s32 func_8001D4B8(u8 *, s32, s32, s32);
extern void func_8001D640(u8 *, s32, s32);
extern void func_8001D5D8(u8 *, s32, s32, s32, s32, s32);
extern void func_800BBB94(s32);
extern void func_800742E0(u8 *, u8, f32);
extern void func_800AC25C(u8 *, s32, s32, s32);
extern void func_800BC07C(u8 *, s32);
extern void func_8009C0D8(s32, s32);
extern void func_80074F24(u8 *);
extern void func_80073AF0(u8 *);
extern void func_80076FA0(u8 *);
extern void func_80076EAC(u8 *);
extern void func_800AA658(u8 *, void *);
extern void func_800DB124(s32);
extern void func_800137FC(void);
extern void func_80014384(void);
extern void func_800AB2A4(u8 *, s32, s32, s32, u8 *, s32);
extern s32 func_80076B58(u8 *);
extern void func_80076680(u8 *, u8 *, s32);

static __inline__ void snd_set(u8 *g, s32 h, s32 scale, s32 t, s32 a, s32 b)
{
    func_8001D5D8(g, h, (*(s32 *)(g + 0x68) * scale) >> 15, t, a, b);
}

static __inline__ void snd_fade(u8 *g, s32 h, s32 t, s32 a, s32 b)
{
    func_8001D5D8(g, h, 0, t, a, b);
}

static __inline__ void send_msg(u8 *o, s32 a) { func_800AB2A4(D_800F26E0, D_800F2744, 20, a, o, *(s32 *)(o + 0x5414)); }

static __inline__ void snd_vol(u8 *g, s32 h, s32 scale)
{
    func_8001D640(g, h, (*(s32 *)(g + 0x68) * scale) >> 15);
}

#define W(o) (*(s32 *)(obj + (o)))
#define B(o) (*(u8 *)(obj + (o)))
typedef struct { u8 pad[0x4120]; u8 *slots[8]; } ObjS;
#define SLOT(i) (((ObjS *)obj)->slots[i])

void func_80082870(u8 *obj, Event *evt)
{
    s32 dt = (evt->time - W(0x10)) >> 8;

    {
        static void *const unused_tbl[] = { &&LA, &&LB, &&LC, &&LD, &&LE, &&LF, &&LG, &&LH, &&LI, &&LJ, &&end };
        unsigned int i = evt->type - 1;
        if (i >= 23) goto end;
        goto *D_80070FF0[i];
    }
LA:
    func_800B4794(1);
    func_80073318(obj);
    func_80073D18(obj);
    func_800B4794(0);
    goto end;
LB:
    if (B(0x60F) == 6) {
        s32 v = B(0x615);
        if (v >= 2) {
            if (v >= 5) {
                if (v != 5) goto lb_skip;
                func_800A9BE8(obj + 0x45C, 5);
            } else {
                func_800A9BE8(obj + 0x45C, 15);
            }
            W(0x5424) = 0x6900;
        }
lb_skip:
        B(0x5475) = 0;
        B(0x60F) = 8;
    }
    goto LI2;
LC:
    B(0x610) &= ~(1 << evt->arg);
    func_80072574(obj, dt);
    goto end;
LD:
    {
        u8 *p = evt->ptr;
        u8 s1 = p[0x2DD];
        s32 s0;
        B(0x610) |= 1 << s1;
        if (p[0x1AA] != 4) {
            s0 = evt->arg;
            if (p[0x1AA] == 1) {
                W(0x542C) = s0;
            }
            if (B(0x615) == 3) {
                s32 a = W(0x542C);
                s32 b = W(0x5430);
                s32 r;
                if (a < b || b == -7680) {
                    s32 k;
                    W(0x5430) = a;
                    k = B(0x611) * 8;
                    func_800AAC84(p, obj + (k + 0x61C), obj + (k + 0x624), 14400);
                    r = func_8001D4B8(D_800F1AE0, 217, 0, 1);
                    snd_vol(D_800F1AE0, r, 32767);
                } else {
                    r = func_8001D4B8(D_800F1AE0, 200, 0, 1);
                    snd_vol(D_800F1AE0, r, 32767);
                }
            } else {
                if (B(0x615) == 2) {
                    func_800BBB94(*(s32 *)(p + 0x284));
                }
                func_800742E0(obj, s1 - B(0x611), (f32)s0 / (*(f32 *)0x8007104C) * (*(f32 *)0x80071050));
            }
            if (B(0x60F) < 27) {
                W(0x5424) = 0xF00;
                B(0x60F) = 27;
            }
        }
        if (W(0x5458) == -1) {
            s32 r;
            s32 r2;
            snd_fade(D_800F1AE0, W(0x5450), 90, 1, 0);
            r = func_8001D4B8(D_800F1AE0, 256, 0, -1);
            func_8001D640(D_800F1AE0, r, 0);
            snd_set(D_800F1AE0, r, 21298, 60, 0, 0);
            W(0x5458) = r;
            r2 = func_8001D4B8(D_800F1AE0, 217, 0, 1);
            snd_vol(D_800F1AE0, r2, 32767);
            W(0x5454) = r2;
        }
    }
    goto end;
LE:
    func_800AC25C(obj, 98, 16, 0);
    D_80077740 = ((u8 *)evt)[19];
    func_800A9BE8(obj + 0x45C, 6);
    W(0x5424) = 0;
    B(0x60F) = 36;
    func_80072574(obj, dt);
    goto end;
LF:
    {
        u8 *g = D_800F2AD0;
        func_800BC07C(g, ((u8 *)evt)[17]);
        if (W(0x543C) == 0) {
            u8 f = g[3];
            if (f & 0x10) {
                func_8009C0D8(2, D_800F2AD0[0] >> 5);
            } else if (f & 2) {
                func_8009C0D8(0, D_800F2AD0[0] >> 5);
            } else if (f & 8) {
                func_80074F24(obj);
            }
        } else if (g[3] & 0xA) {
            W(0x5414) = 0;
            func_80073AF0(obj);
        }
    }
    goto LI2;
LG:
    {
        s32 v = evt->arg;
        if (v == 56) {
            B(0x60E) = 0;
            func_80076FA0(obj);
        } else if (v == 55 || v == 7) {
            func_80076EAC(obj);
            func_80073AF0(obj);
        }
    }
    goto end;
LH:
    {
        s32 v = W(0xAC);
        if (v == 1) goto LI2;
        if (v == 0) goto end;
        if (v == 2) goto LH2;
    }
    goto end;
LI:
LI2:
    func_80072574(obj, dt);
    goto end;
LH2:
    if (W(8) == 0) {
        Slot *s = (Slot *)(obj + 0x410C);
        u8 *o = s->obj;
        if (o != 0) {
            W(0x410C) = 0;
            if (s->a != 0) {
                func_800AA658(o, obj + 0x4110);
            }
            if (s->b != 0) {
                func_800AA658(o, obj + 0x4114);
            }
            s->d = 0;
            s->e = 0;
            s->c = 0;
            W(0x410C) = 0;
        }
        func_800DB124(1);
        func_800137FC();
        func_80014384();
        send_msg(obj, W(4));
    }
    goto end;
LJ:
    {
        unsigned int v = evt->arg;
        s8 d;
        s32 c;
        u8 n2;
        s32 base;
        s32 i;
        switch (v) {
        case 1:
            B(0x60C) = func_80076B58(obj);
            func_80076680(obj, SLOT(B(0x60C)), 1);
            break;
        case 2:
            {
                f32 best = (*(f32 *)0x80071054);
                u32 n = B(0x613);
                B(0x60C) = 0;
                for (i = 0; ; i++) {
                    u8 *q;
                    f32 val;
                    { u32 k = (u8)i; if (k >= n) break; q = SLOT(k); }
                    if (q == 0) continue;
                    val = *(f32 *)(q + 0x310);
                    if (!(best < val)) continue;
                    B(0x60C) = i;
                    best = val;
                }
                func_80076680(obj, SLOT(B(0x60C)), 1);
                break;
            }
        case 4:
            {
                u32 r = (D_800F2714 * 16807) & 0x7FFFFFFF;
                s32 n = B(0x613);
                D_800F2714 = r;
                B(0x60C) = (r >> 15) * n >> 16;
            }
            d = 0;
            if (SLOT(B(0x60C)) == 0) {
                do {
                    B(0x60C)++;
                    if (B(0x60C) >= B(0x613)) B(0x60C) = 0;
                } while (SLOT(B(0x60C)) == 0);
                d = 0;
            }
            base = B(0x60C);
            for (;;) {
                {
                    u8 t = SLOT(base + d)[0x1AA];
                    if (!(t != 1)) break;
                }
                c = B(0x60C);
                n2 = B(0x613);
                do {
                    d++;
                    if (c + d >= n2) d = -c;
                    if (d == 0) goto done;
                } while (SLOT(c + d) == 0);
            }
            goto done;
        case 5:
            {
                u32 r = (D_800F2714 * 16807) & 0x7FFFFFFF;
                s32 n = B(0x613);
                D_800F2714 = r;
                B(0x60C) = (r >> 15) * n >> 16;
            }
            d = 0;
            if (SLOT(B(0x60C)) == 0) {
                do {
                    B(0x60C)++;
                    if (B(0x60C) >= B(0x613)) B(0x60C) = 0;
                } while (SLOT(B(0x60C)) == 0);
                d = 0;
            }
            base = B(0x60C);
            for (;;) {
                {
                    u8 t = SLOT(base + d)[0x1AA];
                    if (!(t == 1)) break;
                }
                c = B(0x60C);
                n2 = B(0x613);
                do {
                    d++;
                    if (c + d >= n2) d = -c;
                    if (d == 0) goto done;
                } while (SLOT(c + d) == 0);
            }
        done:
            B(0x60C) += d;
            func_80076680(obj, SLOT(B(0x60C)), 1);
            break;
        }
    }
end:
    W(0x10) = evt->time;
}
