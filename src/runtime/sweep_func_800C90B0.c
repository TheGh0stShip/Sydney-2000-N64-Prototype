typedef struct { short adj; short pad; void (*fn)(); } VEnt;
typedef struct {
    char pad0[0xC0];
    int flags;
} Part;

extern unsigned short func_8000EB20(char *name);
extern void func_80013208(int *out, float a, float b, int id, int k);
extern void func_800ADC54(char *p, int on);

void func_800C90B0(char *o, int arg)
{
    char *name;
    int h;
    char *p;
    char *q;
    VEnt *vt;

    name = "GYM_BACKGROUND1";
    h = 0;
    func_80013208(&h, 655.33997f, 655.33997f, func_8000EB20(name), 2);
    p = o + 0xBC;
    *(int *)(o + 0x180) = h;
    ((Part *)p)->flags |= 2;
    func_800ADC54(p, 1);
    vt = *(VEnt **)(o + 0x170);
    vt[2].fn(p + vt[2].adj, arg);
    *(char *)(o + 0x16C) = 1;
    vt = *(VEnt **)(o + 0x170);
    vt[8].fn(p + vt[8].adj);
    h = 0;
    *(float *)(o + 0x164) = 327.66998f;

    func_80013208(&h, 655.33997f, 655.33997f, func_8000EB20(name), 2);
    q = o + 0x190;
    *(int *)(o + 0x254) = h;
    ((Part *)q)->flags |= 0x12;
    func_800ADC54(q, 1);
    vt = *(VEnt **)(o + 0x244);
    vt[2].fn(q + vt[2].adj, arg);
    *(char *)(o + 0x240) = 1;
    vt = *(VEnt **)(o + 0x244);
    vt[8].fn(q + vt[8].adj);
    *(float *)(o + 0x238) = 294.90298f;
}
