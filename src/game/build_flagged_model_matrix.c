#ifndef LEAF_NAME
#define LEAF_NAME buildFlaggedModelMatrix
#endif
#ifndef FLOAT_TO_FIXED_NAME
#define FLOAT_TO_FIXED_NAME guMtxF2L
#endif

typedef unsigned int u32;

typedef struct {
    u32 words[16];
} Mtx;

typedef struct {
    u32 command;
    u32 value;
} Gfx;

extern float modelMatrix[4][4] __asm__("D_80068B80");
extern float modelTranslation[3] __asm__("D_8005A52C");
extern const double firstMatrixScale __asm__("D_80000670");
extern const double secondMatrixScale __asm__("D_80000678");
extern const float matrixOne __asm__("D_80000680");

extern void FLOAT_TO_FIXED_NAME(float source[4][4], Mtx *destination);

void LEAF_NAME(Gfx **displayList, float source[4][4], Mtx *matrix, u32 flags)
{
    u32 row;
    u32 column;
    Gfx *command;

    modelMatrix[0][0] = source[0][0];
    modelMatrix[0][1] = source[0][1];
    modelMatrix[0][2] = source[0][2];
    modelMatrix[1][0] = source[1][0];
    modelMatrix[1][1] = source[1][1];
    modelMatrix[1][2] = source[1][2];
    modelMatrix[2][0] = source[2][0];
    modelMatrix[2][1] = source[2][1];
    modelMatrix[2][2] = source[2][2];

    if (flags & 2) {
        for (row = 0; row < 3; row++) {
            for (column = 0; column < 3; column++) {
                modelMatrix[row][column] =
                    (float)((double)modelMatrix[row][column] * firstMatrixScale);
            }
        }
    }
    if (flags & 4) {
        for (row = 0; row < 3; row++) {
            for (column = 0; column < 3; column++) {
                modelMatrix[row][column] =
                    (float)((double)modelMatrix[row][column] * secondMatrixScale);
            }
        }
    }

    modelMatrix[0][3] = 0.0f;
    modelMatrix[1][3] = 0.0f;
    modelMatrix[2][3] = 0.0f;
    modelMatrix[3][3] = matrixOne;
    modelMatrix[3][0] = source[3][0];
    modelMatrix[3][1] = source[3][1];
    modelMatrix[3][2] = source[3][2];
    modelTranslation[0] = source[3][0];
    modelTranslation[1] = source[3][1];
    modelTranslation[2] = source[3][2];

    FLOAT_TO_FIXED_NAME(modelMatrix, matrix);
    command = *displayList;
    *displayList = command + 1;
    command->command = 0xDA380003;
    command->value = (u32)matrix;
}
