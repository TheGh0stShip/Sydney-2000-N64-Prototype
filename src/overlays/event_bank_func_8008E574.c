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
typedef struct S { char pad[0x8414]; s8 c8414; char pad8415[2]; u8 b8417; } S;
extern G *D_800FC270;
extern char D_800F3BC0[];
extern void func_800C0110(void *, int, int, int);
extern int func_8009B73C(int);

void func_8008E574(S *a0)
{
    Slot *base;
    Slot *t;
    int sfx;
    unsigned int i;
    int type;
    int k, v, id;
    int found;
    int r;
    int state;

    if (a0->b8417 != 0 && a0->b8417 != 5 && a0->b8417 != 1) return;
    sfx = -1;
    base = D_800FC270->slot;
    t = base;
    if (D_800FC270->state == 0) sfx = 202;
    else if (D_800FC270->state == 1) sfx = 204;
    else if (D_800FC270->state == 2) sfx = 206;
    for (i = 0; i < D_800FC270->n; i++) {
        if (base[i].c8 == 0) { t = &base[i]; break; }
    }
    if (t->c0 != 8) type = D_800FC270->ent[t->c0].b20;
    else type = 3;
    state = D_800FC270->state;
    switch (state) {
    case 0: case 1: case 2: case 3: case 5:
        if (a0->c8414 < 2) {
            if (D_800FC270->snd) func_800C0110(D_800F3BC0, 123, 0, 0);
            return;
        }
        if (type != 3) { k = 12; v = t->c0; }
        else { k = 131; v = (u8)t->c1; sfx = -1; }
        id = k + v;
        if (D_800FC270->snd) func_800C0110(D_800F3BC0, id, 0, 0);
        if (sfx >= 0 && D_800FC270->snd) func_800C0110(D_800F3BC0, sfx, 0, 0);
        return;
    case 4:
        if (a0->c8414 < 2) {
            if (D_800FC270->snd) func_800C0110(D_800F3BC0, 346, 0, 0);
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
                if (D_800FC270->snd) func_800C0110(D_800F3BC0, 238, 0, 0);
            } else {
                if (D_800FC270->snd) func_800C0110(D_800F3BC0, 231, 0, 0);
            }
            break;
        case 4:
            if ((s8)r < 8) func_800C0110(D_800F3BC0, 239, 0, 0);
            else func_800C0110(D_800F3BC0, 232, 0, 0);
            break;
        case 5:
            if ((s8)r == 0) func_800C0110(D_800F3BC0, 236, 0, 0);
            else if ((s8)r == 1) func_800C0110(D_800F3BC0, 234, 0, 0);
            else if ((s8)r == 2) func_800C0110(D_800F3BC0, 235, 0, 0);
            else if ((s8)r == 3) func_800C0110(D_800F3BC0, 233, 0, 0);
            else func_800C0110(D_800F3BC0, 228, 0, 0);
            break;
        }
        return;
    }
}
