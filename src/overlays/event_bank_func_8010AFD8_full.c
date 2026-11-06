typedef struct Inner {
    char pad0[0x3DCC];
    float v;
} Inner;

typedef struct Obj {
    char pad0[4];
    Inner *inner;
    char pad8[0x30C];
    float v;
} Obj;

void func_8010AFD8(Obj *a, float v)
{
    a->v = v;
    a->inner->v = v;
}
