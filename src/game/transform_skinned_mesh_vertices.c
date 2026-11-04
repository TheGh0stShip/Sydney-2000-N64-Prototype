#ifndef LEAF_NAME
#define LEAF_NAME transformSkinnedMeshVertices
#endif

typedef signed int s32;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    float rotation[4][4];
    float translation[3];
} BoneTransform;

typedef struct {
    u32 padding00;
    u8 *bone;
    float *position;
    u8 padding0C[0x14];
} SkinVertex;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    u8 padding06[0xA];
} OutputVertex;

typedef struct {
    u32 padding00[2];
    OutputVertex *vertices;
    u32 padding0C[2];
} VertexGroup;

typedef struct {
    u32 vertexCount;
    SkinVertex *sourceVertices;
    u32 groupCount;
    VertexGroup *groups;
    u16 *groupStarts;
    u32 padding14;
} SkinnedMesh;

typedef struct {
    u32 padding00;
    OutputVertex *buffers[7];
    SkinnedMesh *meshes;
} SkinnedModel;

typedef struct {
    u8 padding000[0xC4];
    SkinnedModel *model;
    u8 padding0C8[0x98];
    BoneTransform *bones;
} SkinnedObject;

extern const float groupVertexScale __asm__("D_80000600");
extern const float finalVertexScale __asm__("D_80000604");

/* Skins one mesh into a vertex buffer; the last group uses its own scale. */
s32 LEAF_NAME(SkinnedObject *object, s32 meshIndex, s32 bufferIndex)
{
    SkinnedModel *model = object->model;
    SkinnedMesh *mesh = &model->meshes[meshIndex];
    u8 *buffer = (u8 *)model->buffers[bufferIndex] -
                 (u32)model->meshes->groups->vertices;
    float scale;
    u32 lastGroup = mesh->groupCount - 1;
    u32 end;
    u32 group;
    s32 remaining;
    SkinVertex *source;
    OutputVertex *output;
    BoneTransform *bone;
    float *position;
    float result[3];

    scale = groupVertexScale;
    end = mesh->groupStarts[0];
    for (group = 0;; group++) {
        u32 start = end;

        if (group >= lastGroup) {
            break;
        }
        source = &mesh->sourceVertices[start];
        end = mesh->groupStarts[group + 1];
        output = (OutputVertex *)(buffer +
                                  (u32)mesh->groups[group].vertices);
        remaining = end - start;
        do {
            bone = &object->bones[*source->bone];
            result[0] = bone->translation[0];
            position = source->position;
            result[0] += position[0] * bone->rotation[0][0] +
                         position[1] * bone->rotation[1][0] +
                         position[2] * bone->rotation[2][0];
            result[1] = bone->translation[1];
            result[1] += position[0] * bone->rotation[0][1] +
                         position[1] * bone->rotation[1][1] +
                         position[2] * bone->rotation[2][1];
            result[2] = bone->translation[2];
            result[2] += position[0] * bone->rotation[0][2] +
                         position[1] * bone->rotation[1][2] +
                         position[2] * bone->rotation[2][2];
            output->x = result[0] * scale;
            output->y = result[1] * scale;
            output->z = result[2] * scale;
            source++;
            output++;
        } while (--remaining);
    }

    scale = finalVertexScale;
    source = &mesh->sourceVertices[end];
    remaining = mesh->vertexCount - end;
    output = (OutputVertex *)(buffer +
                              (u32)mesh->groups[group].vertices);
    do {
        bone = &object->bones[*source->bone];
        result[0] = bone->translation[0];
        position = source->position;
        result[0] += position[0] * bone->rotation[0][0] +
                     position[1] * bone->rotation[1][0] +
                     position[2] * bone->rotation[2][0];
        result[1] = bone->translation[1];
        result[1] += position[0] * bone->rotation[0][1] +
                     position[1] * bone->rotation[1][1] +
                     position[2] * bone->rotation[2][1];
        result[2] = bone->translation[2];
        result[2] += position[0] * bone->rotation[0][2] +
                     position[1] * bone->rotation[1][2] +
                     position[2] * bone->rotation[2][2];
        output->x = result[0] * scale;
        output->y = result[1] * scale;
        output->z = result[2] * scale;
        source++;
        output++;
    } while (--remaining);

    return 0;
}
