typedef unsigned char u8;
typedef signed char s8;
typedef struct Slot { s8 c0; s8 c1; char pad2[2]; float f4; s8 c8; char pad9[3]; } Slot;
typedef struct Ent { char pad[0x20]; u8 b20; char pad21[60 - 0x21]; } Ent;
typedef struct G {
    Ent ent[1];
    char pad3C[0xA00 - 60];
    int state;
    int snd;
    char padA08[4];
    u8 n;
    char padA0D[3];
    Slot slot[1];
    char padA1C[0xD10 - 0xA1C];
    float thr;
} G;
typedef struct P { char pad[4]; u8 b4; char pad5[28 - 5]; } P;
typedef struct S { char pad[0x75AB]; u8 b75AB; char pad75AC[0x75FC - 0x75AC]; P *p; } S;
extern G *D_800FC270;
extern char D_800F3BC0[];
extern void func_800C0110(void *, int, int, int);
extern int func_8009B73C(int);

void func_800946FC(S *a0)
{
    G *g;
    Slot *base;
    Slot *t;
    int sfx;
    unsigned int i;
    int type;
    int cnt;
    int k, v, id;
    int found;
    int r;
    P *p;

    t = 0;
    if (a0->b75AB >= 2) return;
    sfx = -1;
    base = D_800FC270->slot;
    if (D_800FC270->state == 0) sfx = 184;
    else if (D_800FC270->state == 1) sfx = 186;
    else if (D_800FC270->state == 2) sfx = 188;
    for (i = 0; i < D_800FC270->n; i++) {
        if (base[i].c8 == 0) { t = &base[i]; break; }
    }
    if (t == 0) return;
    if (t->c0 != 8) type = D_800FC270->ent[t->c0].b20;
    else type = 3;
    cnt = 0;
    for (i = 0; i < D_800FC270->n; i++) {
        if (a0->p[i].b4 < 3) cnt++;
    }
    g = D_800FC270;
    switch (g->state) {
    case 0: case 1: case 2: case 3: case 5:
        if (cnt) {
            if (D_800FC270->snd) func_800C0110(D_800F3BC0, 113, 0, 23040);
            return;
        }
        if (type != 3) { k = 8; v = t->c0; }
        else { k = 116; v = (u8)t->c1; sfx = -1; }
        id = k + v;
        if (D_800FC270->snd) func_800C0110(D_800F3BC0, id, 0, 0);
        if (sfx >= 0 && D_800FC270->snd) func_800C0110(D_800F3BC0, sfx, 0, 0);
        return;
    case 4:
        if (cnt) {
            if (g->snd) func_800C0110(D_800F3BC0, 328, 0, 23040);
            return;
        }
        r = func_8009B73C(0);
        found = 0;
        switch (D_800FC270->snd) {
        case 1:
            for (i = 0; i < D_800FC270->n; i++) {
                if (base[i].c0 == 0 && base[i].f4 >= D_800FC270->thr) found = 1;
            }
            if (found) {
                if (D_800FC270->snd) func_800C0110(D_800F3BC0, 225, 0, 0);
            } else {
                if (D_800FC270->snd) func_800C0110(D_800F3BC0, 218, 0, 0);
            }
            break;
        case 5:
            if ((s8)r == 0) func_800C0110(D_800F3BC0, 223, 0, 0);
            else if ((s8)r == 1) func_800C0110(D_800F3BC0, 221, 0, 0);
            else if ((s8)r == 2) func_800C0110(D_800F3BC0, 222, 0, 0);
            else if ((s8)r == 3) func_800C0110(D_800F3BC0, 220, 0, 0);
            else func_800C0110(D_800F3BC0, 215, 0, 0);
            break;
        }
        return;
    }
}
