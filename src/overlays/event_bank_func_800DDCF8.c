typedef unsigned char u8;
typedef int s32;

typedef struct {
    u8 pad[0x68];
    s32 vol;
} Snd;

typedef struct G { u8 pad[2560]; s32 mode; } G;

extern Snd D_800F1AE0;
extern G *D_800FC270;
extern u8 D_800F26E0[];
extern s32 D_800F2744;
extern s32 D_800778BC;
extern u8 D_80077A6C[];

extern s32 func_8001D4B8(Snd *s, s32 a, s32 b, s32 c);
extern void func_8001D640(Snd *s, s32 h, s32 v);
extern void func_800759A0(u8 *p);
extern void func_800D33A0(u8 *p, u8 *s, s32 a, s32 b);
extern void func_800A9BE8(u8 *p, s32 a);
extern void func_800CC418(u8 *p);
extern void func_800767CC(u8 *p);
extern s32 func_80017D54(void);
extern void func_800AB2A4(u8 *a, s32 b, s32 c, s32 d, s32 e, s32 f);

static inline s32 scl(s32 v, s32 m)
{
    return (v * m) >> 15;
}

#define W(o) (*(s32 *)(p + (o)))
#define B(o) (*(u8 *)(p + (o)))

void func_800DDCF8(u8 *p)
{
    s32 h;
    u8 *e;

    W(25284) -= 256;
    if (W(25284) > 0) {
        return;
    }
    h = func_8001D4B8(&D_800F1AE0, 143, 0, 1);
    func_8001D640(&D_800F1AE0, h, scl(D_800F1AE0.vol, 32767));
    B(25383) = 1;
    if (D_800FC270->mode != 6 && B(1557) != 4) {
        func_800759A0(p);
    }
    if (B(1557) != 5) {
        func_800D33A0(p + 12884, D_80077A6C, 0, -1);
    }
    if (B(1557) == 2) {
        func_800A9BE8(p + 1116, 17);
        e = p + 1360;
        e[185] = 1;
        e[184] = 1;
        e[186] = 0;
        e[187] = 0;
        W(25284) = 14848;
        B(1551) = 39;
    } else if (B(1557) == 5 || B(1557) == 1) {
        func_800A9BE8(p + 1116, 14);
        W(25284) = 3840;
        B(1551) = 15;
    } else {
        W(25284) = 7680;
        B(1551) = 37;
        func_800CC418(p + 23124);
    }
    func_800767CC(p);
    if (func_80017D54()) {
        func_800AB2A4(D_800F26E0, D_800F2744, 12, D_800778BC, 0, 0);
    }
}
