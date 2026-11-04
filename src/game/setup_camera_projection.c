#ifndef LEAF_NAME
#define LEAF_NAME setupCameraProjection
#endif
#ifndef TRANSLATE_F_NAME
#define TRANSLATE_F_NAME guTranslateF
#endif
#ifndef CONCAT_NAME
#define CONCAT_NAME guMtxCatF
#endif
#ifndef SCALE_F_NAME
#define SCALE_F_NAME guScaleF
#endif
#ifndef FLOAT_TO_FIXED_NAME
#define FLOAT_TO_FIXED_NAME guMtxF2L
#endif
#ifndef FIXED_TO_FLOAT_NAME
#define FIXED_TO_FLOAT_NAME guMtxL2F
#endif
#ifndef SINE_NAME
#define SINE_NAME sinf
#endif
#ifndef COSINE_NAME
#define COSINE_NAME cosf
#endif
#ifndef PERSPECTIVE_NAME
#define PERSPECTIVE_NAME guPerspective
#endif
#ifndef LOOKAT_NAME
#define LOOKAT_NAME buildCameraLookAt
#endif
#ifndef TRANSLATE_NAME
#define TRANSLATE_NAME guTranslate
#endif

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 words[16];
} Mtx;

typedef struct {
    u32 words[8];
} LookAt;

typedef struct {
    u32 command;
    u32 value;
} Gfx;

typedef struct {
    float rotation[3][4];
    float padding30[4];
    float position[3];
} Camera;

extern Gfx *displayListHead __asm__("D_800663DC");
extern int frameBufferIndex __asm__("D_8005A93C");
extern float viewMatrix[4][4] __asm__("D_80069050");
extern float translationMatrix[4][4] __asm__("D_80069090");
extern float rotatedMatrix[4][4] __asm__("D_800690D0");
extern float flipMatrix[4][4] __asm__("D_80069110");
extern u16 perspectiveNormal __asm__("D_80069040");
extern Mtx projectionMatrices[2][3] __asm__("D_80068C40");
extern Mtx viewMatrices[2][3] __asm__("D_80068DC0");
extern LookAt lookAts[2][3] __asm__("D_80068F80");
extern Mtx objectIdentityMatrix __asm__("D_80068F40");
extern float combinedMatrices[][4][4] __asm__("D_8005A538");
extern Gfx sceneSetupList[] __asm__("D_80065F38");
extern const float matrixOne __asm__("D_800006B8");
extern const double fieldOfViewBias __asm__("D_800006C0");
extern const float halfScale __asm__("D_800006C8");
extern const float radiansToDegrees __asm__("D_800006CC");
extern const float farPlane __asm__("D_800006D0");

extern void TRANSLATE_F_NAME(float matrix[4][4], float x, float y, float z);
extern void CONCAT_NAME(float a[4][4], float b[4][4], float result[4][4]);
extern void SCALE_F_NAME(float matrix[4][4], float x, float y, float z);
extern void FLOAT_TO_FIXED_NAME(float source[4][4], Mtx *destination);
extern void FIXED_TO_FLOAT_NAME(float destination[4][4], Mtx *source);
extern float SINE_NAME(float angle);
extern float COSINE_NAME(float angle);
extern void PERSPECTIVE_NAME(Mtx *matrix, u16 *normal, float fovy, float aspect,
                             float near, float far, float scale);
extern void LOOKAT_NAME(Camera *camera, LookAt *lookAt, float upX, float upY, float upZ);
extern void TRANSLATE_NAME(Mtx *matrix, float x, float y, float z);

void LEAF_NAME(int unused0, int unused1, Camera *camera, float fieldOfView, int view)
{
    float halfAngle;
    float nearPlane;
    Gfx *command;

    viewMatrix[0][0] = camera->rotation[0][0];
    viewMatrix[0][1] = camera->rotation[1][0];
    viewMatrix[0][2] = camera->rotation[2][0];
    viewMatrix[1][0] = camera->rotation[0][1];
    viewMatrix[1][1] = camera->rotation[1][1];
    viewMatrix[1][2] = camera->rotation[2][1];
    viewMatrix[2][0] = camera->rotation[0][2];
    viewMatrix[2][1] = camera->rotation[1][2];
    viewMatrix[2][2] = camera->rotation[2][2];
    viewMatrix[0][3] = viewMatrix[1][3] = viewMatrix[2][3] = 0.0f;
    viewMatrix[3][0] = 0.0f;
    viewMatrix[3][1] = 0.0f;
    viewMatrix[3][2] = 0.0f;
    viewMatrix[3][3] = matrixOne;

    TRANSLATE_F_NAME(translationMatrix, -camera->position[0], -camera->position[1],
                     -camera->position[2]);
    CONCAT_NAME(translationMatrix, viewMatrix, rotatedMatrix);
    SCALE_F_NAME(flipMatrix, matrixOne, matrixOne, -1.0f);
    CONCAT_NAME(rotatedMatrix, flipMatrix, viewMatrix);
    FLOAT_TO_FIXED_NAME(viewMatrix, &viewMatrices[frameBufferIndex][view]);

    fieldOfView = (float)((double)fieldOfView + fieldOfViewBias);
    halfAngle = fieldOfView * halfScale;
    nearPlane = SINE_NAME(halfAngle) * 2;
    nearPlane = nearPlane / COSINE_NAME(halfAngle);
    if (nearPlane < matrixOne) {
        nearPlane = matrixOne;
    }
    PERSPECTIVE_NAME(&projectionMatrices[frameBufferIndex][view], &perspectiveNormal,
                     fieldOfView * radiansToDegrees, 1.1f, nearPlane, farPlane, matrixOne);
    perspectiveNormal *= 100;
    LOOKAT_NAME(camera, &lookAts[frameBufferIndex][view], 0.0f, matrixOne, 0.0f);

    command = displayListHead++;
    command->command = 0xDC08000A;
    command->value = (u32)&lookAts[frameBufferIndex][view].words[0];
    command = displayListHead++;
    command->command = 0xDC08030A;
    command->value = (u32)&lookAts[frameBufferIndex][view].words[4];
    command = displayListHead++;
    command->command = 0xDB0E0000;
    command->value = perspectiveNormal;
    command = displayListHead++;
    command->command = 0xDA380007;
    command->value = (u32)&projectionMatrices[frameBufferIndex][view];
    command = displayListHead++;
    command->command = 0xDA380005;
    command->value = (u32)&viewMatrices[frameBufferIndex][view];

    FIXED_TO_FLOAT_NAME(viewMatrix, &viewMatrices[frameBufferIndex][view]);
    FIXED_TO_FLOAT_NAME(translationMatrix, &projectionMatrices[frameBufferIndex][view]);
    CONCAT_NAME(viewMatrix, translationMatrix, combinedMatrices[view]);

    command = displayListHead++;
    command->command = 0xE7000000;
    command->value = 0;
    TRANSLATE_NAME(&objectIdentityMatrix, 0.0f, 0.0f, 0.0f);
    command = displayListHead++;
    command->command = 0xDA380003;
    command->value = (u32)&objectIdentityMatrix;
    command = displayListHead++;
    command->command = 0xDE000000;
    command->value = (u32)sceneSetupList;
    command = displayListHead++;
    command->command = 0xE200001C;
    command->value = 0x00552078;
}
