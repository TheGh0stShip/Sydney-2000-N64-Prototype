typedef float f32;

typedef struct Xf {
    f32 m[3][4];
    f32 pad30[4];
    f32 t[3];
} Xf;

void func_800AC480(Xf *in, Xf *out)
{
    f32 a, b, c;
    f32 s = in->m[0][0] * in->m[0][0] + in->m[0][1] * in->m[0][1] + in->m[0][2] * in->m[0][2];

    if (s != 0.0f) {
        s = 1.0f / s;
        out->m[0][0] = s * in->m[0][0];
        out->m[1][0] = s * in->m[0][1];
        out->m[2][0] = s * in->m[0][2];
        out->m[0][1] = s * in->m[1][0];
        out->m[1][1] = s * in->m[1][1];
        out->m[2][1] = s * in->m[1][2];
        out->m[0][2] = s * in->m[2][0];
        out->m[1][2] = s * in->m[2][1];
        out->m[2][2] = s * in->m[2][2];
        a = out->m[0][0] * in->t[0];
        b = out->m[1][0] * in->t[1];
        c = out->m[2][0] * in->t[2];
        out->t[0] = -(a + b + c);
        a = out->m[0][1] * in->t[0];
        b = out->m[1][1] * in->t[1];
        c = out->m[2][1] * in->t[2];
        out->t[1] = -(a + b + c);
        a = out->m[0][2] * in->t[0];
        b = out->m[1][2] * in->t[1];
        c = out->m[2][2] * in->t[2];
        out->t[2] = -(a + b + c);
    }
}
