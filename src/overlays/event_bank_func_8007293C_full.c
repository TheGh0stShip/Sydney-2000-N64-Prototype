typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} SndState;

typedef struct {
    u8 pad0[0x68];
    s32 volume;
} Bank;

typedef struct {
    u8 pad0[0x18];
    s32 id;
} EvCtx;

typedef struct {
    s16 off;
    s16 pad;
    void (*fn)(void *, u8 *);
} Thunk;

typedef struct {
    u8 pad0[0x10];
    Thunk t10;
} VT;

typedef float f32;

typedef struct {
    char pad0[0x2F4];
    f32 f2F4;
    char pad2F8[0x3AC - 0x2F8];
    u8 b3AC;
} Q;

typedef struct {
    char pad0[4];
    f32 v;
    char pad8[4];
} Elem;

typedef struct {
    char pad0[0x504];
    f32 f504;
    char pad508[0x530 - 0x508];
    f32 f530;
    char pad534[0xA00 - 0x534];
    int mode;
    char padA04[0xA10 - 0xA04];
    Elem elems[82];
    char padDE8[4];
    f32 fDEC;
} G;

typedef struct {
    char pad0[0x10];
    int x10;
} Obj1280;

typedef struct {
    char pad0[0x18D0];
    char x18D0[0x2F88 - 0x18D0];
    int i2F88;
    char pad2F8C[0x2FA8 - 0x2F8C];
    char x2FA8[0x2FB4 - 0x2FA8];
    Q *p2FB4;
    char pad2FB8[0x33F8 - 0x2FB8];
    char x33F8[0x7AF0 - 0x33F8];
    char x7AF0[0x7CAC - 0x7AF0];
    s8 col;
    s8 row;
    u8 phase;
    u8 state;
    u8 b7CB0;
    char pad7CB1[0x7CC0 - 0x7CB1];
    int timer;
    char pad7CC4[0x7CD4 - 0x7CC4];
    u8 b7CD4;
    char pad7CD5[0x7CDF - 0x7CD5];
    u8 b7CDF;
    char pad7CE0[4];
    f32 *tbl;
    char pad7CE8[0x7CF0 - 0x7CE8];
    int i7CF0;
    char pad7CF4[0x7CF8 - 0x7CF4];
    int i7CF8;
    int i7CFC;
    char pad7D00[0x7D04 - 0x7D00];
    int i7D04;
} S;

extern u8 *D_800FC270;
extern SndState D_800445F0;
extern Bank D_800F1AE0;
extern EvCtx D_800F272C;
extern volatile s32 D_800F2728;
extern s32 D_800F2780;
extern s32 D_800F13F0;
extern u8 D_800F26E0[];
extern u8 D_800F2AD8[];
extern Obj1280 D_800F1280;
extern u8 D_800F4D00[];

extern void func_80008534(SndState *);
extern void func_80008540(SndState *);
extern s32 func_8001D4B8(Bank *, s32, s32, s32);
extern void func_8001D640(Bank *, s32, s32);
extern void func_8001D680(Bank *, s32);
extern void func_80074E9C(u8 *, s32);
extern void func_80075244(u8 *);
extern void func_80075420(u8 *);
extern void func_8007572C(u8 *);
extern void func_80076510(u8 *);
extern void func_800761CC(u8 *);
extern void func_80076B28(u8 *);
extern void func_80076C64(u8 *, s32, s32, s32);
extern void func_80076E18(u8 *);
extern void func_8007B9E8(u8 *);
extern void func_80096C8C(u8 *, s32, f32, s32, s32, s32);
extern void func_80097770(u8 *);
extern void func_8009B0E4(s32, u8, u8 *, s32, u8, s32, s32);
extern void func_8009BB88(s32, s32);
extern void func_8009BD48(s32);
extern void func_800A294C(u8 *, s32);
extern void func_800A62EC(u8 *);
extern void func_800A9BE8(u8 *, s32);
extern void func_800AB2A4(u8 *, s32, s32, void *, s32, s32);
extern void func_800AC334(u8 *);
extern void func_800ADC38(u8 *);
extern void func_800ADC54(u8 *, s32);
extern void func_800B31EC(s32);
extern void func_800BBD78(u8 *, s32, s32, u8 *, s32);
extern void func_800BC180(u8 *);
extern void func_800D29E0(u8 *);
extern void func_800D33A0(u8 *, u8 *, s32, s32);
extern void func_800D771C(u8 *);

extern int D_800F1270[];
#define GP ((G *)D_800FC270)
void func_8001D5D8(Bank *, int, int, int, int, int);
void func_8009BD10(f32, int, int, int *, int *);
int func_8009BFE8(int, Elem *, int, f32);
void func_800A6308(void *);
void func_80075E1C(S *, f32);

#define B(o) (*(u8 *)(obj + (o)))
#define SB(o) (*(s8 *)(obj + (o)))
#define W(o) (*(s32 *)(obj + (o)))
#define GW(o) (*(s32 *)(D_800FC270 + (o)))
#define SLOT(i) ((i) * 12)

typedef struct {
    float v;
    s32 b;
    s32 c;
} Ent12;

#define GS(i) (GP->elems[i])
#define LS(i) (((Ent12 *)W(0x7CE4))[i])

static __inline__ s32 scale(s32 v, s32 k)
{
    return (v * k) >> 15;
}

static __inline__ int scalevol(int pct) {
    return (D_800F1AE0.volume * pct) >> 15;
}

static __inline__ void sndplay(S *s, int id, int pct) {
    int h = func_8001D4B8(&D_800F1AE0, id, 0, 1);
    func_8001D640(&D_800F1AE0, h, (D_800F1AE0.volume * pct) >> 15);
    s->i7CFC = h;
}

static __inline__ void sndfade(int h, int pct) {
    func_8001D5D8(&D_800F1AE0, h, (D_800F1AE0.volume * pct) >> 15, 60, 0, 0);
}

void func_8007293C(S *s, int arg1)
{
    f32 f;
    int id;
    int idx;
    int h;
    int h2;
    Q *q;

    func_800A294C((u8 *)s->x33F8, (s32)s->p2FB4);
    s->timer -= 256;
    if (s->timer > 0) {
        return;
    }
    switch (s->state) {
    case 0:
    case 1:
    case 3:
    case 4:
        h = s->row;
        s->i7D04 = 192;
        idx = h * 3;
        {
            int o4 = idx * 4;
            if (s->col < 3) {
                f = s->tbl[idx + s->col];
            } else {
                f = *(f32 *)((u8 *)s->tbl + (o4 + 8));
            }
        }
        s->b7CD4 = 0;
        if (f > 0.0f) {
            s->timer = 19200;
            func_800A9BE8((u8 *)s->x7AF0, 12);
            sndfade(s->i7CF0, 19660);
            s->phase = 10;
            func_800AB2A4(D_800F26E0, D_800F272C.id, 12, (void *)s->i2F88, (s32)s->x2FA8, 4);
            func_800AB2A4(D_800F26E0, D_800F272C.id + 256, 15, (void *)s->i2F88, (s32)s->x2FA8, 0);
            func_8009BD10(f, 2, 2, D_800F1270, D_800F1270 + 1);
            D_800F1280.x10 = 399;
            if (func_8009BFE8(4, &GP->elems[s->row], s->state, f)) {
                D_800F1280.x10 = 603;
                s->i7D04 = 220;
            }
            if (GP->mode == 4 && GP->f530 < f) {
                D_800F1280.x10 = 602;
                s->i7D04 = 220;
            }
            if (GP->mode == 5 && GP->fDEC < f) {
                D_800F1280.x10 = 604;
                s->i7D04 = 220;
            }
            if ((GP->mode == 4 || GP->mode == 0 || GP->mode == 1 ||
                 GP->mode == 2) &&
                s->state != 4 && GP->f504 < f) {
                D_800F1280.x10 = 601;
                s->i7D04 = 220;
            }
            if (s->b7CB0 != 4) {
                if (f > 18.0f) {
                    sndplay(s, 115, 32767);
                } else if (f > 15.0f) {
                    sndplay(s, 113, 32767);
                } else {
                    sndplay(s, 114, 32767);
                }
                h2 = func_8001D4B8(&D_800F1AE0, 111, 0, -1);
                func_8001D640(&D_800F1AE0, h2, 0);
                sndfade(h2, 32767);
                s->i7CF8 = h2;
                func_800A6308(s->x18D0);
            }
            if (GP->mode == 4 && f > 0.0f) {
                func_80075E1C(s, f);
            }
        } else {
            sndfade(s->i7CF0, 6553);
            s->timer = 0x9600;
            s->phase = 11;
            func_800A9BE8((u8 *)s->x7AF0, 5);
            D_800F1280.x10 = 596;
            s->i7D04 = 200;
            if (s->state == 5) {
                return;
            }
            if (s->b7CDF != 0) {
                return;
            }
            if (GP->mode != 4) {
                func_80076C64((u8 *)s, 533, 0, 0);
            } else {
                q = s->p2FB4;
                if (q->f2F4 < 0.8f || q->b3AC == 0) {
                    func_80076C64((u8 *)s, 471, 0, 0);
                } else if (q->f2F4 < 0.9f) {
                    func_80076C64((u8 *)s, 533, 0, 0);
                } else if (q->f2F4 < 1.0f) {
                    func_80076C64((u8 *)s, 473, 0, 0);
                } else {
                    func_80076C64((u8 *)s, 472, 0, 0);
                }
            }
        }
        break;
    case 2:
    case 5:
        s->timer = 15360;
        s->phase = 13;
        break;
    }
}

void func_80072E88(u8 *obj, s32 arg1)
{
    float fa;
    float fb;
    s32 t;
    SndState *ss;
    s32 c;
    u8 flag;

    if (arg1 == 0) {
        return;
    }
    {
    s32 on = W(0x7CD0);
    fa = fb = 1.5707964f;
    if (on != 0) {
        if ((D_800F2780 -= 0x100) <= 0) {
            W(0x7AEC) = 15;
            func_800AB2A4(D_800F26E0, D_800F272C.id, 7, obj, 0, 9);
        }
    }
    }
    switch (B(0x7CAE)) {
    case 1:
        if ((W(0x7CC0) -= 0x100) > 0) break;
        t = D_800F13F0;
        B(0x7CAE) = 2;
        B(0x7CDF) = 0;
        W(0x7CE0) = t;
        break;
    case 5:
        func_800A294C(obj + 0x33F8, W(0x2FB4));
    case 4:
        if (W(0x7CC8) == 0) break;
        if ((W(0x7CC0) -= 0x100) > 0) break;
        W(0x7CC0) = 0;
        W(0x7CC8) = 0;
        W(0x2F80) = 0;
        func_800D29E0(obj + 0x2F0);
        break;
    case 9:
        func_8007293C((S *)obj, arg1);
        break;
    case 10:
        if ((W(0x7CC0) -= 0x100) > 0) break;
        func_800A9BE8(obj + 0x7AF0, 5);
        func_800AB2A4(D_800F26E0, D_800F272C.id, 0x19, *(u8 **)(obj + 0x2FB4), 0, 0);
        W(0x7CC0) = 0x9600;
        B(0x7CAE) = 11;
        break;
    case 11:
        if ((W(0x7CC0) -= 0x100) > 0) break;
        func_800D33A0(obj + 0x2F0, (u8 *)&D_800F1280, 1, -1);
        t = func_8001D4B8(&D_800F1AE0, W(0x7D04), 0, 1);
        func_8001D640(&D_800F1AE0, t, scale(D_800F1AE0.volume, 0x7FFF));
        if (W(0x7D04) == 0xDC && GW(0xA00) == 5) {
            func_80076C64(obj, 0x3F, 0, 0);
        }
        func_800B31EC(0);
        switch (B(0x7CAF)) {
        case 5:
            B(0x7CAE) = 12;
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            if ((*(u8 **)(obj + 0x2FB4))[0x1AA] != 3) {
                func_80096C8C(obj + 0x35EC, 4,
                              GS(SB(0x7CAD)).v,
                              (s32)&LS(SB(0x7CAD)), SB(0x7CAC), W(0x2FB8));
            }
            B(0x7CAE) = 12;
            D_800F2728 = 0;
            func_800BC180(D_800F2AD8);
            func_800BBD78(D_800F2AD8, 13, 1, obj, 2);
            break;
        }
        break;
    case 12:
        switch (B(0x7CAF)) {
        case 0:
        case 1:
        case 3:
        case 4:
        case 5:
            W(0x7CC0) = 0x9600;
            {
            u8 *g = D_800FC270;
            W(0x7CC4) = 0x7800;
            if (*(s32 *)(g + 0xA00) == 5 && B(0x7CAF) != 5) {
                func_80076B28(obj);
            } else if (GW(0xA00) == 4 && B(0x7CAF) != 5) {
                func_800761CC(obj);
            }
            }
            break;
        case 2:
            break;
        }
        B(0x7CAE) = 13;
        break;
    case 13:
        if (W(0x7CC4) > 0) {
            if ((W(0x7CC4) -= 0x100) <= 0) {
                func_800D29E0(obj + 0x2F0);
            }
        }
        if ((W(0x7CC0) -= 0x100) > 0) break;
        func_80076E18(obj);
        switch (B(0x7CAF)) {
        case 0:
        case 1:
            B(0x7CAE) = 15;
            break;
        case 5:
            B(0x7CAE) = 16;
            break;
        case 2:
            B(0x7CAF) = 3;
            B(0x7CAE) = 0;
            func_800AB2A4(D_800F26E0, D_800F272C.id, 0x18, obj, 0, 1);
            GS(SB(0x7CAD)).v = -1.0f;
            LS(SB(0x7CAD)).v = -1.0f;
            SB(0x7CAC) = -1;
            func_8009BD48(B(0x7CAF));
            break;
        case 4:
            if (GS(SB(0x7CAD)).v >= *(float *)(D_800FC270 + 0xD10)) {
                W(0x7AEC) = 15;
                func_800AB2A4(D_800F26E0, D_800F272C.id, 7, obj, 0, 9);
                break;
            }
        case 3:
            func_800AB2A4(D_800F26E0, D_800F272C.id, 0x18, obj, 0, 1);
            break;
        }
        D_800F2728 = 0;
        break;
    case 15:
        ss = &D_800445F0;
        if (ss->f8 == 0) {
            ss->f4 = ss->f0;
            func_80008540(ss);
            ss->f8 = 1;
        }
        c = B(0x7CAF);
        B(0x7CAF) = 5;
        B(0x7CB0) = c;
        func_80076E18(obj);
        if (B(0x7CB0) != 4) {
            if (W(0x7CFC) != -1) {
                func_8001D680(&D_800F1AE0, W(0x7CFC));
                W(0x7CFC) = -1;
            }
            if (W(0x7CF8) != -1) {
                func_8001D680(&D_800F1AE0, W(0x7CF8));
                W(0x7CF8) = -1;
            }
        }
        if (B(0x7CDF) != 0) {
            B(0x7CAE) = 17;
            break;
        }
        {
            u8 *q = D_800F4D00;
            u8 *p = obj + 0x7A10;
            VT *vt = *(VT **)(p + 0xB4);
            vt->t10.fn(p + vt->t10.off, q);
            func_800ADC54(p, 1 << *(s32 *)(q + 0xD8));
            p[0xB0] = 1;
            func_800ADC38(p);
        }
        B(0x7CDC) = 0;
        B(0x7CDD) = 0;
    case 16:
        func_8009BB88(B(0x7CAF), 1);
        if ((W(0x7CDC) & 0xFFFF0000) == 0) {
            func_80076C64(obj, 0x65, 0xF00, 0x1E00);
        }
        func_800A62EC(obj + 0x18D0);
        func_800A9BE8(obj + 0x7AF0, 7);
        func_800AB2A4(D_800F26E0, D_800F272C.id, 3, *(u8 **)(obj + 0x2F88), (s32)(obj + 0x2F90), *(s32 *)&fa);
        func_800AB2A4(D_800F26E0, D_800F272C.id, 3, *(u8 **)(obj + 0x2F8C), (s32)(obj + 0x2F9C), *(s32 *)&fb);
        func_8007B9E8(*(u8 **)(obj + 0x2FB4));
        t = W(0x7CE0);
        if (t == 0) {
            t = 1;
        }
        D_800F13F0 = t;
        W(0x7CC0) = 0;
        if (B(0x7CDC) == 0) {
            func_80076510(obj);
            B(0x7CDC) = 1;
        } else if (B(0x7CDD) == 0) {
            B(0x7CDD) = 1;
            if (W(0x7D04) != 0xC8) {
                u8 b = B(0x7D0C);
                if (b < 5) {
                    func_80076C64(obj, 0x21A, 0, 0x12C00);
                } else if (b < 9) {
                    func_80076C64(obj, 0x219, 0, 0x12C00);
                } else if (b < 15) {
                    func_80076C64(obj, 0x21C, 0, 0x12C00);
                } else {
                    func_80076C64(obj, 0x21B, 0, 0x12C00);
                }
            }
        }
        B(0x7CAE) = 2;
        break;
    case 17:
        ss = &D_800445F0;
        if (ss->f8 == 1) {
            ss->f0 = ss->f4;
            if (ss->f0 != 0) {
                func_80008534(ss);
            } else {
                func_80008540(ss);
            }
            ss->f8 = 0;
        }
        D_800F2728 = 0;
        if (B(0x7CB0) != 4) {
            if (W(0x7CFC) != -1) {
                func_8001D680(&D_800F1AE0, W(0x7CFC));
                W(0x7CFC) = -1;
            }
            if (W(0x7CF8) != -1) {
                func_8001D680(&D_800F1AE0, W(0x7CF8));
                W(0x7CF8) = -1;
            }
        }
        {
            u8 *p = obj + 0x7BE4;
            if (*(s32 *)(p + 4) != 0) {
                func_800AC334(p);
            }
        }
        if (SB(0x7CAD) == D_800FC270[0xA0C] - 1) {
            u8 k = SB(0x7CAC);
            flag = SB(0x7CAC) >= 2;
            if (flag) {
                switch (GW(0xA00)) {
                case 5:
                    func_8007572C(obj);
                    break;
                case 0:
                case 1:
                case 2:
                case 3:
                    func_80075244(obj);
                    break;
                case 4:
                    func_80075420(obj);
                    break;
                }
            } else {
                func_80076C64(obj, 0x6F, 0, 0);
            }
            if (GW(0xA00) == 4) {
                if (GW(0xA04) != 5) {
                    flag = 0;
                } else {
                    k += 3;
                }
            }
            func_800D29E0(obj + 0x2F0);
            func_800D29E0(obj + 0x868);
            func_800D29E0(obj + 0xDE0);
            func_800D29E0(obj + 0x1358);
            func_8009B0E4(0xE5, k, obj + 0x4A7C, 2, flag, 0, 0);
            func_800A9BE8(obj + 0x7AF0, 6);
            func_800D29E0(obj + 0x2F0);
            if (B(0x7CB0) != 4) {
                func_8001D680(&D_800F1AE0, W(0x7CF8));
            }
            if (SB(0x7CAC) == 2) {
                W(0x7CC0) = 0x70800;
            } else {
                W(0x7CC0) = 0x12C00;
            }
            func_80074E9C(obj, 0);
            func_800BC180(D_800F2AD8);
            func_800BBD78(D_800F2AD8, 13, 1, obj, 2);
            B(0x7CAE) = 14;
            break;
        }
        B(0x7CAE) = 0;
        func_800AB2A4(D_800F26E0, D_800F272C.id, 0x18, obj, 0, 0);
        break;
    case 14:
        if ((W(0x7CC0) -= 0x100) > 0) break;
        func_800D771C(obj + 0x4A7C);
        B(0x7CAE) = 0;
        func_800AB2A4(D_800F26E0, D_800F272C.id, 0x18, obj, 0, 0);
        break;
    case 0:
        break;
    }
    {
        u8 *p = obj + 0x35EC;
        if (*(s32 *)(p + 0x148C) != 0) {
            func_80097770(p);
        }
    }
}
