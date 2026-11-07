typedef struct { short adj; short pad; void (*fn)(); } VEnt;

extern void func_80019680(int *h, int c);
extern void func_8001A330(int *h, int c);
extern void func_8001A1D8(int *h, float a, float b, int c, float d);
extern void func_8001A210(int *h, float a, float b, float c, float d, int e);
extern void func_80019338(int *h, int r, int g, int b, int a);
extern void func_800191E0(int *h, int c);
extern void func_800ADC54(char *o, int f);

void func_800CB204(int unused, char *o, float x, float y, int p4, float p5, int p6, int p7, int p8)
{
    int h;
    int t;
    int fl;
    float *m;
    VEnt *vt;

    h = 0;
    if (p6) {
        func_80019680(&h, p6);
    } else {
        func_8001A330(&h, 0xFFFF);
    }
    func_8001A1D8(&h, 0.0f, 0.0f, p4, p5);
    func_8001A210(&h, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    if (p8) {
        func_80019338(&h, 255, 255, 255, 128);
    } else {
        func_800191E0(&h, -1);
    }
    *(unsigned char *)(o + 0xC9) = p7;
    *(int *)(o + 0xC0) |= 0x20000;
    func_800ADC54(o, 2);
    fl = *(int *)(o + 0xC0);
    t = h;
    *(int *)(o + 0xC0) = fl | 2;
    *(int *)(o + 0xC4) = t;
    vt = *(VEnt **)(o + 0xB4);
    vt[8].fn(o + vt[8].adj);
    m = (float *)(o + 0x14);
    m[9] = 0.0f;
    m[8] = 0.0f;
    m[6] = 0.0f;
    m[4] = 0.0f;
    m[2] = 0.0f;
    m[1] = 0.0f;
    m[18] = 0.0f;
    m[17] = 0.0f;
    m[16] = 0.0f;
    m[0] = m[5] = m[10] = 1.0f;
    *(float *)(o + 0x54) = x;
    *(float *)(o + 0x58) = y;
}
