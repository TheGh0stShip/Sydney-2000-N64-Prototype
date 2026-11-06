typedef struct Pair {
    char pad0[0xEC];
    float a;
    float b;
} Pair;

typedef struct Obj {
    char pad0[0xEC];
    float a;
    float b;
    char padF4[0x2F4 - 0xF4];
    float in_a;
    float in_b;
    char pad2FC[0x318 - 0x2FC];
    float bias;
    char pad31C[0x4E8 - 0x31C];
    Pair mirror;
} Obj;

void func_801018EC(Obj *obj)
{
    float a;
    float b;
    float lo;
    float hi;
    Pair *m;

    a = obj->in_a;
    a *= *(float *)0x80078B44;
    b = obj->in_b - *(float *)0x80078B48;
    b /= *(float *)0x80078B4C;
    b -= *(float *)0x80078B50;
    a -= obj->bias;
    a += *(float *)0x80078B54;
    a /= *(float *)0x80078B58;
    a += *(float *)0x80078B5C;
    lo = 0.0f;
    if (a < lo) {
        a = lo;
    }
    hi = *(float *)0x80078B60;
    if (hi < a) {
        a = hi;
    }
    if (b < lo) {
        b = lo;
    }
    if (hi < b) {
        b = hi;
    }
    m = &obj->mirror;
    obj->a = a;
    obj->b = b;
    m->a = a;
    m->b = b;
}
