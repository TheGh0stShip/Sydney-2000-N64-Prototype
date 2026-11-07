typedef struct { short adj; short pad; void (*fn)(); } VEnt;
typedef struct {
    int type;
    char pad4[0xB1 - 4];
    unsigned char bb1;
    char padb2[0xB4 - 0xB2];
    VEnt *vt;
    char padb8[0xC4 - 0xB8];
    int model;
    char padc8[0xD4 - 0xC8];
} Big;
typedef struct { char pad[0x9F8]; int venue; } Game;

extern char D_800F2758[];
extern char *D_800F23B0[];
extern Game *D_800FC270;
extern void func_800AA804(char *pool, void *slot, int size, char *name);
extern void func_800ADED4(Big *b);
extern void func_800ADC54(Big *b, int f);
extern int func_80017D54(void);
extern int func_80013E7C(char *name, void *p, int z);
extern void func_800ADE84(Big *b, int f);

void func_800A6160(char *o, unsigned int kind, int flag)
{
    Big tmp;
    Big *b;

    *(unsigned int *)(o + 0xC0) = kind;
    func_800AA804(D_800F2758, o + 0xBC, sizeof(Big), "ENVOBJ");
    func_800ADED4(&tmp);
    **(Big **)(o + 0xBC) = tmp;
    (*(Big **)(o + 0xBC))->bb1 = 0;
    func_800ADC54(*(Big **)(o + 0xBC), flag);
    if (kind == 3) {
        if (func_80017D54() == 0) {
            kind = 24;
        }
    }
    if (kind < 3) {
        if (func_80017D54() == 0) {
            kind = 25;
        }
    }
    if (kind - 4 < 3) {
        int v = D_800FC270->venue;
        if (v == 8) {
            (*(Big **)(o + 0xBC))->model = func_80013E7C("GRAPHICS__ENVIRONMENTS__POOL__NATIONAL__NDIVEPOOL_OBB", o + 0xB8, 0);
        } else if (v == 7) {
            (*(Big **)(o + 0xBC))->model = func_80013E7C("GRAPHICS__ENVIRONMENTS__POOL__NATIONAL__NSWIMPOOL_OBB", o + 0xB8, 0);
        }
    } else {
        (*(Big **)(o + 0xBC))->model = func_80013E7C(D_800F23B0[kind], o + 0xB8, 0);
    }
    (*(Big **)(o + 0xBC))->type = 86;
    b = *(Big **)(o + 0xBC);
    b->vt[8].fn((char *)b + b->vt[8].adj);
    func_800ADE84(&tmp, 2);
}
