typedef unsigned char u8;
typedef signed char s8;
typedef short s16;

typedef struct {
    s8 b0;
    u8 b1;
    s16 h;
    char pad4[4];
    s8 b8;
    char pad9[3];
} Ent;

typedef struct {
    char pad0[0xA00];
    int wA00;
    int wA04;
    char padA08[8];
    Ent e[1];
} Game;

extern Game *D_800FC270;
extern char D_800F3BC0[];
extern void func_800C0110(void *, int, int, int);

#define SND(o, id)     if ((o)[0x5DE9] != 4 && (o)[0x5DE9] != 2 && (o)[0x5DE9] != 3) {         func_800C0110(D_800F3BC0, (id), 0, 0);     }

void func_80074510(u8 *o, int arg1)
{
    Ent *e1;
    Ent *e2;
    int a;
    int b;
    int c;

    e1 = D_800FC270->e;
    while (e1->b8 != 0) {
        e1++;
    }
    a = -1;
    b = -1;
    c = -1;
    if (D_800FC270->wA00 == 4) {
        if (arg1 == 0) {
            SND(o, 368)
        } else {
            e2 = D_800FC270->e;
            while (e2->b0 == 8) {
                e2++;
            }
            SND(o, 367)
            a = e1->b1 + 138;
            if (e2->h != -1) {
                if (e2->b8 == 0) {
                    b = 258;
                } else if (e2->b8 == 1) {
                    b = 256;
                } else if (e2->b8 == 2) {
                    b = 257;
                } else if (e2->b8 == 3) {
                    b = 255;
                } else {
                    b = 250;
                }
            } else {
                    b = 251;
            }
        }
    } else {
        SND(o, 104)
        if (D_800FC270->wA00 == 5 && e1->b0 != 8) {
            a = e1->b0 + 16;
        } else {
            a = e1->b1 + 138;
            if (e1->b0 != 8 && D_800FC270->wA04 == 1) {
                if (D_800FC270->wA00 == 0) {
                    c = 170;
                } else if (D_800FC270->wA00 == 1) {
                    c = 172;
                } else {
                    c = 175;
                }
            }
        }
    }
    if (a != -1) {
        SND(o, a)
    }
    if (b != -1) {
        SND(o, 262)
        SND(o, b)
    }
    if (c != -1) {
        SND(o, c)
    }
}
