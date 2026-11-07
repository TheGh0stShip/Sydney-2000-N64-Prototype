typedef struct { short adj; short pad; void (*fn)(); } VEnt;
typedef struct { char pad[0x58]; float f58; char pad5c[0x60 - 0x5C]; float f60; char pad64[0xA0 - 0x64]; float x; float y; char pada8[0xB0 - 0xA8]; unsigned char act; char padb1[3]; VEnt *vt; char padb8[0xC0 - 0xB8]; int flags; int tex; char rest[212 - 0xC8]; } Sub;
typedef struct { char pad[4]; float y; } Pt;
typedef struct { char pad[0x10]; Pt **pts; } Bank;
typedef struct {
    char pad0[0x14];
    char cfg[0xB8 - 0x14];
    Bank *bank;
    Sub subs[20];
    int tex[20];
    int img[20];
    char pad11ec[0x11EC - 0x11EC];
    int a2;
    int pad11f0;
    int a3;
    char pad11f8[0x1204 - 0x11F8];
    float base;
} Board;

extern int D_800F4770[];
extern int D_800F47C0[];
extern float D_800F4810[];
extern int func_80013E7C(int id, Bank **b, int n);
extern void func_800ADC54(Sub *s, int n);
extern void func_800B3870(void *d, void *s, int n);

void func_800CA160(Board *b, void *src, int a2, int a3)
{
    unsigned char i;
    Sub *s;

    b->a3 = a3;
    b->a2 = a2;
    i = 0;
    while (1) {
        if (i >= 20) break;
        b->img[i] = 0;
        if ((b->img[i] = func_80013E7C(D_800F4770[i], &b->bank, 0)) == 0) {
            return;
        }
        b->tex[i] = 0;
        if ((b->tex[i] = func_80013E7C(D_800F47C0[i], &b->bank, 0)) == 0) {
            return;
        }
        s = &b->subs[i];
        s->tex = b->tex[i];
        s->flags |= 2;
        func_800ADC54(s, 1);
        func_800B3870((char *)s + 0x14, src, 76);
        s->y -= (*b->bank->pts)->y;
        s->y = s->y + D_800F4810[i] - 75.3641f;
        s->f60 = 1.5f;
        if (i == 0) {
            b->base = s->f58;
        }
        s->x = (float)((i - 10) * 7) * 0.32767f;
        s->y += 32.767f;
        s->vt[2].fn((char *)s + s->vt[2].adj, b);
        s->act = 1;
        i++;
    }
    func_800B3870(b->cfg, src, 76);
}
