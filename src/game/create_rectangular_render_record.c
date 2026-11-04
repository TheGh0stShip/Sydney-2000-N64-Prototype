#ifndef LEAF_NAME
#define LEAF_NAME createRectangularRenderRecord
#endif
#ifndef CREATE_NAME
#define CREATE_NAME createRenderRecord
#endif
#ifndef FIND_NAME
#define FIND_NAME findRenderRecord
#endif

typedef signed int s32;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    float x;
    float y;
    float z;
    u32 first;
    float scale;
    u32 second;
    s32 index;
    u32 textureU;
    float textureV;
} RectangleVertex;

typedef struct {
    u32 flags;
    unsigned char padding04[0x4C];
    RectangleVertex *vertices;
    unsigned char padding54[0x14];
    u16 firstMode;
    u16 secondMode;
    void *callback;
    u16 recordType;
    u16 field72;
    u16 thirdMode;
} RectangleObject;

extern float rectangleUnitScale __asm__("D_80000B34");
extern void rectangleCallback(void) __asm__("D_8005AC8C");

extern s32 CREATE_NAME(u32, u16 *, RectangleObject **, s32);
extern u32 FIND_NAME(u16, u32, u32, u32, u32);

s32 LEAF_NAME(RectangleObject **output, float width, float depth,
              float originX, float originZ, u16 type, u32 flags)
{
    RectangleVertex *vertices;
    RectangleObject *object;
    u16 kind = 4;
    u32 i;
    s32 status;

    status = CREATE_NAME(1, &kind, output, -1);
    if (status != 0) {
        return status;
    }

    object = *output;
    vertices = object->vertices;
    for (i = 0; i < 4; i++) {
        vertices[i].index = -1;
        vertices[i].first = 0;
        vertices[i].scale = rectangleUnitScale;
        vertices[i].second = 0;
    }
    vertices[0].textureU = 0;
    vertices[0].textureV = rectangleUnitScale;
    vertices[1].textureU = 0;
    vertices[1].textureV = rectangleUnitScale;
    vertices[2].textureU = 0;
    vertices[2].textureV = 0.0f;
    vertices[3].textureU = 0;
    vertices[3].textureV = 0.0f;

    vertices[0].x = originX;
    vertices[1].x = originX + width;
    vertices[2].x = originX + width;
    vertices[3].x = originX;
    if (flags & 4) {
        vertices[0].y = 0.0f;
        vertices[1].y = 0.0f;
        vertices[2].y = 0.0f;
        vertices[3].y = 0.0f;
        vertices[0].z = originZ;
        vertices[1].z = originZ;
        vertices[2].z = originZ + depth;
        vertices[3].z = originZ + depth;
    } else {
        vertices[0].y = originZ;
        vertices[1].y = originZ;
        vertices[2].y = originZ + depth;
        vertices[3].y = originZ + depth;
        vertices[0].z = 0.0f;
        vertices[1].z = 0.0f;
        vertices[2].z = 0.0f;
        vertices[3].z = 0.0f;
    }

    object->thirdMode = 3;
    object->secondMode = 2;
    object->firstMode = 0;
    object->callback = rectangleCallback;
    object->field72 = 3;
    if (object->flags & 2) {
        object->recordType = type;
    } else {
        object->recordType = FIND_NAME(type, 0, 0, 0, 0);
    }
    object->thirdMode = 3;
    return 0;
}
