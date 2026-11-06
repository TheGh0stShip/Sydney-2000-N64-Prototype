/* Event-bank main event handler (link VRAM 0x800722B4), ROM 0xA32B4..0xA3938. */
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct {
    s32 type;
    s32 time;
    s32 pad08;
    s32 pad0C;
    s32 arg;
} Event;

typedef struct {
    u8 pad0[2];
    s16 h2;
    s32 w4;
    s32 w8;
} Slot;

typedef struct {
    u8 pad0[0xA00];
    s32 mode;
    u8 padA04[8];
    u8 count;
    u8 padA0D[3];
    Slot slot[8];
} Game;

typedef struct {
    u8 pad0[0x68];
    s32 volume;
} SndBank;

extern void *D_800710B0[];
extern void *D_80071118[];
extern void *D_80071168[];
extern void *D_80071180[];
extern const f32 D_80071248;
extern SndBank D_800F1AE0;
extern char D_800F26E0[];
extern s32 D_800F2744;
extern char D_800F1798[];
extern u8 *D_800FC270;
extern s32 D_800774D0;
extern char D_8007741C[];

extern void func_800B4794(s32);
extern void func_800738A4(u8 *);
extern void func_80074874(u8 *, s32);
extern void func_8000C944(void);
extern void func_800AB2A4(void *, s32, s32, s32, void *, s32);
extern void func_800A9B78(void *, s32, s32, s32, s32);
extern void func_8009BB88(s32, s32);
extern void func_800717A0(u8 *);
extern void func_80076D6C(u8 *, s32, s32);
extern void func_800A2B80(void *);
extern void func_8001D5D8(SndBank *, s32, s32, s32, s32, s32);
extern s32 func_8001D4B8(SndBank *, s32, s32, s32);
extern void func_8001D640(SndBank *, s32, s32);
extern void func_80076E98(u8 *, s32);
extern void func_800D33A0(void *, char *, s32, s32);
extern void func_80076C64(u8 *, s32, s32, s32);
extern void func_800A9BE8(void *, s32);
extern void func_80071A68(u8 *, Event *);
extern void func_80071D00(u8 *, Event *);
extern void func_80072078(u8 *, Event *, s32);
extern void func_80074C58(u8 *, f32);
extern void func_800CEE04(void *);
extern void func_80074E9C(u8 *, s32);
extern void func_80076C98(u8 *);
extern void func_800DA804(s32, s32, void *, s32, s32);
extern void func_80074588(u8 *);
extern void func_800AACB0(void *, u8 *, s32);
extern void func_80072E88(u8 *, s32);
extern void func_800DB124(s32);
extern void func_800137FC(void);
extern void func_80014384(void);

#define W(o) (*(s32 *)(obj + (o)))
#define B(o) (*(u8 *)(obj + (o)))
#define P(o) (*(u8 **)(obj + (o)))

void func_800A32B4(u8 *obj, Event *evt)
{
    s32 dt = (evt->time - W(0x10)) >> 8;
    s32 h;

    {
        static void *const unused_tbl[] = { &&C1, &&C3, &&C5, &&C7, &&C11, &&C12, &&C13, &&C14,
                                            &&C15, &&C21, &&C23, &&C24, &&C25 };
        unsigned int i = evt->type - 1;
        if (i >= 25) goto end;
        goto *D_800710B0[i];
    }
C3:
    func_800B4794(1);
    func_800738A4(obj);
    goto off;
C21:
    func_800B4794(1);
    func_80074874(obj, 0);
    func_8000C944();
    func_800AB2A4(D_800F26E0, D_800F2744, 3, W(0x2F88), obj + 0x2F90, 0);
    func_800A9B78(obj + 0x7AF0, W(0x2FB4), 0, 1, 2);
    func_8009BB88(B(0x7CAF), 1);
    func_800717A0(obj);
off:
    func_800B4794(0);
    goto end;
C11:
    {
        static void *const unused_tbl2[] = { &&D1, &&D2, &&D4, &&D5, &&D7, &&D8 };
        unsigned int i = evt->arg;
        if (i >= 19) goto end;
        goto *D_80071118[i];
    }
D1:
    func_80076D6C(obj, W(0x2FB4), 1);
    goto end;
D2:
    func_80076D6C(obj, W(0x2FB4), 1);
    goto end;
D4:
    func_80076D6C(obj, W(0x2FB4), 1);
    goto end;
D5:
    func_80076D6C(obj, W(0x2FB4), 1);
    goto end;
D7:
    func_80076D6C(obj, W(0x2F88), 1);
    goto end;
D8:
    func_80076D6C(obj, W(0x2F8C), 1);
    goto end;
C12:
    B(0x7CAE) = 4;
    func_800A2B80(obj + 0x33F8);
    {
        static void *const unused_tbl3[] = { &&E0, &&E2 };
        unsigned int i = B(0x7CAF);
        if (i >= 6) goto E2;
        goto *D_80071168[i];
    }
E0:
    {
        SndBank *b = &D_800F1AE0;
        s32 m = 32767;
        s32 l = W(0x7CEC);
        func_8001D5D8(b, l, 0, 270, 1, 0);
        h = func_8001D4B8(b, 96, 0, -1);
        func_8001D640(b, h, 0);
        func_8001D5D8(b, h, (b->volume * m) >> 15, 195, 0, 0);
        W(0x7CF0) = h;
    }
E2:
    func_80076E98(obj, dt);
    goto end;
C14:
    D_800774D0 = evt->arg;
    func_800D33A0(obj + 0x2F0, D_8007741C, 0, -1);
    {
        s32 m = 32767;
        h = func_8001D4B8(&D_800F1AE0, 226, 0, 1);
        func_8001D640(&D_800F1AE0, h, (D_800F1AE0.volume * m) >> 15);
    }
    if (evt->arg != 0) goto end;
    B(0x7CDF) = 1;
    func_80076C64(obj, 180, 0, 0);
    goto end;
C13:
    if (evt->arg != 0) {
        SndBank *b = &D_800F1AE0; s32 m = 32767; s32 hh = func_8001D4B8(b, 181, 0, 1);
        func_8001D640(b, hh, (b->volume * m) >> 15);
    } else {
        SndBank *b = &D_800F1AE0; s32 m = 32767; s32 hh = func_8001D4B8(b, 90, 0, 1);
        func_8001D640(b, hh, (b->volume * m) >> 15);
    }
    func_800A9BE8(obj + 0x7AF0, 9);
    goto end;
C25:
    func_80071A68(obj, evt);
    goto end;
C15:
    if (*(s32 *)(D_800FC270 + 0xA00) != 4) goto end;
    if (B(0x7CDE) != 0) goto end;
    if (B(0x7CAF) == 5) goto end;
    B(0x7CDE) = 1;
    func_80076C64(obj, 550, 0, 0);
    goto end;
C23:
    if (B(0x7CB0) != 4) {
        SndBank *bb = &D_800F1AE0;
        s32 l = W(0x7CF8);
        func_8001D5D8(bb, l, 0, 30, 1, 0);
    }
    if (B(0x7CAF) != 5) {
        u8 *q;
        f32 f;
        *(f32 *)(obj + 0x7CD8) = *(f32 *)(D_800FC270 + *(s8 *)(obj + 0x7CAD) * 12 + 0xA14);
        q = P(0x2FB4);
        f = 0.0f;
        if (q[0x2E4] == 0) {
            f = *(f32 *)(q + 0x34C);
        }
        func_80074C58(obj, f);
    }
    func_800CEE04(obj + 0x74F0);
    W(0x7CC0) = 0x3C00;
    B(0x7CAE) = 9;
    goto end;
C24:
    func_80071D00(obj, evt);
    goto end;
C1:
    func_80072078(obj, evt, dt);
    goto end;
C7:
    {
        static void *const unused_tbl4[] = { &&F7, &&F56, &&Fdef };
        unsigned int i = evt->arg - 7;
        if (i >= 50) goto Fdef;
        goto *D_80071180[i];
    }
F56:
    {
        Game *g;
        u8 a, b;
        *(s8 *)(obj + 0x7CAD) = -1;
        B(0x7CAC) = 0;
        g = (Game *)D_800FC270;
        W(0x7CA8) = 1;
        a = 0;
        if (g->count != 0) {
            f32 neg = *(f32 *)0x80071248;
            Game *gg = g;
            do {
            for (b = 0; b < 3; b++) {
                (*(f32 **)(obj + 0x7CE4))[a * 3 + b] = neg;
            }
            gg->slot[a].w4 = 0;
            gg->slot[a].h2 = 0;
            a++;
            } while (a < gg->count);
        }
        func_800AB2A4(D_800F26E0, D_800F2744, 24, (s32)obj, 0, 0);
        goto end;
    }
F7:
    {
        s32 v = *(s32 *)(D_800FC270 + 0xA00);
        if (v == 4 || v == 0 || v == 1 || v == 2 || v == 3) {
            func_80074E9C(obj, 0);
            B(0x7CAE) = 17;
            func_80076C98(obj);
            func_800DA804(0, 0, D_800F1798, 0, 0);
        }
    }
Fdef:
    func_80074588(obj);
    func_800AACB0(D_800F26E0, obj, 0);
    W(0xAC) = 1;
    goto end;
C5:
    switch (W(0xAC)) {
    case 0:
        func_80072E88(obj, dt);
        break;
    case 1:
        if (W(0x8) == 0) {
            func_800DB124(1);
            func_800137FC();
            func_80014384();
            { s32 t = W(0x4); func_800AB2A4(D_800F26E0, D_800F2744, 20, t, obj, W(0x7AEC)); }
        }
        break;
    }
end:
    W(0x10) = evt->time;
}
