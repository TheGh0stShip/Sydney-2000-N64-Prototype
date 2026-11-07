extern float sqrtf(float);
int func_800ACE08(float a, float b, float c, float *out)
{
    int n = 0;
    float d = b * b - a * c * 4.0f;
    float q;
    if (d < 0.0f) {
        out[1] = 0.0f;
        out[0] = 0.0f;
        return n;
    }
    d = sqrtf(d);
    q = -((b < 0.0f ? b - d : b + d) * 0.5f);
    if (a != 0.0f) {
        *out++ = q / a;
        n++;
    }
    if (q != 0.0f) {
        *out = c / q;
        n++;
    }
    return n;
}
