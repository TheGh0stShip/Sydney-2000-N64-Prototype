#include "guint.h"

void guMtxCatF(float mf[4][4], float nf[4][4], float result[4][4]) {
    int i;
    int j;
    int k;
    float temporary[4][4];

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            temporary[i][j] = 0.0f;
            for (k = 0; k < 4; k++) {
                temporary[i][j] += mf[i][k] * nf[k][j];
            }
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            result[i][j] = temporary[i][j];
        }
    }
}
