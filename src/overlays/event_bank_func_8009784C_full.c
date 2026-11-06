/* Event-bank event dispatcher (link VRAM 0x8007225C), ROM 0x9784C..0x97FFC. */
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    char pad0[0x4C];
    s32 w4C;
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
    char pad7C[4];
    s32 w80;
    s32 w84;
    char pad88[4];
    f32 *w8C;
    f32 f90;
} SubState;

typedef struct {
    s32 w0;
    s32 w4;
    s32 pad8;
    s32 padC;
    s32 w10;
} Event;

typedef struct {
    s8 slot;
    char pad1;
    s16 h2;
    f32 value;
    s32 w8;
} RoundEntry;

typedef struct { char pad[0xA10]; RoundEntry r[1]; } GameCtx;
extern u8 *D_800FC270;
extern char D_800F26E0[];
extern s32 D_800F2744;
extern s32 D_800F2620;
extern s32 D_800F2728;
extern u8 D_800F2AD0[];
extern char D_800F3BC0[];
extern char D_800F1798[];
extern s32 D_80076F88;
extern void *const D_80071090[];
extern void *const D_800710F8[];
extern void *const D_80071110[];

extern void func_800B4794(s32);
extern void func_800739A8(void *);
extern void func_80071D28(void *, Event *);
extern void func_80071BCC(void *, Event *);
extern void func_80074D78(void *);
extern void func_800A9BE8(void *, s32);
extern void func_80071650(void *, Event *);
extern void func_800AAC84(s32, void *, void *, s32);
extern void func_80074B14(void *, f32);
extern void func_800CEE04(void *);
extern void func_800AB2A4(void *, s32, s32, void *, s32, s32);
extern void func_8009BD50(s32);
extern void func_800AC334(void *);
extern void func_800762A8(void *, s32);
extern void func_800BC07C(void *, s32);
extern void func_8009C0D8(s32, s32);
extern void func_800C013C(void *);
extern void func_800D29E0(void *);
extern void func_800AC25C(void *, s32, s32, s32);
extern f32 func_8007AF50(s32);
extern void func_800AACB0(void *, void *, s32);
extern void func_80074A1C(void *);
extern void func_800DA804(s32, s32, void *, s32, s32);
extern void func_800743C0(void *);
extern void func_800730BC(void *, s32);
extern void func_800DB124(s32);
extern void func_800137FC(void);
extern void func_80014384(void);

#define SUB(o) ((SubState *)((o) + 0x8000))
#define W(o, off) (*(s32 *)((o) + (off)))

void func_8009784C(u8 *obj, Event *evt)
{
    SubState *p;
    s32 dt;
    u32 idx;
    f32 f;

    {
        static void *const unused_tbl[] = { &&C1, &&C3, &&C5, &&C7, &&C11, &&C12,
                                            &&C21, &&C23, &&C24, &&C25, &&end };
        s32 i1;
        dt = (evt->w4 - W(obj, 0x10)) >> 8;
        i1 = evt->w0;
        if ((u32)(i1 - 1) >= 25) goto end;
        goto *D_80071090[i1 - 1];
    }
C3:
    if (D_800F2620 != 0) {
        D_80076F88 = 1;
    } else {
        D_80076F88 = 0;
    }
    func_800B4794(1);
    func_800739A8(obj);
    func_800B4794(0);
    goto end;
C21:
    func_80071D28(obj, evt);
    goto end;
C11:
    func_80071BCC(obj, evt);
    goto end;
C12:
    func_80074D78(obj);
    {
        static void *const unused_tbl2[] = { &&S0, &&S2, &&S5 };
        u32 i2 = SUB(obj)->state;
        if (i2 >= 6) goto S5;
        goto *D_800710F8[i2];
    }
S0:
    func_800A9BE8(obj + 0x7DE4, 3);
    goto S5;
S2:
    func_800A9BE8(obj + 0x7DE4, 16);
S5:
    if (SUB(obj)->state == 5) {
        SUB(obj)->w74 = -7680;
    } else {
        SUB(obj)->w74 = 0x1C200;
    }
    SUB(obj)->b52 = 4;
    goto end;
C25:
    func_80071650(obj, evt);
    goto end;
C23:
  {
    SubState *q = SUB(obj);
    if (q->b52 == 18) goto end;
    if (q->state != 5) {
        RoundEntry *r;
        f = *(f32 *)&evt->w10;
        r = (RoundEntry *)(D_800FC270 + 0xA10) + q->b51;
        if (*(s32 *)(W(obj, 0x2F68) + 0x2E8) == 0) {
            f = 0.0f;
        }
        q->f90 = r->value;
        if (r->value < f) {
            func_800AAC84(W(obj, 0x2F68), obj + 0x805C, obj + 0x8064, 7200);
        }
        func_80074B14(obj, f);
    }
  }
    func_800CEE04(obj + 0x38D4);
    SUB(obj)->w6C = 7680;
    SUB(obj)->b52 = 13;
    if (*(s32 *)(W(obj, 0x2F68) + 0x2E8) == 0) {
        func_800AB2A4(D_800F26E0, D_800F2744, 17, (void *)W(obj, 0x2F50), 0, 0);
    }
    goto end;
C24:
    p = SUB(obj);
    p->w4C = 0;
    func_8009BD50(p->state);
    if (p->state == 5) {
        p->state = p->b55;
    }
    {
        u8 *a = obj + 0x7ED8;
        if (*(s32 *)(a + 4) != 0) {
            func_800AC334(a);
        }
    }
    if (p->state == 4 || p->state == 2 || p->state == 3) {
        func_800AB2A4(D_800F26E0, evt->w4, 21, obj, 0, 1);
        func_800762A8(obj, 0);
    } else {
        func_800AB2A4(D_800F26E0, evt->w4, 21, obj, 0, 0);
        func_800762A8(obj, 1);
    }
    SUB(obj)->b52 = 0;
    goto end;
C1:
    func_800BC07C(D_800F2AD0, ((u8 *)evt)[17]);
    if (D_800F2AD0[3] & 0x10) {
        if (SUB(obj)->w84 != 0) goto tick;
        W(obj, 0x7DD8) = 15;
        func_8009C0D8(2, D_800F2AD0[0] >> 5);
        goto tick;
    } else if (D_800F2AD0[3] & 2) {
        if (SUB(obj)->w84 == 1) goto reset;
        W(obj, 0x7DD8) = 15;
        func_8009C0D8(0, D_800F2AD0[0] >> 5);
        goto tick;
    } else if (D_800F2AD0[3] & 8) {
        p = SUB(obj);
        if (p->w84 == 1) {
        reset:
            W(obj, 0x7DD8) = 0;
            func_800AB2A4(D_800F26E0, D_800F2744, 7, obj, 0, 9);
            goto tick;
        }
        if (p->b52 == 18) goto set700;
        if (p->state == 5) {
            p->b52 = 21;
            *(volatile s32 *)&D_800F2728 = 0;
            func_800C013C(D_800F3BC0);
            goto tick;
        }
        if (p->state == 2) {
            p->w6C = 256;
            p->w70 = 256;
            p->b52 = 17;
            p->w78 = 0;
            W(obj, 0x2F48) = 0;
            goto tick;
        }
        if (W(obj, 0x2F68) == 0) goto tick;
        if (*(u8 *)(W(obj, 0x2F68) + 0x1AA) == 1) {
            switch (p->b52) {
            case 1:
            case 2:
                func_800D29E0(obj + 0x2B8);
                func_800D29E0(obj + 0x830);
                func_800D29E0(obj + 0xDA8);
                func_800D29E0(obj + 0x1320);
                func_800AC25C(obj, 93, 17, 0);
                p->w6C = 1792;
                func_800C013C(D_800F3BC0);
                break;
            case 15:
                p->b52 = 16;
                break;
            case 18:
            set700:
                p->w6C = 1792;
                func_800C013C(D_800F3BC0);
                break;
            }
            goto tick;
        }
        p->b55 = p->state;
        p->b52 = 21;
        func_80074B14(obj, func_8007AF50(W(obj, 0x2F68)));
        func_800D29E0(obj + 0x830);
        func_800D29E0(obj + 0xDA8);
        func_800D29E0(obj + 0x1320);
        func_800AACB0(D_800F26E0, obj, 0);
        goto tick;
    }
    goto tick;
C7:
    {
        static void *const unused_tbl3[] = { &&E7, &&E56, &&E_def, &&end };
        u32 i3 = evt->w10 - 7;
        if (i3 >= 50) goto E_def;
        goto *D_80071110[i3];
    }
E56:
    {
        u8 i, j;
        u8 *g;
        SubState *q = SUB(obj);
        q->b51 = -1;
        q->b50 = 0;
        g = D_800FC270;
        q->w4C = 1;
        i = 0;
        if (g[0xA0C] != 0) {
            SubState *r = q;
            f32 m = *(f32 *)0x800711D8;
            u8 *h = g;
            do {
                for (j = 0; j < 3; j++) {
                    r->w8C[i * 3 + j] = m;
                }
                ((GameCtx *)h)->r[i].value = 0.0f;
                ((GameCtx *)h)->r[i].h2 = 0;
                i++;
            } while (i < h[0xA0C]);
        }
    }
    func_800AB2A4(D_800F26E0, D_800F2744, 21, obj, 0, 0);
    goto end;
E7:
    {
        s32 m = *(s32 *)(D_800FC270 + 0xA00);
        if (m == 4 || m == 0 || m == 1 || m == 2) {
            func_800762A8(obj, 1);
            SUB(obj)->b52 = 21;
            func_80074A1C(obj);
            func_800DA804(0, 0, D_800F1798, 0, 0);
            SUB(obj)->w80 = 1;
        }
    }
E_def:
    func_800743C0(obj);
    func_800AACB0(D_800F26E0, obj, 0);
    W(obj, 0xAC) = 1;
    goto end;
C5:
    if (W(obj, 0xAC) == 0) goto tick;
    if (W(obj, 0xAC) == 1) goto C5b;
    goto end;
tick:
    func_800730BC(obj, dt);
    goto end;
C5b:
    {
        if (W(obj, 8) == 0) {
            func_800DB124(1);
            func_800137FC();
            func_80014384();
            { void *a4 = (void *)W(obj, 4); func_800AB2A4(D_800F26E0, D_800F2744, 20, a4, (s32)obj, W(obj, 0x7DD8)); }
        }
    }
end:
    W(obj, 0x10) = evt->w4;
}
