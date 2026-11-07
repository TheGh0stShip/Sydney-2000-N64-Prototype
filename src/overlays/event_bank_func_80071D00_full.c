typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

typedef struct {
    s8 b0;
    u8 b1;
    short h;
    f32 v;
    char pad8[4];
} Ent;

typedef struct {
    char pad0[0x504];
    f32 f504;
    char pad508[0x530 - 0x508];
    f32 f530;
    char pad534[0xA00 - 0x534];
    int wA00;
    int wA04;
    char padA08[4];
    u8 count;
    char padA0D[3];
    Ent e[1];
} Game;

typedef struct {
    char pad0[4];
    int w4;
    char pad8[8];
    int w10;
} Arg;

typedef struct {
    char pad0[0x20];
    u8 b20;
    char pad21[60 - 0x21];
} Rec;

#define B(p, o) (*(u8 *)((char *)(p) + (o)))
#define SB(p, o) (*(s8 *)((char *)(p) + (o)))
#define W(p, o) (*(int *)((char *)(p) + (o)))
#define F(p, o) (*(f32 *)((char *)(p) + (o)))

extern Game *D_800FC270;
extern char D_800F26E0[];
extern void func_800A62EC(void *);
extern void func_800AB2A4(void *, int, int, void *, int, int);
extern void func_8009C0D8(int, int);
extern void func_80074E9C(void *, int);
extern void func_80076E50(void *);
extern void func_8009BD50(int);
extern void func_800AC334(void *);

void func_80071D00(char *s, Arg *a)
{
    int done;
    int adv;
    int k;
    int m;
    f32 f;
    char *p;

    func_800A62EC(s + 0x18D0);
    if (W(s, 0x7CA8) == 0) {
        f = D_800FC270->e[SB(s, 0x7CAD)].v;
        if (D_800FC270->wA00 == 4 || D_800FC270->wA00 == 0 || D_800FC270->wA00 == 1 || D_800FC270->wA00 == 2) {
            if (B(s, 0x7CAF) != 4) {
                if (D_800FC270->f504 < f) {
                    D_800FC270->f504 = f;
                }
            }
        }
        if (D_800FC270->wA00 == 4) {
            if (D_800FC270->f530 < f) {
                D_800FC270->f530 = f;
            }
        } else if (D_800FC270->wA00 == 5) {
            if (F(D_800FC270, 0xDEC) < f) {
                F(D_800FC270, 0xDEC) = f;
            }
        }
    }
    done = 0;
    do {
        if (a->w10 == 0) {
            SB(s, 0x7CAD)++;
        }
        if (B(s, 0x7CAF) == 3) {
            SB(s, 0x7CAC)++;
        }
        adv = 0;
        if (SB(s, 0x7CAD) < D_800FC270->count) {
            adv = 1;
        } else {
            SB(s, 0x7CAD) = 0;
            SB(s, 0x7CAC)++;
            if (SB(s, 0x7CAC) < 3) {
                adv = 1;
            } else if (D_800FC270->wA00 != 5 || (B(D_800FC270, 0xD52) & 4)) {
                W(s, 0x7AEC) = 15;
                func_800AB2A4(D_800F26E0, a->w4, 7, s, 0, 9);
                done = 1;
            } else {
                done = 1;
                W(s, 0x7AEC) = 15;
                func_8009C0D8(done, -1);
            }
        }
        if (adv) {
            Game *g = D_800FC270;
            m = g->e[SB(s, 0x7CAD)].b0;
            if (m < 8) {
                Rec *r = (Rec *)g + m;
                if (r->b20 == 2 && (B(D_800FC270, 0xD52) & 2)) {
                    func_80074E9C(s, 0);
                    func_80076E50(s);
                    if (SB(s, 0x7CAD) == D_800FC270->count - 1) {
                        B(s, 0x7CAE) = 17;
                        done = 1;
                    }
                } else {
                    func_800AB2A4(D_800F26E0, a->w4, 21, s, 0, 0);
                    done = 1;
                    B(s, 0x7CAE) = 0;
                }
            } else if (m == 8) {
                if (B(D_800FC270, 0xD52) & 3) {
                    func_80074E9C(s, 0);
                    func_80076E50(s);
                    if (SB(s, 0x7CAD) == D_800FC270->count - 1) {
                        B(s, 0x7CAE) = 17;
                        done = 1;
                    }
                } else {
                    func_800AB2A4(D_800F26E0, a->w4, 21, s, 0, 0);
                    done = 1;
                    B(s, 0x7CAE) = 0;
                }
            }
        }
    } while (!done);
    if (W(s, 0x7CA8) == 0) {
        func_8009BD50(B(s, 0x7CAF));
    }
    if (B(s, 0x7CAE) != 17) {
        p = s + 0x7BE4;
        if (W(p, 4) != 0) {
            func_800AC334(p);
        }
        if (B(s, 0x7CAF) != 2 && B(s, 0x7CAF) != 3 && B(s, 0x7CAF) != 4) {
            func_80074E9C(s, 0);
        } else {
            func_80074E9C(s, 1);
        }
        if (B(s, 0x7CAF) == 5) {
            B(s, 0x7CAF) = B(s, 0x7CB0);
        }
    }
}
