typedef unsigned char u8;
typedef signed int s32;
typedef float f32;

typedef struct {
    union { s32 val; f32 fv; } u;
    u8 pad[2];
    u8 flags;
    u8 pad2;
    s32 pad3;
} Entry;

typedef struct {
    u8 pad0[0xA00];
    s32 mode;
    u8 pad1[0x10];
    Entry e[(0xDFC - 0xA14) / 12 - 1];
    u8 pad2[0xDFC - 0xA14 - ((0xDFC - 0xA14) / 12 - 1) * 12];
    f32 best;
} Big;

extern Big *D_800FC270;
extern u8 D_800F1AE0[];
extern u8 D_800786AC[];
extern s32 D_80078900;

extern void func_8001D5D8(void *, s32, s32, s32, s32, s32);
extern void func_800D0BB8(void *, s32);
extern void func_80077EEC(void *, s32, s32, s32);
extern void func_8007ACFC(s32, s32);
extern void func_800D33A0(void *, void *, s32, s32);
extern s32 func_8001D4B8(void *, s32, s32, s32);
extern void func_8001D640(void *, s32, s32);
extern void func_800A9BE8(void *, s32);
extern void func_80077D80(void *);

#define F15_A (*(f32 *)0x80071140)
#define F15_B (*(f32 *)0x80071144)
#define F30_A (*(f32 *)0x80071148)
#define F30_B (*(f32 *)0x8007114C)
#define F40   (*(f32 *)0x80071150)

static inline s32 scale_volume(s32 x, s32 m)
{
    return (x * m) >> 15;
}

static inline void play_sfx(s32 id)
{
    func_8001D5D8(D_800F1AE0, id, 0, 180, 1, 0);
}

void func_8007C0E0(u8 *a0)
{
    u8 *b = a0 + 0x8000;
    s32 t;
    f32 f;
    Big *g;
    s32 h;

    t = *(s32 *)(b + 0xCA0) - 256;
    *(s32 *)(b + 0xCA0) = t;
    if (t > 0) {
        return;
    }
    *(s32 *)(b + 0xC94) = 12;
    if (b[0xC9D] != 4) {
        play_sfx(*(s32 *)(b + 0x4648));
    }
    func_800D0BB8(a0 + 0x5394, D_800FC270->e[b[0xC98]].u.val);
    f = *(f32 *)(b + 0xCCC);
    *(s32 *)(b + 0xCA0) = 0x10E00;
    if (0.0f <= f && f < F15_A) {
        func_80077EEC(a0, 36, 0, 0);
        func_8007ACFC(*(s32 *)(a0 + 0x536C), 2);
    } else if (*(f32 *)(a0 + 0x8000 + 0xCCC) >= F15_B &&
               *(f32 *)(a0 + 0x8000 + 0xCCC) < F30_A) {
        func_80077EEC(a0, 34, 0, 0);
        func_8007ACFC(*(s32 *)(a0 + 0x536C), 0);
    } else if (*(f32 *)(a0 + 0x8000 + 0xCCC) >= F30_B &&
               *(f32 *)(a0 + 0x8000 + 0xCCC) < F40) {
        func_80077EEC(a0, 33, 0, 0);
        func_8007ACFC(*(s32 *)(a0 + 0x536C), 0);
    } else {
        func_80077EEC(a0, 35, 0, 0);
        func_8007ACFC(*(s32 *)(a0 + 0x536C), 1);
    }
    {
        u8 *c = a0 + 0x8000;
        if (c[0xC99] + 1 == c[0xC9A]) {
            g = D_800FC270;
            if (g->mode == 5) {
                f = g->e[c[0xC98]].u.fv;
                if (g->best < f) {
                    g->best = f;
                    g->e[c[0xC98]].flags |= 2;
                    D_80078900 = *(s32 *)((u8 *)D_800FC270 + c[0xC98] * 12 + 0xA14);
                    func_800D33A0(a0 + 0x2E18, D_800786AC, 1, -1);
                    h = func_8001D4B8(D_800F1AE0, 220, 0, 1);
                    func_8001D640(D_800F1AE0, h,
                                  scale_volume(*(s32 *)(D_800F1AE0 + 0x68), 0x7FFF));
                }
            }
        }
    }
    func_800A9BE8(a0 + 0x86F8, 8);
    func_80077D80(a0);
}
