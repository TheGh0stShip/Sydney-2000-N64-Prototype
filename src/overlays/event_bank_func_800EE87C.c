typedef struct Game {
    char pad0[0xA00];
    int state;
    char padA04[0xD53 - 0xA04];
    unsigned char mode;
} Game;

typedef struct Obj {
    char pad0[0x194];
    float a;
    float b;
    float c;
    char pad1A0[0x1A4 - 0x1A0];
    float best;
} Obj;

extern Game *D_800FC270;
extern unsigned int D_800F13F0;

float func_800EE87C(Obj *obj)
{
    float base;
    float r1;
    float off; float off2;
    float amp;
    float r2;
    float res;
    double d;
    int v;
    unsigned int s;

    base = obj->a * *(float *)0x80078AD8 + obj->b * *(float *)0x80078ADC;
    {unsigned int s1; int v1; double d1;
    s1 = (D_800F13F0 * 16807) & 0x7FFFFFFF;
    v1 = s1 >> 19;
    D_800F13F0 = s1;
    d1 = v1;
    if (v1 < 0) {
        d1 += *(double *)0x80078AE0;
    }
    r1 = (float)d1 * *(float *)0x80078AE8;}
    switch (D_800FC270->mode) {
    case 0:
        off = *(float *)0x80078AEC;
        amp = *(float *)0x80078AF0;
        break;
    case 1:
        off = *(float *)0x80078AF4;
        amp = *(float *)0x80078AF8;
        break;
    case 2:
        off = *(float *)0x80078AFC;
        amp = *(float *)0x80078B00;
        break;
    case 3:
        off = *(float *)0x80078B04;
        amp = *(float *)0x80078B08;
        break;
    default:
        off = amp = 0.0f;
        break;
    }
    s = (D_800F13F0 * 16807) & 0x7FFFFFFF;
    v = s >> 19;
    D_800F13F0 = s;
    d = v;
    if (v < 0) {
        d += *(double *)0x80078B10;
    }
    off2 = obj->c;
    r1 = r1 * (*(float *)0x80078B18 - off2);
    amp = amp * ((float)d * *(float *)0x80078B1C + *(float *)0x80078B20);
    base = amp * base + off;
    base -= r1 * *(float *)0x80078B24;
    if (D_800FC270->state != 5 && obj->best < base) {
        obj->best = base;
    }
    return base;
}
