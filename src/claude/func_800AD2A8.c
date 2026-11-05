typedef float f32;
typedef int s32;

/* 3x4 rotation rows (stride 0x10) followed by a translation row at +0x40. */
typedef struct {
    f32 rot[4][4];  /* 0x00 */
    f32 trans[4];   /* 0x40 */
} TransformMtx;
typedef char assert_TransformMtx_size[(sizeof(TransformMtx) == 0x50) ? 1 : -1];

void func_800AD2A8(TransformMtx *m, f32 *v, f32 *out, s32 addTranslation)
{
    if (addTranslation) {
        out[0] = m->trans[0];
        out[1] = m->trans[1];
        out[2] = m->trans[2];
    } else {
        out[0] = out[1] = out[2] = 0.0f;
    }
    out[0] += v[0] * m->rot[0][0] + (v[1] * m->rot[1][0] + v[2] * m->rot[2][0]);
    out[1] += v[0] * m->rot[0][1] + (v[1] * m->rot[1][1] + v[2] * m->rot[2][1]);
    out[2] += v[0] * m->rot[0][2] + (v[1] * m->rot[1][2] + v[2] * m->rot[2][2]);
}
