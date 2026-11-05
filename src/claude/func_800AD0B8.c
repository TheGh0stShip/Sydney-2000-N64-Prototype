typedef float f32;

void func_800AD0B8(f32 *a, f32 *b, f32 t, f32 *out)
{
    f32 tmp[4];

    if (a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3] < 0.0f) {
        tmp[0] = -b[0];
        tmp[1] = -b[1];
        tmp[2] = -b[2];
        tmp[3] = -b[3];
    } else {
        tmp[0] = b[0];
        tmp[1] = b[1];
        tmp[2] = b[2];
        tmp[3] = b[3];
    }
    out[0] = a[0] + (tmp[0] - a[0]) * t;
    out[1] = a[1] + (tmp[1] - a[1]) * t;
    out[2] = a[2] + (tmp[2] - a[2]) * t;
    out[3] = a[3] + (tmp[3] - a[3]) * t;
}
