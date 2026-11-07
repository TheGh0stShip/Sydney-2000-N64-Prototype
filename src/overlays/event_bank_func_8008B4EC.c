typedef unsigned char u8;
typedef signed char s8;
typedef struct Snd { char pad[0x68]; int vol; } Snd;
typedef struct GEnt { int i0; int i4; int i8; } GEnt;
typedef struct G {
    char pad0[0x500];
    float f500;
    char pad504[0x52C - 0x504];
    float f52C;
    char pad530[0xA00 - 0x530];
    int kind;
    char padA04[0xA10 - 0xA04];
    GEnt ents[(0xDE8 - 0xA10) / 12];
    float fDE8;
} G;
typedef struct Sub { char pad[0x1AA]; u8 u1AA; } Sub;
typedef struct Rec { int pad[4]; int i10; } Rec;
typedef struct Obj {
    char pad0[0x2B8];
    char unk2B8[0x59DC - 0x2B8];
    Sub *sub;
    char pad59E0[0x67D4 - 0x59E0];
    char unk67D4[0x8414 - 0x67D4];
    s8 s8414;
    s8 s8415;
    u8 u8416;
    u8 u8417;
    char pad8418[0x8428 - 0x8418];
    int t8428;
    char pad842C[0x844C - 0x842C];
    float *tab;
} Obj;
extern G *D_800FC270;
extern Snd D_800F1AE0;
extern int D_800F1270[2];
extern Rec D_800F1280;
extern int D_800F2728;
extern void func_8009BD10(float, int, int, int *, int *);
extern int func_8009BFE8(int, GEnt *, int, float);
extern void func_800D33A0(void *, Rec *, int, int);
extern int func_8001D4B8(Snd *, int, int, int);
extern void func_8001D640(Snd *, int, int);
extern void func_80075C68(Obj *);
extern void func_80096C8C(void *, int, int, float *, int, int);

void func_8008B4EC(Obj *o)
{
    int snd;
    float f;
    int m;
    int k;

    if ((o->t8428 -= 256) > 0) {
        return;
    }
    snd = 192;
    if (o->s8414 < 3) {
        f = o->tab[o->s8415 * 3 + o->s8414];
    } else {
        f = o->tab[o->s8415 * 3 + 2];
    }
    if (0.0f < f) {
        func_8009BD10(f, 2, 2, &D_800F1270[0], &D_800F1270[1]);
        D_800F1280.i10 = 399;
        if (func_8009BFE8(3, &D_800FC270->ents[o->s8415], o->u8417, f)) {
            D_800F1280.i10 = 603;
            snd = 220;
        }
        if (D_800FC270->kind == 4 && D_800FC270->f52C < f) {
            D_800F1280.i10 = 602;
            snd = 220;
        }
        if (D_800FC270->kind == 5 && D_800FC270->fDE8 < f) {
            D_800F1280.i10 = 604;
            snd = 220;
        }
        k = D_800FC270->kind;
        if (k == 4 || k == 0 || k == 1 || k == 2) {
            if (o->u8417 != 4 && D_800FC270->f500 < f) {
                D_800F1280.i10 = 601;
                snd = 220;
            }
        }
    } else {
        D_800F1280.i10 = 595;
        snd = 200;
    }
    func_800D33A0(o->unk2B8, &D_800F1280, 1, -1);
    m = 32767;
    func_8001D640(&D_800F1AE0, func_8001D4B8(&D_800F1AE0, snd, 0, 0), (D_800F1AE0.vol * m) >> 15);
    func_80075C68(o);
    switch (o->u8417) {
    case 5:
        o->u8416 = 13;
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        if (o->sub->u1AA != 3) {
            func_80096C8C(o->unk67D4, 3, D_800FC270->ents[o->s8415].i4, &o->tab[o->s8415 * 3], o->s8414, 0);
        }
        o->u8416 = 13;
        break;
    }
    D_800F2728 = 0;
}
