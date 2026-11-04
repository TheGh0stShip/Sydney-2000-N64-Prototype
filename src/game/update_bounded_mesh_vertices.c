#ifndef LEAF_NAME
#define LEAF_NAME updateBoundedMeshVertices
#endif

#ifndef ABS_NAME
#define ABS_NAME doubleAbsolute
#endif

typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct SourceVertex {
    float x;
    float y;
    float z;
    float normalX;
    float normalY;
    float normalZ;
    float pad18;
    float firstValue;
    float secondValue;
} SourceVertex;

typedef struct OutputVertex {
    s16 x;
    s16 y;
    s16 z;
    u16 flag;
    s16 firstValue;
    s16 secondValue;
    s8 normal[3];
    u8 alpha;
} OutputVertex;

typedef struct OutputBuffer {
    OutputVertex *vertices;
} OutputBuffer;

typedef struct MeshObject {
    u32 flags;
    u8 pad04[0x4C];
    SourceVertex *source;
    OutputBuffer outputs[4];
    u32 count;
    u8 pad68[0xC];
    u16 dirtyMask;
    u8 pad76[2];
    float radius;
} MeshObject;

extern u32 D_8005A93C;

extern double ABS_NAME(double value);

s32 LEAF_NAME(MeshObject *object)
{
    float minimum;
    float maximum;
    float minimumFirst;
    float minimumSecond;
    float firstValue;
    float secondValue;
    SourceVertex *source;
    s32 normal;
    u32 count;
    u32 index;

    minimum = 1e20f;
    maximum = -1e20f;
    minimumFirst = minimum;
    minimumSecond = minimum;

    if (object->dirtyMask == 0) {
        return 0;
    }

    object->dirtyMask &= ~(1 << D_8005A93C);

    /* Find the coordinate extents; the texture minimums are tracked but unused. */
    index = 0;
    source = object->source;
    if (object->count != 0) {
        count = object->count;
        do {
            if (maximum < source->x) {
                maximum = source->x;
            }
            if (maximum < source->y) {
                maximum = source->y;
            }
            if (maximum < source->z) {
                maximum = source->z;
            }
            if (source->x < minimum) {
                minimum = source->x;
            }
            if (source->y < minimum) {
                minimum = source->y;
            }
            if (source->z < minimum) {
                minimum = source->z;
            }
            if (source->firstValue < minimumFirst) {
                minimumFirst = source->firstValue;
            }
            if (source->secondValue < minimumSecond) {
                minimumSecond = source->secondValue;
            }
            index++;
            source++;
        } while (index < count);
    }

    /* The bounding radius uses the larger of the two extents. */
    minimum = ABS_NAME(minimum);
    if (minimum < maximum) {
        minimum = maximum;
    }
    object->radius = minimum * 1.733;

    /* Small meshes are scaled up and flagged; the maximum becomes the scale. */
    if (maximum < 64.0f) {
        maximum = 64.0f;
        object->flags |= 8;
    } else {
        maximum = 1.0f;
    }

    source = object->source;
    for (index = 0; index < object->count; index++, source++) {
        object->outputs[D_8005A93C].vertices[index].alpha = 0xFF;
        object->outputs[D_8005A93C].vertices[index].flag = 0;
        object->outputs[D_8005A93C].vertices[index].x = source->x * maximum;
        object->outputs[D_8005A93C].vertices[index].y = source->y * maximum;
        object->outputs[D_8005A93C].vertices[index].z = source->z * maximum;

        /* Normals clamp to a signed byte; 0x80 stores as -128. */
        normal = source->normalX * 127.0;
        if (normal > 127) {
            normal = 127;
        }
        if (normal < -128) {
            normal = 0x80;
        }
        object->outputs[D_8005A93C].vertices[index].normal[0] = normal;

        normal = source->normalY * 127.0;
        if (normal > 127) {
            normal = 127;
        }
        if (normal < -128) {
            normal = 0x80;
        }
        object->outputs[D_8005A93C].vertices[index].normal[1] = normal;

        normal = source->normalZ * 127.0;
        if (normal > 127) {
            normal = 127;
        }
        if (normal < -128) {
            normal = 0x80;
        }
        object->outputs[D_8005A93C].vertices[index].normal[2] = normal;

        firstValue = source->firstValue;
        secondValue = 1.0 - source->secondValue;
        if (firstValue > 15.0) {
            firstValue = 15.0f;
        }
        if (secondValue > 15.0) {
            secondValue = 15.0f;
        }
        firstValue *= 2048.0f;
        secondValue *= 2048.0f;
        object->outputs[D_8005A93C].vertices[index].firstValue = firstValue;
        object->outputs[D_8005A93C].vertices[index].secondValue = secondValue;
    }

    return 0;
}
