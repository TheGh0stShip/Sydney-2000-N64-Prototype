/* Event-bank state update (link VRAM 0x800730BC), ROM 0x986AC..0x98F98. */
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    char pad0[0x50];
    s8 b50;
    s8 b51;
    u8 b52;
    char pad53;
    u8 state;
    u8 b55;
    char pad56[0x16];
    s32 w6C;
    s32 w70;
    s32 w74;
    s32 w78;
    char pad7C[8];
    s32 w84;
    s32 w88;
    f32 *w8C;
} SubState;

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
} Saved;

typedef struct {
    char pad[0x10];
    s16 off;
    char pad12[2];
    void (*fn)(void *, void *);
} VEntry;

typedef struct {
    char pad[0xA00];
    s32 mode;
    s32 sub;
    char pad8[4];
    u8 count;
    char padD[3];
    struct { s8 slot; char pad1[3]; f32 value; s32 w8; } r[1];
} GameCtx;

extern GameCtx *D_800FC270;
extern char D_800F26E0[];
extern s32 D_800F2744;
extern s32 D_800F2780;
extern s32 D_800F2728;
extern s32 D_800F13F0;
extern char D_800F4D00[];
extern char D_800F1AE0[];
extern char D_800F2AD8[];
extern Saved D_800445F0;
extern f32 D_80071308;
extern void *const D_80071210[];
extern void *const D_80071270[];
extern void *const D_800712D8[];
extern void *const D_800712F0[];

extern void func_800AB2A4(void *, s32, s32, void *, s32, s32);
extern void func_8009B9EC(s32, s32);
extern void func_80072A0C(void *);
extern void func_80072C64(void *);
extern void func_80072DB4(void *);
extern void func_800D29E0(void *);
extern void func_800A9BE8(void *, s32);
extern void func_800755E0(void *);
extern void func_80075F38(void *);
extern void func_8007517C(void *);
extern s32 func_8007B7D4(s32);
extern void func_80076824(void *);
extern void func_8009BD48(s32);
extern void func_80074B14(void *, f32);
extern void func_800ADC54(void *, s32);
extern void func_800ADC38(void *);
extern void func_8001D550(void *, s32);
extern void func_800768EC(void *, s32, s32, s32);
extern void func_800A3394(void *, s32, s32, s32);
extern void func_800A31BC(void *);
extern void func_80008540(void *);
extern void func_80008534(void *);
extern void func_800A62EC(void *);
extern void func_800AC334(void *);
extern void func_800A16D0(void *, s32, s32);
extern void func_800A20C4(void *, s32);
extern void func_800AC25C(void *, s32, s32, s32);
extern void func_8009B0E4(s32, s32, void *, s32, s32, s32, s32);
extern void func_80075248(void *);
extern void func_800762A8(void *, s32);
extern void func_800BC180(void *);
extern void func_800BBD78(void *, s32, s32, void *, s32);
extern void func_800D771C(void *);
extern void func_80097770(void *);

#define SUB(o) ((SubState *)((o) + 0x8000))
#define W(o, off) (*(s32 *)((o) + (off)))

void func_800986AC(u8 *obj, s32 active)
{
    SubState *p;

    if (active == 0) return;

    if (SUB(obj)->w84 != 0) {
        D_800F2780 -= 256;
        if (D_800F2780 <= 0) {
            W(obj, 0x7DD8) = 15;
            func_800AB2A4(D_800F26E0, D_800F2744, 7, obj, 0, 9);
        }
    }
    {
        static void *const unused1[] = { &&A1, &&A2, &&A4, &&A5, &&A9, &&A13, &&A22, &&A23, &&L2 };
        u32 i = SUB(obj)->b52 - 1;
        if (i >= 23) goto L2;
        goto *D_80071210[i];
    }
A1:
    SUB(obj)->w6C -= 256;
    if (SUB(obj)->w6C <= 0) {
        SUB(obj)->b52 = 2;
    }
    goto L2;
A2:
    if (SUB(obj)->state == 2) goto L2;
    if (SUB(obj)->state == 4) goto L2;
    func_8009B9EC(11520, 0);
    goto L2;
A4:
    func_80072A0C(obj);
    goto L2;
A5:
    if (SUB(obj)->w78 == 0) goto L2;
    SUB(obj)->w6C -= 256;
    if (SUB(obj)->w6C > 0) goto L2;
    SUB(obj)->w6C = 0;
    SUB(obj)->w78 = 0;
    W(obj, 0x2F48) = 0;
    func_800D29E0(obj + 0x2B8);
    {
        u8 *q = obj + 0x7DE4;
        if (q[0xE8] == 19) {
            func_800A9BE8(q, 19);
        } else {
            func_800A9BE8(q, 20);
        }
    }
    goto L2;
A22:
    if (SUB(obj)->w78 == 0) goto L2;
    SUB(obj)->w6C -= 256;
    if (SUB(obj)->w6C > 0) goto L2;
    SUB(obj)->w6C = 0;
    SUB(obj)->w78 = 0;
    W(obj, 0x2F48) = 0;
    func_800D29E0(obj + 0x2B8);
    func_800A9BE8(obj + 0x7DE4, 18);
    goto L2;
A23:
    if (SUB(obj)->w78 == 0) goto L2;
    SUB(obj)->w6C -= 256;
    if (SUB(obj)->w6C > 0) goto L2;
    SUB(obj)->w6C = 0;
    SUB(obj)->w78 = 0;
    W(obj, 0x2F48) = 0;
    func_800D29E0(obj + 0x2B8);
    goto L2;
A9:
    if (SUB(obj)->w78 == 0) goto L2;
    SUB(obj)->w6C -= 256;
    if (SUB(obj)->w6C > 0) goto L2;
    SUB(obj)->w6C = 0;
    SUB(obj)->w78 = 0;
    W(obj, 0x2F48) = 0;
    func_800D29E0(obj + 0x2B8);
    func_800A9BE8(obj + 0x7DE4, 13);
    goto L2;
A13:
    func_80072C64(obj);
L2:
    {
        static void *const unused2[] = { &&B15, &&B16, &&B17, &&B18, &&B19, &&B20, &&B21,
                                         &&B24, &&B25, &&end2 };
        u32 i = SUB(obj)->b52;
        if (i >= 26) goto end2;
        goto *D_80071270[i];
    }
B15:
    func_80072DB4(obj);
    goto end2;
B16:
    {
        static void *const unused3[] = { &&S0, &&set17 };
        u32 i = SUB(obj)->state;
        if (i >= 6) goto set17;
        goto *D_800712D8[i];
    }
S0:
    if (D_800FC270->mode == 5 && SUB(obj)->state != 5) {
        func_800755E0(obj);
    } else if (D_800FC270->mode == 4) {
        if (SUB(obj)->state == 5) goto c517;
        func_80075F38(obj);
    } else if (SUB(obj)->state == 5) {
    c517:
        func_8007517C(obj);
    }
    if (*(s32 *)(W(obj, 0x2F68) + 0x2E8) != 0) {
        func_800A9BE8(obj + 0x7DE4, 8);
    } else {
        func_800A9BE8(obj + 0x7DE4, 15);
    }
    p = SUB(obj);
    p->w6C = 0x9600;
    p->w70 = func_8007B7D4(W(obj, 0x2F68)) - 7680;
    if (p->w70 < 7681) {
        p->w70 = p->w6C;
    }
set17:
    SUB(obj)->b52 = 17;
    goto end2;
B17:
    if (SUB(obj)->w70 > 0) {
        SUB(obj)->w70 -= 256;
        if (SUB(obj)->w70 <= 0) {
            func_800D29E0(obj + 0x2B8);
        }
    }
    p = SUB(obj);
    p->w6C -= 256;
    if (p->w6C > 0) goto end2;
    func_80076824(obj);
    {
        static void *const unused4[] = { &&T01, &&T5, &&T2, &&T34, &&clr };
        u32 i = p->state;
        if (i >= 6) goto clr;
        goto *D_800712F0[i];
    }
T01:
    SUB(obj)->b52 = 19;
    goto clr;
T5:
    SUB(obj)->b52 = 20;
    goto clr;
T2:
    SUB(obj)->state = 3;
    SUB(obj)->b52 = 0;
    func_800AB2A4(D_800F26E0, D_800F2744, 24, obj, 0, 1);
    D_800FC270->r[SUB(obj)->b51].value = *(f32 *)0x80071308;
    SUB(obj)->w8C[SUB(obj)->b51 * 3] = *(f32 *)0x80071308;
    SUB(obj)->b50 = -1;
    func_8009BD48(SUB(obj)->state);
    goto clr;
T34:
    func_800AB2A4(D_800F26E0, D_800F2744, 24, obj, 0, 1);
clr:
    *(volatile s32 *)&D_800F2728 = 0;
    goto end2;
B24:
    {
        SubState *q = SUB(obj);
        q->w6C = 0x10E00;
        q->b55 = q->state;
        func_80074B14(obj, 0.0f);
        q->b52 = 25;
    }
    goto end2;
B25:
    p = SUB(obj);
    p->w6C -= 256;
    if (p->w6C >= 0) goto end2;
    func_800D29E0(obj + 0x2B8);
    p->b52 = 21;
    goto end2;
B19:
    {
        u8 *s1;
        VEntry *v;
        u8 t;
        char *d;
        t = SUB(obj)->state;
        SUB(obj)->state = 5;
        SUB(obj)->b55 = t;
        func_80076824(obj);
        d = D_800F4D00;
        s1 = obj + 0x7CF8;
        v = *(VEntry **)(s1 + 0xB4);
        v->fn(s1 + v->off, d);
        func_800ADC54(s1, 1 << *(s32 *)(d + 0xD8));
        s1[0xB0] = 1;
        func_800ADC38(s1);
        func_8001D550(D_800F1AE0, 1);
        func_800768EC(obj, 111, 0, 0);
        func_800A3394(D_800F1AE0, 9830, -1, -1);
        func_800A31BC(D_800F1AE0);
        if (D_800445F0.w8 == 0) {
            D_800445F0.w4 = D_800445F0.w0;
            func_80008540(&D_800445F0);
            D_800445F0.w8 = 1;
        }
    }
B20:
    func_800A62EC(obj + 0x1898);
    func_800AC334(obj + 0x2F6C);
    func_800A16D0(obj + 0x2F6C, 19, W(obj, 0x2F68));
    func_800A20C4(obj + 0x2F6C, 0);
    func_800AB2A4(D_800F26E0, D_800F2744, 3, (void *)W(obj, 0x2F50), (s32)(obj + 0x2F5C), 0);
    func_800AC25C(obj, 93, 18, 0);
    {
        s32 v;
        v = SUB(obj)->w88;
        if (v == 0) v = 1;
        D_800F13F0 = v;
        SUB(obj)->w6C = 0;
        SUB(obj)->b52 = 2;
    }
    goto end2;
B21:
    {
        Saved *sv = &D_800445F0;
        if (sv->w8 == 1) {
            s32 v = sv->w4;
            D_800445F0.w0 = v;
            if (v != 0) {
                func_80008534(sv);
            } else {
                func_80008540(sv);
            }
            sv->w8 = 0;
        }
    }
    {
        u8 *a = obj + 0x7ED8;
        s32 t = *(s32 *)(a + 4);
        *(volatile s32 *)&D_800F2728 = 0;
        if (t != 0) {
            func_800AC334(a);
        }
    }
    {
        SubState *q = SUB(obj);
        GameCtx *ctx = D_800FC270;
        if (q->b51 == ctx->count - 1 && q->state != 3) {
            u32 a1 = (u8)q->b50;
            s32 t0 = a1 >= 2;
            if (ctx->mode == 4) {
                if (ctx->sub == 4) {
                    t0 = 0;
                } else if (ctx->sub == 5) {
                    a1 += 3;
                }
            }
            func_8009B0E4(227, a1 & 0xFF, obj + 0x5284, 2, t0, 0, 0);
            func_80075248(obj);
            func_800A9BE8(obj + 0x7DE4, 10);
            func_800D29E0(obj + 0x2B8);
            SUB(obj)->w6C = 0x1C200;
            func_800762A8(obj, 1);
            func_800BC180(D_800F2AD8);
            func_800BBD78(D_800F2AD8, 13, 1, obj, 2);
            SUB(obj)->b52 = 18;
            goto end2;
        }
        SUB(obj)->b52 = 0;
        func_800AB2A4(D_800F26E0, D_800F2744, 24, obj, 0, 0);
        goto end2;
    }
B18:
    p = SUB(obj);
    p->w6C -= 256;
    if (p->w6C > 0) goto end2;
    func_800D771C(obj + 0x5284);
    p->b52 = 0;
    func_800AB2A4(D_800F26E0, D_800F2744, 24, obj, 0, 0);
end2:
    {
        u8 *e = obj + 0x3DF4;
        if (*(s32 *)(e + 0x148C) != 0) {
            func_80097770(e);
        }
    }
}
