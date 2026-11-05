typedef struct { int max, min; float base, cur, scale; } Ramp;
void func_800BB99C(Ramp *r, int max, int min, float base)
{
    r->max = max;
    r->min = min;
    r->base = base;
    r->scale = 1.0f - base;
}
