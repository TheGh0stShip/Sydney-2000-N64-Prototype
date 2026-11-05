typedef struct { char pad[0x14]; float t; unsigned char last; } Ramp;
void func_800BB9C0(Ramp *r, int unused, unsigned char *in)
{
    float v = r->t * 30.0f;
    unsigned char k = in[3] & 3;
    if (k != 0 && k != 3 && k != r->last) {
        r->last = k;
        v += 1.0f;
    }
    r->t = v * (1.0f / 31.0f);
}
