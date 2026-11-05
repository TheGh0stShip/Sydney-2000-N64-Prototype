/* Runtime-stage C reconstruction: spherical interpolation between two quaternions,
 * taking the shorter arc and falling back to a linear blend for nearly equal inputs.
 */
typedef float f32;
typedef double f64;

extern f64 acos(f64 x);
extern f32 sinf(f32 x);

void func_800ACF20(f32 *a, f32 *b, f32 t, f32 *out)
{
    f32 tmp[4];
    f32 cosom;
    f32 omega;
    f32 inverseSin;
    f32 scale0;
    f32 scale1;

    cosom = a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];
    if (cosom < 0.0f) {
        cosom = -cosom;
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
    if (1.0f - cosom > 0.01f) {
        omega = acos(cosom);
        inverseSin = 1.0f / sinf(omega);
        scale0 = sinf(omega - t * omega) * inverseSin;
        scale1 = sinf(t * omega) * inverseSin;
    } else {
        scale0 = 1.0f - t;
        scale1 = t;
    }
    out[0] = scale0 * a[0] + scale1 * tmp[0];
    out[1] = scale0 * a[1] + scale1 * tmp[1];
    out[2] = scale0 * a[2] + scale1 * tmp[2];
    out[3] = scale0 * a[3] + scale1 * tmp[3];
}
