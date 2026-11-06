typedef struct Obj {
    char pad0[0x194];
    float a;
    float b;
    float c;
} Obj;

extern unsigned int D_800F13F0;

int func_80100EB0(Obj *obj)
{
    float base;
    float r1;
    float r2;

    base = obj->a * *(float *)0x80078A9C + obj->c * *(float *)0x80078AA0 + obj->b * *(float *)0x80078AA0;
    {
        unsigned int s1;
        int v1;
        double d1;

        s1 = (D_800F13F0 * 16807) & 0x7FFFFFFF;
        v1 = s1 >> 19;
        D_800F13F0 = s1;
        d1 = v1;
        if (v1 < 0) {
            d1 += *(double *)0x80078AA8;
        }
        r1 = (float)d1 * *(float *)0x80078AB0 * *(float *)0x80078AB4;
    }
    {
        unsigned int s2;
        int v2;
        double d2;

        s2 = (D_800F13F0 * 16807) & 0x7FFFFFFF;
        v2 = s2 >> 19;
        D_800F13F0 = s2;
        d2 = v2;
        if (v2 < 0) {
            d2 += *(double *)0x80078AB8;
        }
        r2 = (float)d2 * *(float *)0x80078AB0;
    }
    if (r2 <= base + r1) {
        return 1;
    }
    return 0;
}
