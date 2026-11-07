typedef unsigned char u8;
typedef signed char s8;
typedef struct P { char pad[744]; int w2E8; } P;
typedef struct M { char pad[4]; void *w4; char p[16 - 8]; int w16; } M;
typedef struct A { char pad[104]; int w104; } A;
typedef struct Ent { char pad[16]; u8 b20; char p[60 - 17]; } Ent;
typedef struct Tb { s8 c0; char p[3]; float f4; char p2[4]; } Tb;
typedef struct G {
    char pad0[16];
    Ent ent[8];
    char p1[2560 - 16 - 480];
    int wA00;
    char p2[2572 - 2564];
    u8 nA0C;
    char p3[3];
    Tb tab[64];
    char p4[3344 - 2576 - 768];
    float fD10;
    char p5[3410 - 3348];
    u8 bD52;
} G;
typedef struct S {
    char pad[696];
    char x2B8[2096 - 696];
    char x830[6296 - 2096];
    char x1898[12112 - 6296];
    int w2F50;
    char p1b[12124 - 12116];
    char x2F5C[23004 - 12124];
    P *p59DC;
    char p3[0x8260 - 23008];
    int w8260;
    char x8264[0x8410 - 0x8264];
    int w8410;
    u8 b8414;
    u8 b8415;
    u8 b8416;
    u8 b8417;
    char p5[0x8428 - 0x8418];
    int w8428;
    int w842C;
    int w8430;
    char p6[0x8448 - 0x8434];
    int w8448;
} S;
extern G *D_800FC270;
extern int D_800F13F0;
extern char D_800F26E0[];
extern char *D_800F2744;
extern char D_800775C8[];
extern A D_800F1AE0;
extern void func_800AB2A4();
extern void func_800A62EC(void *);
extern void func_80076F1C(S *);
extern void func_8009C0D8(int, int);
extern void func_800B4794(int);
extern void func_8007492C(S *, int);
extern void func_8000C944(void);
extern void func_800A9B78(void *, P *, int, int, int);
extern void func_8009B80C(void *, int, int, int);
extern void func_800A9BE8(void *, int);
extern void func_8009BF6C(void *, P *);
extern void func_8009AEC0(int, void *);
extern void func_800D33A0(void *, void *, int, int);
extern void func_8009BB88(int, int);
extern void func_80075274(S *);
extern int func_8001D4B8(A *, int, int, int);
extern void func_8001D640(A *, int, int);
extern void func_8001D5D8(A *, int, int, int, int, int);

void func_800898F0(S *s, M *m)
{
    int go;
    int done;
    int ok;
    int t;
    int idx;
    int r;
    int k;

    go = 0;
    done = go;
    func_800A62EC(s->x1898);
    while (1) {
        if (done) break;
        if (m->w16 == 0) s->b8415++;
        if (s->b8417 == 3 || s->b8417 == 4) s->b8414++;
        ok = 0;
        if (s->b8417 == 4 && D_800FC270->tab[(s8)s->b8415].f4 >= D_800FC270->fD10) {
        } else if ((s8)s->b8415 < D_800FC270->nA0C) {
            ok = 1;
        } else {
            s->b8415 = 0;
            s->b8414++;
            if ((s8)s->b8414 < 3) ok = 1;
        }
        if (ok) {
            idx = D_800FC270->tab[(s8)s->b8415].c0;
            if (idx < 8) t = D_800FC270->ent[idx].b20;
            else t = 3;
            if (t == 1) {
                go = 1;
                done = 1;
                s->b8416 = 0;
            } else if ((t == 3 && (D_800FC270->bD52 & 1)) || (t == 2 && (D_800FC270->bD52 & 2))) {
                func_80076F1C(s);
                if ((s8)s->b8415 == D_800FC270->nA0C - 1) {
                    s->b8416 = 18;
                    done = 1;
                }
            } else {
                go = 1;
                done = 1;
                s->b8416 = 0;
            }
        } else if (D_800FC270->wA00 != 5 || (D_800FC270->bD52 & 4)) {
            s->w8260 = 15;
            func_800AB2A4(D_800F26E0, m->w4, 7, s, 0, 9);
            done = 1;
        } else {
            done = 1;
            s->w8260 = 15;
            func_8009C0D8(done, -1);
        }
    }
    if (go == 0) return;
    func_800B4794(1);
    func_8007492C(s, 0);
    func_8000C944();
    func_800AB2A4(D_800F26E0, D_800F2744, 3, s->w2F50, s->x2F5C, 0);
    s->w8448 = D_800F13F0;
    func_800A9B78(s->x8264, s->p59DC, 0, 1, 2);
    switch (s->b8417) {
    case 0:
        if (s->w8410) {
            func_8009B80C(s->x2B8, 3, -1, 2);
            switch (D_800FC270->wA00) {
            case 6:
                func_800A9BE8(s->x8264, 24);
                s->w8428 = 0;
                break;
            case 5:
                func_800A9BE8(s->x8264, 16);
                s->w8428 = 0x9600;
                break;
            default:
                func_800A9BE8(s->x8264, 0);
                s->w8428 = 0x9600;
                break;
            }
        } else {
            if (D_800FC270->wA00 == 6) {
                func_800A9BE8(s->x8264, 24);
                s->w8428 = 23040;
            } else {
                func_800A9BE8(s->x8264, 1);
                s->w8428 = 23040;
            }
            func_8009BF6C(s->x2B8, s->p59DC);
            func_8009AEC0(2, s->x830);
        }
        s->b8416 = 1;
        break;
    case 5:
        func_800A9BE8(s->x8264, 8);
        s->w8428 = 0x9600;
        s->b8416 = 1;
        break;
    case 1:
        func_800A9BE8(s->x8264, 16);
        s->w8428 = 0x9600;
        s->b8416 = 1;
        break;
    case 2:
        func_800D33A0(s->x2B8, D_800775C8, 1, -1);
    case 3:
    case 4:
        func_800A9BE8(s->x8264, 13);
        s->w8428 = 0;
        s->b8416 = 1;
        break;
    }
    if (s->w8428 <= 0) s->w8428 = 256;
    s->w842C = 15360;
    if (s->w8428 < 15360) s->w842C = s->w8428;
    func_8009BB88(s->b8417, 1);
    if (s->w8410) func_80075274(s);
    switch (s->b8417) {
    case 0:
    case 1:
    case 5:
        r = func_8001D4B8(&D_800F1AE0, 95, 0, -1);
        func_8001D640(&D_800F1AE0, r, 0);
        k = 32767;
        func_8001D5D8(&D_800F1AE0, r, D_800F1AE0.w104 * k >> 15, 45, 0, 0);
        s->w8430 = r;
        break;
    case 2:
    case 3:
    case 4:
        break;
    }
    func_800B4794(0);
}
