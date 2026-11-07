typedef unsigned char u8;
typedef signed char s8;
typedef struct Snd { char pad[0x68]; int vol; } Snd;
typedef struct EntG { s8 kind; char pad1; short sA12; float f4; int pad8; } EntG;
typedef struct G {
    char pad[0xA00];
    int kind;
    int sub;
    char padA08[0xA0C - 0xA08];
    u8 count;
    char padA0D[3];
    EntG ents[1];
} G;
typedef struct Snd3 { int cur; int next; int pending; } Snd3;
extern G *D_800FC270;
extern Snd D_800F1AE0;
extern Snd3 D_800445F0;
extern char D_800F26E0[];
extern int D_800F2744;
extern char D_800F1798[];
extern int D_800F2620;
extern int D_800776D8;
extern int D_800F2728;
extern int D_800F2724;
extern int D_800F1270;
extern char D_800775A0[];
extern char D_800F2AD8[];
extern void func_80008534();
extern void func_80008540();
extern void func_800137FC();
extern void func_80014384();
extern int func_8001D4B8();
extern void func_8001D5D8();
extern void func_8001D640();
extern void func_80071580();
extern void func_80071AE8();
extern void func_80071C68();
extern void func_80071E3C();
extern void func_800722AC();
extern void func_800723A8();
extern void func_80072490();
extern void func_800727A0();
extern void func_800735F4();
extern void func_80073AE0();
extern void func_80074660();
extern void func_80074CB8();
extern void func_80075050();
extern void func_80076204();
extern void func_80076DF0();
extern void func_8007BB28();
extern void func_8009B0E4();
extern void func_800A6308();
extern void func_800A9BE8();
extern void func_800AACB0();
extern void func_800AB2A4();
extern void func_800AC25C();
extern void func_800B4794();
extern void func_800BBD78();
extern void func_800BC180();
extern void func_800D29E0();
extern void func_800D33A0();
extern void func_800DA804();
extern void func_800DB124();

typedef struct ObjA {
    char pad[0xAC];
    int unkAC;
    char padB0[0x8410 - 0xB0];
    int unk8410;
    u8 unk8414;
    s8 cur;
    char pad8416[0x844C - 0x8416];
    float *slots;
} ObjA;
typedef struct ArgA { int pad[4]; int kind; } ArgA;
void func_8008AB10(ObjA *o, ArgA *a)
{
    u8 i;
    u8 j;
    int k;
    switch (a->kind) {
    case 56:
        o->cur = -1;
        o->unk8414 = 0;
        o->unk8410 = 1;
        for (i = 0; i < D_800FC270->count; i++) {
            for (j = 0; j < 3; j++) {
                o->slots[i * 3 + j] = -1.0f;
            }
            D_800FC270->ents[i].f4 = 0;
            D_800FC270->ents[i].sA12 = 0;
        }
        func_800AB2A4(D_800F26E0, D_800F2744, 21, o, 0, 0);
        return;
    case 8:
    case 15:
        return;
    case 9:
        break;
    case 7:
        k = D_800FC270->kind;
        if (k == 3 || k == 4 || k == 0 || k == 1 || k == 2) {
            func_80075050(o);
            func_80074CB8(o);
            func_800DA804(0, 0, D_800F1798, 0, 0);
        }
        break;
    }
    func_80074660(o);
    func_800AACB0(D_800F26E0, o, 0);
    o->unkAC = 1;
}

typedef struct ObjB {
    int pad0;
    int unk4;
    int unk8;
    int pad0C;
    int unk10;
    char pad14[0xAC - 0x14];
    int unkAC;
    char padB0[0x8260 - 0xB0];
    int unk8260;
} ObjB;
typedef struct ArgB { int kind; int time; } ArgB;
void func_8008ACBC(ObjB *o, ArgB *a)
{
    int d = (a->time - o->unk10) >> 8;
    switch (a->kind) {
    case 3:
        if (D_800F2620 != 0) {
            D_800776D8 = 1;
        } else {
            D_800776D8 = 0;
        }
        func_800B4794(1);
        func_80073AE0(o);
        func_800B4794(0);
        break;
    case 21:
        func_80071580(o, a, d);
        break;
    case 11:
        func_80071AE8(o, a, d);
        break;
    case 12:
        func_80071C68(o, a, d);
        break;
    case 25:
        func_80071E3C(o, a, d);
        break;
    case 23:
        func_800722AC(o);
        break;
    case 24:
        func_800723A8(o, a, d);
        break;
    case 1:
        func_80072490(o, a, d);
        break;
    case 7:
        func_800727A0(o, a, d);
        break;
    case 5:
        switch (o->unkAC) {
        case 0:
            func_800735F4(o, d);
            break;
        case 1:
            if (o->unk8 == 0) {
                func_800DB124(1);
                func_800137FC();
                func_80014384();
                { int k = o->unk4; func_800AB2A4(D_800F26E0, D_800F2744, 20, k, o, o->unk8260); }
            }
            break;
        }
        break;
    }
    o->unk10 = a->time;
}

typedef struct Obj3 {
    char pad[0x2B8];
    char unk2B8[0x2F68 - 0x2B8];
    char unk2F68[0x8264 - 0x2F68];
    char unk8264[0x8414 - 0x8264];
    s8 s8414;
    s8 cur;
    u8 u8416;
    u8 state;
    char pad8418[0x8428 - 0x8418];
    int t8428;
} Obj3;
void func_8008AE90(Obj3 *o)
{
    Snd3 *s = &D_800445F0;
    if (s->pending == 1) {
        if ((D_800445F0.cur = s->next) != 0) {
            func_80008534(s);
            s->pending = 0;
        } else {
            func_80008540(s);
            s->pending = 0;
        }
    }
    D_800F2728 = 0;
    if (o->cur == D_800FC270->count - 1 && o->state != 3) {
        if (D_800FC270->kind == 4 && D_800FC270->sub == 5 && o->s8414 == 2) {
            o->t8428 = 0x38400;
            func_8009B0E4(228, o->s8414, o->unk2F68, 2, 1, 0, 0);
        } else if (D_800FC270->kind == 5 && o->s8414 == 2) {
            o->t8428 = 0x1C200;
            func_8009B0E4(228, o->s8414, o->unk2F68, 2, 1, 0, 0);
        } else {
            o->t8428 = 0x1C200;
            func_8009B0E4(228, o->s8414, o->unk2F68, 2, 0, 0, 0);
        }
        func_80076204(o);
        func_800A9BE8(o->unk8264, 12);
        func_800D29E0(o->unk2B8);
        func_80075050(o);
        func_800BC180(D_800F2AD8);
        func_800BBD78(D_800F2AD8, 13, 1, o, 2);
        func_800BBD78(D_800F2AD8, 12, 1, o, 2);
        o->u8416 = 15;
        return;
    }
    o->u8416 = 0;
    func_800AB2A4(D_800F26E0, D_800F2744, 24, o, 0, 0);
}

typedef struct ObjD {
    char pad[0x2B8];
    char unk2B8[0x2F48 - 0x2B8];
    int unk2F48;
    char pad2F4C[0x67C8 - 0x2F4C];
    int timer;
    char pad67CC[0x8416 - 0x67CC];
    u8 unk8416;
    char pad8417[0x8428 - 0x8417];
    int unk8428;
    char pad842C[0x843C - 0x842C];
    int unk843C;
} ObjD;
void func_8008B0C0(ObjD *o, int *out)
{
    int prev;
    int cur;
    int m;
    cur = 256;
    *out = 0;
    if (o->unk843C != 0) {
        o->unk8428 -= 256;
        if (o->unk8428 <= 0) {
            o->unk8428 = 0;
            o->unk843C = 0;
            o->unk2F48 = 0;
            func_800D29E0(o->unk2B8);
        }
        return;
    }
    prev = (float)o->timer / 30.0f * 0.00390625f;
    if (D_800F2728 == 0) {
        D_800F2724 = 1;
    }
    if (prev < 0) {
        cur = 0;
    }
    o->timer -= cur;
    cur = (float)o->timer / 30.0f * 0.00390625f;
    if (cur >= 0 && cur < 6) {
        if (prev != cur) {
            D_800F1270 = cur;
            if (cur == 5) {
                func_800D33A0(o->unk2B8, D_800775A0, 1, -1);
            } else {
                func_800D33A0(o->unk2B8, D_800775A0, 0, -1);
            }
            m = 32767;
            func_8001D640(&D_800F1AE0, func_8001D4B8(&D_800F1AE0, 226, 0, 0), (D_800F1AE0.vol * m) >> 15);
        }
        if (prev > 0 && cur <= 0) {
            o->timer = 0;
            func_80076DF0(o, 201, 0, 0);
            func_800AC25C(o, 94, 17, 1);
            o->unk8416 = 19;
        }
    }
}

typedef struct SubE { char pad[0x2E8]; int i2E8; } SubE;
typedef struct ObjE {
    char pad[0x1898];
    char unk1898[0x59DC - 0x1898];
    SubE *sub;
    char pad59E0[0x5F2C - 0x59E0];
    unsigned int i5F2C;
    char pad5F30[0x64C8 - 0x5F30];
    float f64C8;
    char pad64CC[0x8264 - 0x64CC];
    char unk8264[0x8416 - 0x8264];
    u8 u8416;
    u8 state;
    char pad8418[0x8428 - 0x8418];
    int t8428;
    int t842C;
    char pad8430[0x8438 - 0x8430];
    int h8438;
} ObjE;

static __inline__ int func_ok(ObjE *o)
{
    return o->sub->i2E8 != 0 && o->i5F2C != 0;
}

void func_8008B274(ObjE *o, int *out)
{
    int id;
    int m;
    float f;

    *out = 0;
    if (o->t842C > 0) {
        if ((o->t842C -= 256) <= 0) {
            o->t842C = 0;
            if (func_ok(o)) {
                int h;
                f = o->f64C8;
                if (2621.35986f < f) {
                    id = 115;
                } else if (1966.0199f < f) {
                    id = 113;
                } else {
                    id = 114;
                }
                h = func_8001D4B8(&D_800F1AE0, id, 0, 0);
                m = 32767;
                func_8001D640(&D_800F1AE0, h, (D_800F1AE0.vol * m) >> 15);
                h = func_8001D4B8(&D_800F1AE0, 112, 0, -1);
                func_8001D640(&D_800F1AE0, h, 0);
                func_8001D5D8(&D_800F1AE0, h, (D_800F1AE0.vol * m) >> 15, 30, 0, 0);
                o->h8438 = h;
                func_800A6308(o->unk1898);
            } else {
                int m2;
                int h;
                h = func_8001D4B8(&D_800F1AE0, 131, 0, 0);
                func_8001D640(&D_800F1AE0, h, 0);
                m2 = 32767;
                func_8001D5D8(&D_800F1AE0, h, (D_800F1AE0.vol * m2) >> 15, 45, 0, 0);
                o->h8438 = h;
            }
        }
    }
    if ((o->t8428 -= 256) <= 0) {
        switch (o->state) {
        case 0:
        case 1:
        case 3:
        case 4:
        case 5:
            if (func_ok(o)) {
                o->t8428 = 30720;
                func_8007BB28(o->sub);
                func_800A9BE8(o->unk8264, 18);
            } else {
                o->t8428 = 15360;
            }
            o->u8416 = 12;
            break;
        case 2:
            o->t8428 = 15360;
            o->u8416 = 14;
            break;
        }
    }
}
