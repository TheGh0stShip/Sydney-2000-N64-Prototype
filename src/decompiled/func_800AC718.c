#include "sydney_types.h"

/* Convert the rotation part of a 4x4 matrix to a quaternion (x, y, z, w). */
typedef struct { f32 m[4][4]; } MtxF;
f32 sqrtf(f32);
void func_800AC718(MtxF *mf, f32 *out) {
    f32 q[4];
    s32 nxt[3] = { 1, 2, 0 };
    f32 tr, s;
    s32 i, j, k;
    tr = mf->m[0][0] + mf->m[1][1] + mf->m[2][2];
    if (tr > 0.0f) {
        tr += 1.0f;
        s = sqrtf(tr);
        q[3] = s * 0.5f;
        s = 0.5f / s;
        q[0] = (mf->m[1][2] - mf->m[2][1]) * s;
        q[1] = (mf->m[2][0] - mf->m[0][2]) * s;
        q[2] = (mf->m[0][1] - mf->m[1][0]) * s;
    } else {
        i = 0;
        if (mf->m[1][1] > mf->m[0][0]) i = 1;
        if (mf->m[2][2] > mf->m[i][i]) i = 2;
        j = nxt[i];
        k = nxt[j];
        s = sqrtf((mf->m[i][i] - (mf->m[j][j] + mf->m[k][k])) + 1.0f);
        q[i] = s * 0.5f;
        if (s != 0.0f) s = 0.5f / s;
        q[3] = (mf->m[j][k] - mf->m[k][j]) * s;
        q[j] = (mf->m[i][j] + mf->m[j][i]) * s;
        q[k] = (mf->m[i][k] + mf->m[k][i]) * s;
    }
    out[0] = q[0];
    out[1] = q[1];
    out[2] = q[2];
    out[3] = q[3];
}
