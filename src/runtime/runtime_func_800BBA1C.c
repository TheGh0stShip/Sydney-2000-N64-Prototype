typedef struct { char pad[0xC]; float cur, scale, t; unsigned char last; } Ramp;
void func_800BBA1C(Ramp *r)
{
    r->t = 0.0f;
    r->last = 0;
    r->cur = 0.0f;
}
