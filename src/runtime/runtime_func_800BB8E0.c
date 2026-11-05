typedef struct { float max, min, base, cur, scale, t; } Ramp;

void func_800BB8E0(Ramp *r)
{
    float t = r->t;
    float target = r->base;
    float d, v;
    if (t > 0.0f) {
        if (t > 1.0f) t = 1.0f;
        target += t * r->scale;
    }
    d = target - r->cur;
    if (d > 0.0f) {
        if (d > r->max) d = r->max;
    } else if (d < r->min) d = r->min;
    v = r->cur + d;
    if (v < 0.0f) v = 0.0f;
    else if (v > 1.0f) v = 1.0f;
    r->cur = v;
}
