typedef struct { short adj; short pad; void (*fn)(); } VEnt;
typedef struct { char pad[0xB0]; unsigned char act; char padb1[3]; VEnt *vt; char rest[212 - 0xB8]; } Sub;
typedef struct {
    char pad0[0xB0];
    unsigned char act;
    char padb1[3];
    VEnt *vt;
    char padb8[0xD4 - 0xB8];
    Sub w0;
    char pad1a8[0x1C0 - 0x1A8];
    Sub w1;
    char pad294[0x2AC - 0x294];
    Sub w2;
    char pad380[0x398 - 0x380];
    Sub w3;
    char pad46c[0x484 - 0x46C];
    Sub panel;
    Sub cars[4];
    char pad8a8[0x8A8 - 0x8A8];
    int snd2;
    int snd1;
    int snd[4];
} Hud;

extern void func_800ADC1C(Sub *s);
extern void func_800D6EA0(Sub *s);
extern void func_8001A248(int *h);

static inline void off(Sub *u)
{
    u->vt[3].fn((char *)u + u->vt[3].adj);
    u->act = 0;
}

static inline void car_off(Sub *u, char *self)
{
    u->vt[9].fn(self + u->vt[9].adj);
    u->vt[3].fn((char *)u + u->vt[3].adj);
    u->act = 0;
}

void func_800D3990(Hud *h)
{
    unsigned char i;
    int ofs;

    h->vt[9].fn((char *)h + h->vt[9].adj);
    func_800ADC1C(&h->panel);
    func_800D6EA0(&h->w0);
    func_800D6EA0(&h->w1);
    func_800D6EA0(&h->w2);
    func_800D6EA0(&h->w3);
    off(&h->w0);
    off(&h->w1);
    off(&h->w2);
    off(&h->w3);
    off(&h->panel);
    h->vt[3].fn((char *)h + h->vt[3].adj);
    h->act = 0;
    i = 0;
    while (1) {
        if (i >= 4) break;
        ofs = i * sizeof(Sub) + 0x558;
        car_off(&h->cars[i], (char *)h + ofs);
        if (h->snd[i] != 0) {
            func_8001A248(&h->snd[i]);
        }
        i++;
    }
    if (h->snd1 != 0) {
        func_8001A248(&h->snd1);
    }
    if (h->snd2 != 0) {
        func_8001A248(&h->snd2);
    }
}
