typedef struct Inner {
    char pad0[0x3DCC];
    float v;
} Inner;

typedef struct Obj {
    char pad0[4];
    Inner *inner;
    char pad8[0x2FC];
    float f304;
    char pad308[0xC];
    float v;
    char pad318[0x24];
    float f33C;
} Obj;

#define K(x) (*(float *)(x))

void func_8010AFEC(Obj *a)
{
    float s = a->f304;
    float t = a->f33C + K(0x80078B14) + s * K(0x80078B10) + K(0x80078B1C);
    Inner *in = a->inner;
    float d;

    if (s < K(0x80078B18)) {
        t *= s * K(0x80078B20);
    }
    d = t - a->v;
    if (d > 0.0f) {
        if (d > K(0x80078B24)) {
            d = K(0x80078B24);
        }
    } else {
        if (d < K(0x80078B28)) {
            d = K(0x80078B28);
        }
    }
    a->v += d;
    in->v = a->v;
}
