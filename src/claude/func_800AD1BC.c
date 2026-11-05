typedef float f32;

/* Quaternion (x, y, z, w) to rotation matrix; translation row cleared. */
void func_800AD1BC(f32 *q, f32 *m)
{
    f32 xs, ys, zs;
    f32 xx, xy, xz, yy, yz, zz, wx, wy, wz;

    xs = q[0] + q[0];
    xx = q[0] * xs;
    ys = q[1] + q[1];
    xy = q[0] * ys;
    zs = q[2] + q[2];
    xz = q[0] * zs;
    yy = q[1] * ys;
    yz = q[1] * zs;
    zz = q[2] * zs;
    wx = q[3] * xs;
    wy = q[3] * ys;
    wz = q[3] * zs;

    m[0] = 1.0f - (yy + zz);
    m[4] = xy - wz;
    m[8] = xz + wy;
    m[1] = xy + wz;
    m[5] = 1.0f - (xx + zz);
    m[9] = yz - wx;
    m[2] = xz - wy;
    m[6] = yz + wx;
    m[10] = 1.0f - (xx + yy);
    m[16] = m[17] = m[18] = 0.0f;
}
