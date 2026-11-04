#ifndef LEAF_NAME
#define LEAF_NAME translateObjectGeometry
#endif

typedef signed int s32;
typedef signed short s16;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    u8 padding06[10];
} GeometryVertex;

typedef struct {
    u8 coordinates[0x68];
    u8 entryCount;
    u8 padding69[7];
} GeometryGroup;

typedef struct {
    u8 padding00[4];
    u32 groupCount;
    u8 padding08[4];
    GeometryGroup *groups;
    u8 padding10[12];
    GeometryVertex *vertices;
    u8 padding20[8];
    u32 flags;
    u8 padding2C[28];
    u32 firstVertex;
    u32 lastVertex;
} GeometryObject;

extern const float geometryScale __asm__("D_80000610");

void LEAF_NAME(GeometryObject *object, float x, float y, float z)
{
    s32 ix;
    s32 iy;
    s32 iz;
    u32 i;
    u32 j;
    u32 k;

    if (object->flags & 4) {
        ix = (u16)(s32)x << 6;
        iy = (u16)(s32)y << 6;
        iz = (u16)(s32)z << 6;
    } else {
        ix = (s32)x;
        iy = (s32)y;
        iz = (s32)z;
    }

    for (i = object->firstVertex; i <= object->lastVertex; i++) {
        object->vertices[i].x -= ix;
        object->vertices[i].y -= iy;
        object->vertices[i].z -= iz;
    }

    if (object->groupCount != 0) {
        ix = (s32)(x * geometryScale);
        iy = (s32)(y * geometryScale);
        iz = (s32)(z * geometryScale);
        for (i = 0; i < object->groupCount; i++) {
            GeometryGroup *group = &object->groups[i];
            for (j = 0; j < group->entryCount; j++) {
                u8 *entry = group->coordinates + j * 8;
                ((u16 *)entry)[0] -= ix;
                ((u16 *)entry)[1] -= iy;
                ((u16 *)entry)[2] -= iz;
                for (k = 0; k < 2; k++) {
                    u8 *extra = group->coordinates + j * 12 + k * 6 + 0x20;
                    ((u16 *)extra)[0] -= ix;
                    ((u16 *)extra)[1] -= iy;
                    ((u16 *)extra)[2] -= iz;
                }
            }
        }
    }
}
