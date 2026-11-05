typedef struct {
    char pad0[20];
    unsigned short dims[4];
    char pad1[520 - 28];
    unsigned char active;
    char pad2[1208 - 521];
    int counters[12];
    char pad3[1268 - 1256];
    float tableA[11];
    float tableB[11];
    float bands[4];
    char pad4[2532 - 1372];
    int timer;
    char pad5[3411 - 2536];
    unsigned char stage;
    char pad6[3440 - 3412];
    char entry[9];
    unsigned char entryReady;
} State;

typedef struct {
    char pad0[184];
    unsigned char *dims;
    int value;
    char pad1[19102 - 192];
    unsigned char started;
} Owner;

extern State *D_800FC270;
extern unsigned char D_800F274C;
extern char D_800F2AD8[];
extern short D_800FEEB6[];
extern char D_800F5900[];
extern float D_8008BAA0[11];
extern float D_8008BACC[11];
extern void func_800E9290(void);
extern void func_800D9990(void);
extern void func_800D9B34(void *);
extern void func_800D9A18(void);
extern void func_800BC180(void *);
extern void func_800DFC4C(void *);
extern void func_800E9774(int);
extern void func_800D53A0(void *, int);

void func_800DF11C(Owner *self, int unused, int value)
{
    unsigned int i;
    float *src;
    float *src2;

    if (D_800FC270->stage >= 3) {
        D_800FC270->stage = 2;
    }
    if (value != 0) {
        self->value = value;
        self->dims = (unsigned char *)D_800FC270->dims;
        func_800E9290();
        func_800D9990();
        D_800FC270->timer = 0;
        D_800FC270->entryReady = 1;
        func_800D9B34(D_800FC270->entry);
        func_800D9A18();
        D_800FC270->active = 0;
        D_800FC270->dims[0] = 14;
        D_800FC270->dims[1] = 14;
        D_800FC270->dims[2] = 14;
        D_800FC270->dims[3] = 0;
        self->dims[8] = D_800F274C;
        for (i = 0; i < 12; i++) {
            D_800FC270->counters[i] = 0;
        }
        for (i = 0, src2 = D_8008BACC, src = D_8008BAA0; i < 11; i++) {
            float b = *src2++;
            float a = *src++;

            D_800FC270->tableA[i] = a;
            D_800FC270->tableB[i] = b;
        }
        D_800FC270->bands[0] = 700.0f;
        D_800FC270->bands[1] = 600.0f;
        D_800FC270->bands[2] = 500.0f;
        D_800FC270->bands[3] = 400.0f;
        func_800BC180(D_800F2AD8);
        func_800DFC4C(self);
        D_800FEEB6[0] = 2;
        func_800E9774(self->value);
        func_800D53A0(D_800F5900, 12);
        self->started = 1;
    }
}
