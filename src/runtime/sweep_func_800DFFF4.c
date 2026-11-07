typedef struct { int a; char p0[208]; int b; char p1[208]; int c; char p2[636 - 428]; } Ent;
typedef struct { char p0[4]; int t; char p1[425 - 8]; unsigned char cur; } Sub;
typedef struct {
    char p0[188]; char *g; char p1[11284 - 192]; Ent e[12];
    char p2[19100 - 11284 - 12 * 636]; short h; unsigned char done;
} Obj;
typedef struct { char p0[524]; int mode[12]; char p1[1265 - 572]; unsigned char sel; char p2[2524 - 1266]; unsigned short cnt; } Glob;
typedef struct { int z; int v; } Pair;
typedef struct { char p0[452]; unsigned int flags; } Flg;

extern Glob *D_800FC270;
extern int D_80103430[2];
extern Pair D_800FCD8C[12];
extern unsigned short D_800FE336;
extern Flg D_800FE328;
extern char D_800F5900[];
extern void func_800C8500(Sub *);
extern void func_800C8120(Sub *, int, int);
extern void func_800E9974(char *, int);
extern void func_800DF2B4(Obj *, int);
extern void func_800D53A0(char *, int);

void func_800DFFF4(Obj *o, int a)
{
    int flag = 0;
    unsigned int i;

    if (a != 0) {
        if (o->g != 0) {
            Sub *s = (Sub *)(o->g + 28540);
            unsigned char b = D_800FC270->sel;
            if (b != s->cur) {
                int t = s->t;
                func_800C8500(s);
                s->cur = b;
                func_800C8120(s, t, flag);
            }
        }
    }
    if (o->g != 0) {
        o->h = 2;
        func_800E9974(o->g, 2);
    }
    func_800DF2B4(o, 0);
    if (a != 0) {
        D_800FE336 = 1;
    } else {
        D_800FE336 = D_800FC270->cnt + 1;
    }
    for (i = 0; i < 12; i++) {
        switch (D_800FC270->mode[i]) {
        case 0:
        default:
            o->e[i].a = D_80103430[0];
            o->e[i].b = D_80103430[0];
            o->e[i].c = D_80103430[0];
            break;
        case 1:
            o->e[i].a = D_80103430[1];
            o->e[i].b = D_80103430[0];
            o->e[i].c = D_80103430[0];
            break;
        case 2:
            o->e[i].a = D_80103430[1];
            o->e[i].b = D_80103430[1];
            o->e[i].c = D_80103430[0];
            break;
        case 3:
            flag = 1;
            o->e[i].a = D_80103430[1];
            o->e[i].b = D_80103430[1];
            o->e[i].c = D_80103430[1];
            break;
        }
        D_800FCD8C[i].z = 0;
        D_800FCD8C[i].v = i + 17;
    }
    if (flag != 0) {
        D_800FE328.flags &= ~0x80000;
    } else {
        D_800FE328.flags |= 0x80000;
    }
    func_800D53A0(D_800F5900, 17);
    o->done = 1;
}
