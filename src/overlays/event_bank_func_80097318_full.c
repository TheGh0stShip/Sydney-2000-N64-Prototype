/* Event-bank round/attempt advance handler (link VRAM 0x80071D28), ROM 0x97318..0x9784C. */
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef float f32;

typedef struct {
    s8 slot;
    char pad1[3];
    f32 value;
    s32 pad8;
} RoundEntry;

typedef struct {
    char pad0[0x20];
    u8 kind;
    char pad21[0x1B];
} PlayerEntry;

typedef struct {
    char pad0[0xA10];
    RoundEntry rounds[1];
} GameCtx;

typedef struct {
    PlayerEntry players[1];
} PlayerTbl;

typedef struct {
    char pad0[0x4C];
    s32 w4C;
    s8 b50;
    s8 b51;
    u8 b52;
    char pad53;
    u8 state;
    char pad55[0x17];
    s32 w6C;
    char pad70[0x10];
    s32 w80;
    char pad84[4];
    s32 w88;
    char pad8C[0xC];
    s32 w98;
} SubState;

typedef struct {
    s32 pad0;
    s32 w4;
    s32 pad8;
    s32 padC;
    s32 w10;
} Event;

extern u8 *D_800FC270;
extern char D_800F26E0[];
extern s32 D_800F2744;
extern s32 D_800F13F0;
extern char D_800F1AE0[];
extern char D_80076E50[];
extern void *const D_80071060[];
extern void *const D_80071078[];

extern void func_800A62EC(void *);
extern void func_800AB2A4(void *, s32, s32, void *, s32, s32);
extern void func_80076920(void *);
extern void func_8009C0D8(s32, s32);
extern void func_800B4794(s32);
extern void func_80074664(void *, s32);
extern void func_8000C944(void);
extern void func_800A9B78(void *, s32, s32, s32, s32);
extern void func_8009B80C(void *, s32, s32, s32);
extern void func_800A9BE8(void *, s32);
extern void func_8009BF6C(void *, s32);
extern void func_8009AEC0(s32, void *);
extern void func_800D33A0(void *, void *, s32, s32);
extern void func_8009BB88(s32, s32);
extern void func_800764E0(void *);
extern s32 func_8001D4B8(void *, s32, s32, s32);
extern void func_8001D640(void *, s32, s32);
extern void func_8001D5D8(void *, s32, s32, s32, s32, s32);
extern void func_800768EC(void *, s32, s32, s32);
extern void func_8009B9EC(s32, s32);

#define SUB(o) ((SubState *)((o) + 0x8000))
#define W(o, off) (*(s32 *)((o) + (off)))
#define G(off) (*(u8 *)(D_800FC270 + (off)))
#define GW(off) (*(s32 *)(D_800FC270 + (off)))

static inline s32 mulq15(s32 a, s32 b)
{
    return (a * b) >> 15;
}

void func_80097318(u8 *obj, Event *evt)
{
    SubState *p;
    s32 found = 0;
    s32 done;
    s32 ok;
    s32 k;
    s32 off;
    s32 st;
    char *hb;

    func_800A62EC(obj + 0x1898);
    done = found;
    if (SUB(obj)->w80 != 0) {
        func_800AB2A4(D_800F26E0, evt->w4, 7, obj, 0, 0);
        return;
    }
    p = SUB(obj);
    hb = (char *)0x80100000;
    st = 21;
/* Loop reads D_800FC270 (0x800FC270) via a hoisted 0x80100000 base, as the original did. */
#define D_800FC270 (*(u8 **)(hb - 0x3D90))

    do {
        if (evt->w10 == 0) {
            p->b51++;
        }
        if ((u8)(p->state - 3) < 2) {
            p->b50++;
        }
        ok = 0;
        if (p->state != 4
            || !(((GameCtx *)D_800FC270)->rounds[p->b51].value >= *(f32 *)(D_800FC270 + 0xD10))) {
            if (p->b51 < G(0xA0C)) {
                ok = 1;
            } else {
                p->b51 = 0;
                if (++p->b50 < 3) {
                    ok = 1;
                }
            }
        }
        if (ok) {
            k = ((GameCtx *)D_800FC270)->rounds[p->b51].slot;
            if (k < 8) {
                if (((PlayerTbl *)D_800FC270)->players[k].kind != 2) {
                    goto fail;
                }
                if (G(0xD52) & 2) {
                    goto call;
                }
                goto fail;
            } else if (k == 8) {
                if (!(G(0xD52) & 3)) {
                    goto fail;
                }
            } else {
                continue;
            }
        call:
            func_80076920(obj);
            if (p->b51 == G(0xA0C) - 1) {
                p->b52 = st;
                done = 1;
            }
            continue;
        fail:
            found = 1;
            done = found;
            p->b52 = 0;
        } else {
            if (GW(0xA00) != 5 || (G(0xD52) & 4)) {
                W(obj, 0x7DD8) = 15;
                func_800AB2A4(D_800F26E0, evt->w4, 7, obj, 0, 9);
                done = 1;
            } else {
                done = 1;
                W(obj, 0x7DD8) = 15;
                func_8009C0D8(done, -1);
            }
        }
    } while (!done);
#undef D_800FC270

    if (!found) {
        return;
    }
    func_800B4794(1);
    func_80074664(obj, 0);
    p = (SubState *)0x8000;
    func_8000C944();
    func_800AB2A4(D_800F26E0, D_800F2744, 3, (void *)W(obj, 0x2F50), obj + 0x2F5C, 0);
    ((SubState *)(obj + (s32)p))->w88 = D_800F13F0;
    func_800A9B78(obj + 0x7DE4, W(obj, 0x2F68), 0, 1, 2);
    p = (SubState *)(obj + 0x8000);
    {
        static void *const unused_tbl[] = { &&A0, &&A1, &&A2, &&A3, &&A5 };
        unsigned int s = p->state;
        if (s >= 6) goto A_end;
        goto *D_80071060[s];
    }
A0:
    p = SUB(obj);
    if (p->w4C != 0) {
        func_8009B80C(obj + 0x2B8, 2, -1, 2);
        k = GW(0xA00);
        switch (k) {
        case 6:
            break;
        case 5:
            func_800A9BE8(obj + 0x7DE4, 1);
            p->w6C = 0x9600;
            break;
        default:
            func_800A9BE8(obj + 0x7DE4, 0);
            p->w6C = 0x9600;
            break;
        }
    } else {
        func_800A9BE8(obj + 0x7DE4, 2);
        p->w6C = 23040;
        func_8009BF6C(obj + 0x2B8, W(obj, 0x2F68));
        func_8009AEC0(2, obj + 0x830);
    }
    SUB(obj)->b52 = 1;
    goto A_end;
A1:
    func_800A9BE8(obj + 0x7DE4, 1);
A5:
    SUB(obj)->w6C = 0x9600;
    SUB(obj)->b52 = 1;
    goto A_end;
A2:
    func_800D33A0(obj + 0x2B8, D_80076E50, 1, -1);
A3:
    func_800A9BE8(obj + 0x7DE4, 16);
    SUB(obj)->w6C = 0x12C00;
    SUB(obj)->b52 = 1;
A_end:
    func_800B4794(0);
    p = SUB(obj);
    func_8009BB88(p->state, 1);
    if (p->w4C != 0) {
        func_800764E0(obj);
    }
    {
        static void *const unused_tbl2[] = { &&B0, &&B2, &&B_end };
        unsigned int s = p->state;
        if (s >= 6) goto B_end;
        goto *D_80071078[s];
    }
B0:
    {
        s32 h = func_8001D4B8(D_800F1AE0, 95, 0, -1);
        func_8001D640(D_800F1AE0, h, 0);
        func_8001D5D8(D_800F1AE0, h, mulq15(*(s32 *)(D_800F1AE0 + 0x68), 19660), 45, 0, 0);
        SUB(obj)->w98 = h;
    }
    goto B_end;
B2:
    func_800768EC(obj, 30, 0, 0);
B_end:
    if (SUB(obj)->state != 2 && SUB(obj)->state != 4) {
        func_8009B9EC(11520, 0);
    }
}
