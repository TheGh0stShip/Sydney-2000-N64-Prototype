typedef struct Obj {
    char pad0[0x194];
    float f194;
    float f198;
    float f19C;
    char pad1A0[4];
    float f1A4;
} Obj;

extern unsigned int D_800F2714;

static inline int rand13(void)
{
    unsigned int r = (D_800F2714 * 16807) & 0x7FFFFFFF;
    D_800F2714 = r;
    return r >> 19;
}

float func_8010814C(Obj *a)
{
    float c = a->f19C;
    float t;
    float f;
    double d;
    int r;

    r = rand13();
    d = r;
    t = (a->f194 * *(float *)0x80078B98 + a->f198 * *(float *)0x80078B9C) * *(float *)0x80078BA0;
    if (r < 0) {
        d += *(double *)0x80078BA8;
    }
    f = (float)d * *(float *)0x80078BB0;
    c = c * *(float *)0x80078BB4 + f * *(float *)0x80078BB8;
    t *= c;
    t += *(float *)0x80078BBC;
    if (a->f1A4 < t) {
        a->f1A4 = t;
    }
    return t;
}
