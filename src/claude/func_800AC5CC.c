typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct Xf {
    f32 m[3][4];
    f32 pad30[4];
    f32 t[3];
} Xf;
typedef char assert_xf[(sizeof(Xf) == 0x4C) ? 1 : -1];

void func_800AC5CC(Xf *a, Xf *b, Xf *out, s32 withTranslation) {
    u32 i, j, k;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            out->m[i][j] = 0.0f;
            for (k = 0; k < 3; k++) {
                out->m[i][j] += a->m[i][k] * b->m[k][j];
            }
        }
    }
    if (withTranslation) {
        out->t[0] = b->t[0] + a->t[0] * b->m[0][0] + a->t[1] * b->m[1][0] + a->t[2] * b->m[2][0];
        out->t[1] = b->t[1] + a->t[0] * b->m[0][1] + a->t[1] * b->m[1][1] + a->t[2] * b->m[2][1];
        out->t[2] = b->t[2] + a->t[0] * b->m[0][2] + a->t[1] * b->m[1][2] + a->t[2] * b->m[2][2];
    } else {
        out->t[0] = out->t[1] = out->t[2] = 0.0f;
    }
}
