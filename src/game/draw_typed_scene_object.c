#ifndef LEAF_NAME
#define LEAF_NAME drawTypedSceneObject
#endif
#ifndef CHECK_NAME
#define CHECK_NAME objectIsExcluded
#endif
#ifndef MATRIX_NAME
#define MATRIX_NAME buildFlaggedModelMatrix
#endif
#ifndef POSE_NAME
#define POSE_NAME computeSkeletonPose
#endif
#ifndef SKIN_NAME
#define SKIN_NAME applySkeletonPose
#endif
#ifndef SKIN_PART_NAME
#define SKIN_PART_NAME applySkeletonPartPose
#endif
#ifndef WATER_BEGIN_NAME
#define WATER_BEGIN_NAME beginWaterSurface
#endif
#ifndef WATER_UPDATE_NAME
#define WATER_UPDATE_NAME updateWaterSurface
#endif
#ifndef WATER_PREPARE_NAME
#define WATER_PREPARE_NAME prepareWaterSurface
#endif
#ifndef WATER_VERTEX_NAME
#define WATER_VERTEX_NAME updateWaterVertices
#endif
#ifndef PREPARE_NAME
#define PREPARE_NAME prepareRenderState
#endif
#ifndef CULL_NAME
#define CULL_NAME setCullingOrigin
#endif
#ifndef DRAW_NAME
#define DRAW_NAME drawRenderObject
#endif
#ifndef FINISH_NAME
#define FINISH_NAME finishRenderCommands
#endif
#ifndef BATCH_NAME
#define BATCH_NAME renderRuntimeObjectBatch
#endif
#ifndef UPDATE_NAME
#define UPDATE_NAME updateRenderObject
#endif
#ifndef TEST_NAME
#define TEST_NAME testRenderObjectPlanes
#endif
#ifndef APPLY_NAME
#define APPLY_NAME applyRenderObjectState
#endif
#ifndef SCALED_MATRIX_NAME
#define SCALED_MATRIX_NAME buildScaledModelMatrix
#endif

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 w0;
    u32 w1;
} DisplayWords;

typedef union {
    DisplayWords words;
    long long alignment;
} DisplayCommand;

typedef struct {
    u8 data[0x40];
} Mtx;

typedef struct SkeletonModel {
    u32 flags;
    u32 segments[4];
    u8 padding14[0x04];
    void *setupList;
    u8 padding1C[0x28];
    u8 *poseLists[1];
} SkeletonModel;

typedef struct WaterModel {
    u8 padding00[0x20];
    u32 hasWaves;
    u8 padding24[0x38];
    void *displayLists[2];
} WaterModel;

typedef struct RenderObject {
    u32 flags;
    u8 padding04[0x04];
    u32 partCount;
    u8 padding0C[0x08];
    void *overlayList;
    u8 padding18[0x10];
    u32 secondaryFlags;
    u8 padding2C[0x0C];
    float scaleX;
    float scaleY;
    float scaleZ;
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
    u8 padding48[0x14];
    void *displayLists[2];
    u8 padding64[0x14];
    void *planes;
} RenderObject;

typedef struct SceneObject {
    u32 type;
    u8 padding04[0x10];
    u8 matrix[0x40];
    float positionX;
    float positionY;
    u8 padding5C[0x64];
    u32 flags;
    void *model;
    u8 animation;
} SceneObject;

extern DisplayCommand *displayListHead __asm__("D_800663DC");
extern u32 currentPlayer __asm__("D_8005A93C");
extern u32 allocationCount __asm__("D_8005B7F8");
extern Mtx scratchMatrices[][2] __asm__("D_8005B800");
extern u32 drawnObjectCount __asm__("D_8005A948");
extern u32 shadowPassActive __asm__("D_8005F990");
extern u32 fogEnabled __asm__("D_8005AA08");
extern DisplayCommand skeletonEndList[] __asm__("D_80065FB8");
extern DisplayCommand translucentSetupList[] __asm__("D_80065DC0");
extern DisplayCommand sceneSetupList[] __asm__("D_80065F38");
extern DisplayCommand opaqueSetupList[] __asm__("D_80065A28");
extern DisplayCommand foggedSetupList[] __asm__("D_80065A88");
extern u8 waterTexture[] __asm__("D_80063528");
extern u8 waterShadowTexture[] __asm__("D_80064740");
#define waterLift 6.0f
#define waterDrop 6.0f
#define minimumHeight -32000.0f
#define maximumHeight 32000.0f

extern u32 CHECK_NAME(void);
extern void MATRIX_NAME(DisplayCommand **, void *, Mtx *, u32);
extern void POSE_NAME(SceneObject *, float *, int);
extern void SKIN_NAME(SceneObject *, u32, u32);
extern void SKIN_PART_NAME(SceneObject *, u32, u32);
extern void WATER_BEGIN_NAME(void);
extern void WATER_UPDATE_NAME(WaterModel *);
extern void WATER_PREPARE_NAME(WaterModel *);
extern void WATER_VERTEX_NAME(WaterModel *);
extern void PREPARE_NAME(void);
extern void CULL_NAME(void *);
extern u32 DRAW_NAME(RenderObject *, int, u32, u32);
extern void FINISH_NAME(DisplayCommand **, u32);
extern void BATCH_NAME(u32, u32);
extern void UPDATE_NAME(RenderObject *);
extern u32 TEST_NAME(void *, void *);
extern void APPLY_NAME(RenderObject *, u32);
extern void SCALED_MATRIX_NAME(DisplayCommand **, void *, Mtx *, u32, float, float, float);

static __inline__ Mtx *allocateMatrix(void)
{
    u32 allocation = allocationCount;

    if (allocation >= 128) {
        return &scratchMatrices[0][currentPlayer];
    }
    allocationCount = allocation + 1;
    return &scratchMatrices[allocation][currentPlayer];
}

#define EMIT(first, second)                         \
    {                                               \
        DisplayCommand *command_ = displayListHead++; \
        command_->words.w0 = (first);               \
        command_->words.w1 = (u32)(second);          \
    }

void LEAF_NAME(SceneObject *object, u32 drawArgument, u32 unused, u32 renderArgument)
{
    float pose[4];

    (void)unused;
    if (object->flags & 0x4000) {
        return;
    }

    if (CHECK_NAME() != 0) {
        SkeletonModel *skeleton;
        u32 segment;
        u32 animation;

        if (object->flags & 4) {
            return;
        }
        skeleton = object->model;
        segment = 0;
        if (object->flags & 0x1000000) {
            segment = (segment < skeleton->segments[2]) << 1;
        }
        if (!(object->animation & 0x80) && segment == 0) {
            return;
        }
        MATRIX_NAME(&displayListHead, object->matrix, allocateMatrix(), 2);
        animation = object->animation & 0x7F;
        if (segment != 0) {
            POSE_NAME(object, pose, -1);
            if (animation == 0) {
                SKIN_NAME(object, 0, currentPlayer + segment);
            } else {
                SKIN_PART_NAME(object, animation, currentPlayer + segment);
            }
        }
        EMIT(0xDB060014, skeleton->segments[currentPlayer + segment]);
        if (skeleton->setupList != 0) {
            EMIT(0xDE000000, skeleton->setupList);
            EMIT(0xDE000000, skeleton->poseLists[animation] + 8);
            EMIT(0xDE000000, skeletonEndList);
            return;
        }
        if (object->flags & 0x1000000) {
            if (object->flags & 0x4000000) {
                EMIT(0xDE000000, skeletonEndList);
            } else {
                EMIT(0xE7000000, 0);
                EMIT(0xDE000000, translucentSetupList);
                EMIT(0xFA000000, 0xFFFFFF8C);
                EMIT(0xE200001C, 0x00504A70);
                EMIT(0xE7000000, 0);
            }
        } else {
            EMIT(0xDE000000, sceneSetupList);
        }
        EMIT(0xDE000000, skeleton->poseLists[animation] + 8);
        EMIT(0xDE000000, skeletonEndList);
        return;
    }

    switch (object->type) {
    case 80: {
        WaterModel *water = object->model;

        WATER_BEGIN_NAME();
        if (water->hasWaves != 0) {
            WATER_UPDATE_NAME(water);
        }
        WATER_PREPARE_NAME(water);
        WATER_VERTEX_NAME(water);
        MATRIX_NAME(&displayListHead, object->matrix, allocateMatrix(), 1);
        EMIT(0xE3001001, 0);
        EMIT(0xD7000002, 0x80008000);
        EMIT(0xFD100000, waterTexture);
        EMIT(0xF5100000, 0x07014050);
        EMIT(0xE6000000, 0);
        EMIT(0xF3000000, 0x073FF100);
        EMIT(0xE7000000, 0);
        EMIT(0xF5101000, 0x00014050);
        EMIT(0xF2000000, 0x0007C07C);
        EMIT(0xDE000000, water->displayLists[currentPlayer]);
        object->positionY += waterLift;
        MATRIX_NAME(&displayListHead, object->matrix, allocateMatrix(), 1);
        object->positionY -= waterDrop;
        EMIT(0xDE000000, translucentSetupList);
        EMIT(0xE7000000, 0);
        EMIT(0xFA000000, 0xFFFFFF46);
        EMIT(0xE7000000, 0);
        EMIT(0xE3001001, 0);
        EMIT(0xD7000002, 0x80008000);
        EMIT(0xFD100000, waterShadowTexture);
        EMIT(0xF5100000, 0x07014050);
        EMIT(0xE6000000, 0);
        EMIT(0xF3000000, 0x073FF100);
        EMIT(0xE7000000, 0);
        EMIT(0xF5101000, 0x00014050);
        EMIT(0xF2000000, 0x0007C07C);
        EMIT(0xE7000000, 0);
        EMIT(0xDE000000, water->displayLists[currentPlayer]);
        EMIT(0xE7000000, 0);
        break;
    }
    case 8:
    case 60:
    case 71: case 72: case 73: case 74: case 75: case 76:
    case 79:
    case 81: case 82: case 83: case 84: case 85: case 86:
    case 88: case 89:
    case 105: {
        RenderObject *model = object->model;

        if (model->flags & 1) {
            u32 mode = (model->secondaryFlags & 4) ? 4 : 1;

            if (model->secondaryFlags & 2) {
                u32 part;

                MATRIX_NAME(&displayListHead, object->matrix, allocateMatrix(), mode);
                if (shadowPassActive != 0) {
                    break;
                }
                if (object->type == 105) {
                    EMIT(0xE3000A01, 0);
                    EMIT(0xD9FFFFFE, 0);
                    EMIT(0xE200001C, 0x00552048);
                    EMIT(0xFA000000, 0xFFFFFFFF);
                    EMIT(0xFC30FE61, 0x44FE793C);
                } else {
                    EMIT(0xDE000000, skeletonEndList);
                    if (fogEnabled != 0) {
                        EMIT(0xDE000000, foggedSetupList);
                    } else {
                        EMIT(0xDE000000, opaqueSetupList);
                    }
                }
                drawnObjectCount++;
                for (part = 0; part <= model->partCount; part++) {
                    PREPARE_NAME();
                    DRAW_NAME(model, part, drawArgument, renderArgument);
                    FINISH_NAME(&displayListHead, 0);
                }
                EMIT(0xD9FFFFFE, 0);
                BATCH_NAME(currentPlayer, renderArgument);
                EMIT(0xE7000000, 0);
                EMIT(0xE3000A01, 0);
                if (fogEnabled == 0) {
                    EMIT(0xE7000000, 0);
                    EMIT(0xD9FFFFFF, 1);
                    EMIT(0xE7000000, 0);
                }
            } else {
                PREPARE_NAME();
                CULL_NAME(object->matrix);
                if (!(minimumHeight < object->positionY)) {
                    break;
                }
                if (!(object->positionY < maximumHeight)) {
                    break;
                }
                if (DRAW_NAME(model, -1, 0, renderArgument) == 0) {
                    break;
                }
                MATRIX_NAME(&displayListHead, object->matrix, allocateMatrix(), mode);
                if (model->flags & 0x20) {
                    EMIT(0xDE000000, model->overlayList);
                    FINISH_NAME(&displayListHead, 1);
                    EMIT(0xD9FBFFFF, 0);
                } else {
                    FINISH_NAME(&displayListHead, 0);
                }
            }
        } else if (model->flags & 2) {
            UPDATE_NAME(model);
            if (TEST_NAME(&object->positionX, model->planes) == 0) {
                break;
            }
            APPLY_NAME(model, 0);
            if (model->flags & 8) {
                MATRIX_NAME(&displayListHead, object->matrix, allocateMatrix(), 2);
            } else {
                MATRIX_NAME(&displayListHead, object->matrix, allocateMatrix(), 1);
            }
            if (model->flags & 0x100) {
                EMIT(0xFC119623, 0xFF2FFFFF);
                EMIT(0xFA000000, ((u32)model->red << 24) | ((u32)model->green << 16) |
                                     ((u32)model->blue << 8) | model->alpha);
            }
            EMIT(0xDE000000, model->displayLists[currentPlayer]);
            EMIT(0xE7000000, 0);
        } else if (model->flags & 0x10) {
            if (model->displayLists[0] == 0) {
                break;
            }
            SCALED_MATRIX_NAME(&displayListHead, object->matrix, allocateMatrix(), 1,
                               model->scaleX, model->scaleY, model->scaleZ);
            EMIT(0xDE000000, sceneSetupList);
            EMIT(0xFA000000, ((u32)model->red << 24) | ((u32)model->green << 16) |
                                 ((u32)model->blue << 8) | model->alpha);
            EMIT(0xDE000000, model->displayLists[0]);
        }
        break;
    }
    }
}
