void func_800E76F8(int unused, float *out, float *a, float *b, float t)
{
    float s = 1.0f - t;

    out[0] = a[0] * t + b[0] * s;
    out[1] = a[1] * t + b[1] * s;
    out[2] = a[2] * t + b[2] * s;
    out[7] = a[7] * t + b[7] * s;
    out[8] = a[8] * t + b[8] * s;
}
