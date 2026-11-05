/* Exact func_80009D70: skin vertices and pack lighting or normals.
 * This reconstructed translation-unit fragment retains the preceding DLISTANO
 * tag: its terminator/alignment places the first float at 0x800005C4 and the
 * first double at 0x800005C8. Code and the full constant section are verified.
 * Structure field names remain provisional.
 */
const char skinDisplayListTag[] = "DLISTANO";

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u32 word0;
    u32 word1;
} DisplayCommand;

typedef struct {
    float matrix[4][4];
    float position[3];
} ObjectTransform;

typedef struct {
    s16 ob[3];
    u16 flag;
    s16 tc[2];
    u8 cn[4];
} Vtx;

typedef struct {
    u32 influenceCount;
    u8 *boneIndices;
    float (*positions)[3];
    float *weights;
    u32 unk10;
    float normal[3];
} SkinVertex;

typedef struct {
    u8 padding00[8];
    u32 vertexOffset;
    u8 padding0C[8];
} SkinGroup;

typedef struct {
    u32 vertexCount;
    SkinVertex *vertices;
    u32 groupCount;
    SkinGroup *groups;
    u16 *groupStarts;
    u32 flags;
} SkinLevel;

typedef struct {
    u32 count;
    u8 *vertexBuffers[7];
    SkinLevel *levels;
    float lowerDistances[4];
    float upperDistances[4];
    DisplayCommand *displayLists[4];
} SkinModel;

typedef struct {
    u32 type;
    u8 padding04[0x10];
    ObjectTransform transform;
    u8 padding60[0x64];
    SkinModel *model;
    u8 paddingC8[0x98];
    ObjectTransform *bones;
} SkinObject;

typedef struct {
    float x;
    float y;
    float z;
} CameraState;

typedef char skin_pointer_width[sizeof(void *) == 4 ? 1 : -1];
typedef char skin_vertex_size[sizeof(Vtx) == 16 ? 1 : -1];
typedef char skin_transform_size[sizeof(ObjectTransform) == 0x4C ? 1 : -1];

extern u32 vertexShadingEnabled __asm__("D_800456BC");
extern CameraState camera __asm__("D_8005B6D0");

extern void func_800AD6D0(float *source, float *output);
extern void func_800AD2A8(ObjectTransform *transform, float *input, float *output, s32 mode);

#define SKIN_LOOP(scale, normalScale)                                                    \
    for (group = 0;; group++) {                                                          \
        u8 *buffer;                                                                       \
        if (group >= level->groupCount) break;                                            \
        start = level->groupStarts[group];                                                \
        if (group < level->groupCount - 1) {                                              \
            end = level->groupStarts[group + 1];                                          \
        } else {                                                                          \
            end = level->vertexCount;                                                     \
        }                                                                                 \
        index = start;                                                                    \
        vertex = &level->vertices[index];                                                 \
        buffer = model->vertexBuffers[segment];                                           \
        vtx = (Vtx *)(buffer + level->groups[group].vertexOffset                          \
                      - model->levels->groups->vertexOffset);                             \
        for (;; vtx++, index++, vertex++) {                                               \
            u32 k;                                                                        \
            if (index >= end) break;                                                      \
            sum[0] = sum[1] = sum[2] = 0.0f;                                              \
                                                                            \
            k = level->vertices[index].influenceCount;                                              \
            for (;;) {                                                                    \
                float *out;                                                               \
                if (k-- == 0) break;                                                      \
                out = point;                                                              \
                local[0] = vertex->positions[k][0];                                       \
                local[1] = vertex->positions[k][1];                                       \
                local[2] = vertex->positions[k][2];                                       \
                weight = vertex->weights[k];                                              \
                bone = (ObjectTransform *)(vertex->boneIndices[k] * sizeof(ObjectTransform) + (u32)object->bones); \
                point[0] = bone->position[0];                                               \
                point[0] += local[0] * bone->matrix[0][0] + local[1] * bone->matrix[1][0]  \
                          + local[2] * bone->matrix[2][0];                                \
                out[1] = bone->position[1];                                               \
                out[1] += local[0] * bone->matrix[0][1] + local[1] * bone->matrix[1][1]  \
                          + local[2] * bone->matrix[2][1];                                \
                out[2] = bone->position[2];                                               \
                out[2] += local[0] * bone->matrix[0][2] + local[1] * bone->matrix[1][2]  \
                          + local[2] * bone->matrix[2][2];                                \
                sum[0] += point[0] * weight;                                                \
                sum[1] += point[1] * weight;                                                \
                sum[2] += point[2] * weight;                                                \
            }                                                                             \
            vtx->ob[0] = sum[0] * scale;                                                  \
            vtx->ob[1] = sum[1] * scale;                                                  \
            vtx->ob[2] = sum[2] * scale;                                                  \
            func_800AD2A8(&object->bones[vertex->boneIndices[0]], vertex->normal, normal, 0); \
            if (vertexShadingEnabled) {                                                   \
                shade = light[0] * normal[0] + light[1] * normal[1] + light[2] * normal[2]; \
                shade += 1.0;                                                             \
                color = shade * 127.0;                                                    \
                vtx->cn[0] = color;                                                       \
                vtx->cn[1] = color;                                                       \
                vtx->cn[2] = color;                                                       \
            } else {                                                                      \
                normal[0] *= normalScale;                                                 \
                normal[1] *= normalScale;                                                 \
                normal[2] *= normalScale;                                                 \
                vtx->cn[0] = (s8)normal[0];                                               \
                vtx->cn[1] = (s8)normal[1];                                               \
                vtx->cn[2] = (s8)normal[2];                                               \
            }                                                                             \
        }                                                                                 \
    }

s32 func_80009D70(SkinObject *object, u32 levelIndex, u32 segment)
{
    float point[3];
    float local[3];
    float normal[3];
    float sum[3];
    float rotated[3];
    float (*matrix)[4];
    float light[3];
    SkinModel *model;
    SkinLevel *level;
    DisplayCommand *commands;
    SkinVertex *vertex;
    Vtx *vtx;
    u32 group;
    u32 index;
    u32 end;
    float weight;
    ObjectTransform *bone;
    u32 start;
    float shade;
    s32 color;

    model = object->model;
    commands = model->displayLists[levelIndex];
    commands += 2;
    level = &model->levels[levelIndex];
    if (vertexShadingEnabled) {
        light[0] = -(object->transform.position[0] - camera.x);
        light[1] = -(object->transform.position[1] - camera.y);
        light[2] = -(object->transform.position[2] - camera.z);
        matrix = object->transform.matrix;
        rotated[2] = 0.0f;
        rotated[1] = 0.0f;
        rotated[0] = 0.0f;
        rotated[0] += light[0] * matrix[0][0] + (light[1] * matrix[0][1] + light[2] * matrix[0][2]);
        rotated[1] += light[0] * matrix[1][0] + (light[1] * matrix[1][1] + light[2] * matrix[1][2]);
        rotated[2] += light[0] * matrix[2][0] + (light[1] * matrix[2][1] + light[2] * matrix[2][2]);
        func_800AD6D0(rotated, light);
        commands->word0 = 0xD9FDFFFF;
        commands->word1 = 0;
    } else {
        commands->word0 = 0xD9FFFFFF;
        commands->word1 = 0x20000;
    }
    if (level->flags == 0) {
        SKIN_LOOP(64.0f, 126.0)
        return 0;
    } else {
        SKIN_LOOP(64.0f, 126.0)
        return 0;
    }
}
