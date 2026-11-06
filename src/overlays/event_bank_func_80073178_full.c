/* Event-bank round start (link VRAM 0x80073178), ROM 0x764D8..0x767F8. */
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;

typedef struct {
    u8 pad0[0x20];
    u8 kind;
    u8 pad21[60 - 0x21];
} Team;

typedef struct {
    s8 a;
    u8 b;
    s16 c;
    s32 d;
    s8 e;
    u8 pad[3];
} Pick;

typedef struct {
    Team teams[0xA00 / 60];
    u8 padA00[0xA00 - (0xA00 / 60) * 60];
    s32 mode;
    s32 sub;
    u8 padA08[5];
    u8 count;
    u8 padA0E[2];
    Pick picks[(0xD52 - 0xA10) / 12];
    u8 padD4C[0xD52 - 0xA10 - ((0xD52 - 0xA10) / 12) * 12];
    u8 flags;
} Game;

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
} Req;

extern Game *D_800FC270;
extern u8 D_800F2AD8[];
extern u8 D_800F1798[];
extern u8 D_800F26E0[];
extern s32 D_800F272C[];
extern Req D_800445F0;

extern void func_800BC274(u8 *);
extern void func_800BC180(u8 *);
extern void func_80073E64(u8 *);
extern void func_800DA804(s32, s32, u8 *, s32, s32);
extern s32 func_80075E54(u8 *);
extern void func_80076224(u8 *);
extern void func_80075C80(u8 *);
extern void func_80072EE4(u8 *);
extern void func_800735B0(u8 *);
extern void func_8000C944(void);
extern void func_800AB2A4(u8 *, s32, s32, s32, u8 *, s32);
extern void func_800761BC(u8 *);
extern void func_8009BB88(s32, s32);
extern void func_80008534(Req *);
extern void func_80008540(Req *);

void func_80073178(u8 *p)
{

    Pick *e;
    u8 i;
    s16 n; u8 c;
    s16 other;
    Req *q;

    func_800BC274(D_800F2AD8);

    p[0x4BC] = 0;
    for (;;) {
        c = D_800FC270->count;
        n = c;
        e = &D_800FC270->picks[(p + 0x10000)[0xB04] * n];
        for (i = 0; i < n; e++, i++) {
            e->e = -1;
            e->d = 0;
            e->c = -1;
        }
        e = &D_800FC270->picks[(p + 0x10000)[0xB04] * n];
        for (i = other = 0; i < n; i++, e++) {
            if (e->a != 8) {
                if (D_800FC270->teams[e->a].kind == 1) {
                    p[0x4BC]++;
                } else {
                    other++;
                }
            }
        }
        if (p[0x4BC] != 0) {
            goto start;
        }
        if (!(D_800FC270->flags & 2)) {
            if (!(D_800FC270->flags & 1) || other != 0) {
                goto skip;
            }
        }
        func_80073E64(p);
        func_800DA804((p + 0x10000)[0xB04], 1, D_800F1798, 0, 0);
        if (func_80075E54(p) == 0) {
            if (D_800FC270->mode == 4
                && (D_800FC270->sub == 2 || D_800FC270->sub == 4)) {
                func_80076224(p);
                func_80075C80(p);
            } else {
                func_80072EE4(p);
            }
            return;
        }
    }
skip:
    func_800BC180(D_800F2AD8);
start:
    func_800735B0(p);
    func_8000C944();
    func_800AB2A4(D_800F26E0, D_800F272C[6], 3, *(s32 *)(p + 0x10000 + 0xCA0), p + 0x10CA8, 0);
    func_800AB2A4(D_800F26E0, D_800F272C[6], 3, *(s32 *)(p + 0x10000 + 0xCA4), p + 0x10CB4, 0);
    p[0x4BD] = 0;
    (p + 0x10000)[0xD24] = 0;
    (p + 0x10000)[0xD25] = 0;
    (p + 0x10000)[0xB18] = 0;
    (p + 0x10000)[0xB06] = 0;
    *(s32 *)(p + 0x10000 + 0xB1C) = 0;
    func_800761BC(p);
    *(s32 *)(p + 0xAC) = 1;
    if ((p + 0x10000)[0xB04] != 0
        || (D_800FC270->mode == 5 && !(D_800FC270->flags & 4))) {
        *(s32 *)(p + 0x610) = 1;
    }
    func_8009BB88(p[0x614], 1);
    q = &D_800445F0;
    if (q->w8 == 1) {
        if ((D_800445F0.w0 = q->w4) != 0) {
            func_80008534(q);
        } else {
            func_80008540(q);
        }
        q->w8 = 0;
    }
}
