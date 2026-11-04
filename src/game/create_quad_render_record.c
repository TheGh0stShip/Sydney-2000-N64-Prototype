#ifndef LEAF_NAME
#define LEAF_NAME createQuadRenderRecord
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
typedef unsigned char u8;

typedef struct {
    float x;
    float y;
    float z;
    float auxiliaryX;
    float auxiliaryY;
    float auxiliaryZ;
    s32 index;
    u32 flags;
    float scale;
} QuadVertex;

typedef struct {
    u32 flags;
    u8 padding04[0x4C];
    QuadVertex *vertices;
    u8 padding54[0x14];
    u16 field68;
    u16 field6A;
    void *callback;
    u16 recordType;
    u16 field72;
    u16 field74;
    u16 field76;
} QuadRenderRecord;

extern float compactVertexScale __asm__("D_80000B28");
extern float regularVertexScale __asm__("D_80000B30");
extern float vertexDepth __asm__("D_80000B2C");
extern float vertexDefaultScale __asm__("D_80000B24");
extern void *renderCallback __asm__("D_8005AC8C");

extern s32 CREATE_NAME(u32 count, u16 *format, QuadRenderRecord **output,
                       s32 initialValue);
extern u16 FIND_NAME(u16 type, u32 first, u32 second, u32 third, u32 fourth);

s32 LEAF_NAME(QuadRenderRecord **output, float width, float height, u32 type,
              u32 flags)
{
    u16 format = 4;
    QuadRenderRecord *record;
    QuadVertex *vertices;
    float halfWidth;
    float halfHeight;
    float base;
    s32 i;

    if (CREATE_NAME(1, &format, output, -1) != 0) {
        return -1;
    }

    record = *output;
    vertices = record->vertices;
    for (i = 0; i < 4; i++) {
        vertices[i].index = -1;
        vertices[i].flags = 0;
        vertices[i].scale = vertexDefaultScale;
    }

    if ((flags & 4) != 0) {
        halfWidth = width * compactVertexScale;
        halfHeight = height * compactVertexScale;
        vertices[0].x = -halfWidth;
        vertices[0].y = 0.0f;
        vertices[0].z = halfHeight;
        vertices[1].x = halfWidth;
        vertices[1].y = 0.0f;
        vertices[1].z = halfHeight;
        vertices[2].x = halfWidth;
        vertices[2].y = 0.0f;
        vertices[2].z = -halfHeight;
        vertices[3].x = -halfWidth;
        vertices[3].y = 0.0f;
        vertices[3].z = -halfHeight;
        vertices[0].auxiliaryX = vertices[1].auxiliaryX = 0.0f;
        vertices[2].auxiliaryX = vertices[0].auxiliaryX;
    } else {
        base = vertices[3].z;
        halfWidth = width * regularVertexScale;
        halfHeight = height * regularVertexScale;
        for (i = 0; i < 4; i++) {
            vertices[i].auxiliaryX = base;
            vertices[i].auxiliaryY = base;
            vertices[i].auxiliaryZ = vertexDepth;
        }
        vertices[0].x = base - halfWidth;
        vertices[0].y = halfHeight;
        vertices[0].z = base;
        vertices[1].x = halfWidth;
        vertices[1].y = base;
        vertices[1].z = base;
        vertices[2].x = halfWidth;
        vertices[2].y = base - halfHeight;
        vertices[2].z = base;
        vertices[3].x = base - halfWidth;
        vertices[3].y = base - halfHeight;
        vertices[3].z = base;
    }

    record->field74 = 3;
    record->field6A = 2;
    record->field68 = 0;
    record->callback = renderCallback;
    record->field76 = 3;
    if ((record->flags & 2) != 0) {
        record->recordType = (u16)type;
    } else {
        record->recordType = FIND_NAME((u16)type, 0, 0, 0, 0);
    }
    return 0;
}
