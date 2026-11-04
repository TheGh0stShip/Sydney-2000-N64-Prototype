#ifndef LEAF_NAME
#define LEAF_NAME buildViewLookAtReflection
#endif
#ifndef TRANSFORM_NAME
#define TRANSFORM_NAME transformViewVector
#endif

typedef signed char s8;
typedef unsigned char u8;
typedef signed int s32;

typedef struct {
    float x;
    float y;
    float z;
} Vec3f;

typedef struct {
    u8 col[3];
    s8 pad1;
    u8 colc[3];
    s8 pad2;
    s8 dir[3];
    s8 pad3;
} LookAtLight;

typedef struct {
    LookAtLight light;
    u8 padding0C[4];
} LookAtSlot;

typedef struct {
    LookAtSlot l[2];
} LookAtReflection;

extern void TRANSFORM_NAME(void *view, Vec3f *input, Vec3f *output, s32 mode);

float sqrtf(float value);

void LEAF_NAME(void *view, LookAtReflection *lookAt, Vec3f up) {
    Vec3f forward = {0.0f, 0.0f, 1.0f};
    Vec3f upward = {0.0f, 1.0f, 0.0f};
    Vec3f look;
    float xLook;
    float yLook;
    float zLook;
    float xRight;
    float yRight;
    float zRight;
    float len;
    float scaled;

    TRANSFORM_NAME(view, &forward, &look, 0);
    xLook = look.x;
    yLook = look.y;
    zLook = look.z;

    len = (xLook == 0.0f && yLook == 0.0f && zLook == 0.0f) ? 1.0f : 1.0 / sqrtf(xLook * xLook + yLook * yLook + zLook * zLook);
    xLook *= len;
    yLook *= len;
    zLook *= len;

    xRight = up.y * zLook - up.z * yLook;
    yRight = up.z * xLook - up.x * zLook;
    zRight = up.x * yLook - up.y * xLook;
    len = (xRight == 0.0f && yRight == 0.0f && zRight == 0.0f) ? 1.0f : 1.0 / sqrtf(xRight * xRight + yRight * yRight + zRight * zRight);
    xRight *= len;
    yRight *= len;
    zRight *= len;

    up.x = yLook * zRight - zLook * yRight;
    up.y = zLook * xRight - xLook * zRight;
    up.z = xLook * yRight - yLook * xRight;
    len = (up.x == 0.0f && up.y == 0.0f && up.z == 0.0f) ? 1.0f : 1.0 / sqrtf(up.x * up.x + up.y * up.y + up.z * up.z);
    up.x *= len;
    up.y *= len;
    up.z *= len;

    scaled = xRight * 128.0f;
    lookAt->l[0].light.dir[0] = (scaled < 127.0f) ? (s32)scaled : 127;
    scaled = yRight * 128.0f;
    lookAt->l[0].light.dir[1] = (scaled < 127.0f) ? (s32)scaled : 127;
    scaled = zRight * 128.0f;
    lookAt->l[0].light.dir[2] = (scaled < 127.0f) ? (s32)scaled : 127;
    scaled = up.x * 128.0f;
    lookAt->l[1].light.dir[0] = (scaled < 127.0f) ? (s32)scaled : 127;
    scaled = up.y * 128.0f;
    lookAt->l[1].light.dir[1] = (scaled < 127.0f) ? (s32)scaled : 127;
    scaled = up.z * 128.0f;
    lookAt->l[1].light.dir[2] = (scaled < 127.0f) ? (s32)scaled : 127;

    lookAt->l[0].light.col[0] = 0;
    lookAt->l[0].light.col[1] = 0;
    lookAt->l[0].light.col[2] = 0;
    lookAt->l[0].light.pad1 = 0;
    lookAt->l[0].light.colc[0] = 0;
    lookAt->l[0].light.colc[1] = 0;
    lookAt->l[0].light.colc[2] = 0;
    lookAt->l[0].light.pad2 = 0;
    lookAt->l[1].light.col[0] = 0;
    lookAt->l[1].light.col[1] = 0x80;
    lookAt->l[1].light.col[2] = 0;
    lookAt->l[1].light.pad1 = 0;
    lookAt->l[1].light.colc[0] = 0;
    lookAt->l[1].light.colc[1] = 0x80;
    lookAt->l[1].light.colc[2] = 0;
    lookAt->l[1].light.pad2 = 0;
}
