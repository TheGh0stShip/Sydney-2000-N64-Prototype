#ifndef LEAF_NAME
#define LEAF_NAME renderObjectShadows
#endif
#ifndef TEST_NAME
#define TEST_NAME testAllVectorPlanes
#endif
#ifndef SELECT_NAME
#define SELECT_NAME selectObjectPose
#endif
#ifndef DRAW_FIRST_NAME
#define DRAW_FIRST_NAME drawObjectFirstLevel
#endif
#ifndef DRAW_LEVEL_NAME
#define DRAW_LEVEL_NAME drawObjectDetailLevel
#endif
#ifndef SCRATCH_NAME
#define SCRATCH_NAME allocatePlayerScratch
#endif
#ifndef MATRIX_NAME
#define MATRIX_NAME buildFlaggedModelMatrix
#endif
#ifndef UPDATE_NAME
#define UPDATE_NAME updateRenderObject
#endif
#ifndef PREPARE_NAME
#define PREPARE_NAME prepareRenderState
#endif
#ifndef DRAW_NAME
#define DRAW_NAME drawRenderObject
#endif
#ifndef FINISH_NAME
#define FINISH_NAME finishRenderCommands
#endif
#ifndef APPLY_NAME
#define APPLY_NAME applyRenderObjectState
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 word0;
    u32 word1;
} DisplayCommand;

typedef struct {
    float matrix[4][4];
    float position[3];
} ObjectTransform;

typedef struct {
    u16 levelCount;
    u8 padding02[2];
    void *segments[8];
    float lowerDistances[4];
    float upperDistances[4];
    DisplayCommand *displayLists[4];
} DetailModel;

typedef struct {
    u32 flags;
    u8 padding04[0x24];
    u32 secondaryFlags;
    u8 padding2C[0x30];
    DisplayCommand *displayLists[2];
    u8 padding64[0x14];
    float radius;
} RenderObject;

typedef struct {
    u8 padding00[0x28];
    float radius;
} BoundsInfo;

typedef struct {
    u8 padding00[0x08];
    BoundsInfo *bounds;
} ObjectDefinition;

typedef struct {
    u32 type;
    u8 padding04[0x10];
    ObjectTransform transform;
    u8 padding60[0x60];
    u32 flags;
    void *model;
    u8 detailLevel;
    u8 paddingC9[3];
    u32 viewMask;
    ObjectDefinition *definition;
} ShadowObject;

typedef struct {
    float x;
    float y;
    float z;
} CameraState;

extern u32 detailObjectCount __asm__("D_800620C0");
extern ShadowObject *detailObjects[] __asm__("D_80062010");
extern u32 renderObjectCount __asm__("D_8005FCC8");
extern ShadowObject *renderObjects[] __asm__("D_8005FA38");
extern u32 currentPlayer __asm__("D_8005A93C");
extern u32 useAlternateShadowSetup __asm__("D_8005AA08");
extern u32 useFirstLevelOnly __asm__("D_8005A94C");
extern DisplayCommand shadowCommands[][2][177] __asm__("D_8005FEE0");
extern DisplayCommand alternateShadowSetup[] __asm__("D_8005F9B0");
extern DisplayCommand shadowSetup[] __asm__("D_8005F9D8");
extern DisplayCommand shadowFinish[] __asm__("D_8005FA08");
extern DisplayCommand *displayListHead __asm__("D_800663DC");
extern CameraState camera __asm__("D_8005B6D0");
extern float distanceScale __asm__("D_8005B6DC");
extern float shadowSlopeX __asm__("D_8005F9A4");
extern float shadowSlopeZ __asm__("D_8005F9A8");

extern u32 TEST_NAME(float *vector, float tolerance);
extern void SELECT_NAME(ShadowObject *object, float *pose, int index);
extern void DRAW_FIRST_NAME(ShadowObject *object, u32 level, u32 segment);
extern void DRAW_LEVEL_NAME(ShadowObject *object, u32 level, u32 segment);
extern void *SCRATCH_NAME(void);
extern void MATRIX_NAME(DisplayCommand **, ObjectTransform *, void *, u32);
extern void UPDATE_NAME(RenderObject *);
extern void PREPARE_NAME(void);
extern void DRAW_NAME(RenderObject *, int, u32, u32);
extern void FINISH_NAME(DisplayCommand **, u32);
extern void APPLY_NAME(RenderObject *, u32);

void LEAF_NAME(u32 view)
{
    DisplayCommand *commands;
    DisplayCommand *command;
    ShadowObject *object;
    ShadowObject **objectCursor;
    u32 index;
    u32 mask;
    u32 level;
    u32 variant;
    ObjectTransform transform;
    float offset[3];
    float pose[4];
    float dx;
    float height;
    float sx;
    float sz;

    if (detailObjectCount == 0) {
        return;
    }
    commands = shadowCommands[view][currentPlayer];
    if (useAlternateShadowSetup) {
        {
            DisplayCommand *_g = (DisplayCommand *)(displayListHead++);
            _g->word0 = 0xDE000000;
            _g->word1 = (u32)alternateShadowSetup;
        }
    } else {
        {
            DisplayCommand *_g = (DisplayCommand *)(displayListHead++);
            _g->word0 = 0xDE000000;
            _g->word1 = (u32)shadowSetup;
        }
    }
    {
        DisplayCommand *_g = (DisplayCommand *)(displayListHead++);
        _g->word0 = 0xDE000000;
        _g->word1 = (u32)commands;
    }
    for (index = 0;; index++) {
        DetailModel *model;
        float distance;

        if (index >= detailObjectCount) {
            break;
        }

        object = detailObjects[index];
        if (!(object->viewMask & (1 << view))) {
            continue;
        }
        if (object->flags & 4) {
            continue;
        }
        model = object->model;
        object->detailLevel = 0;
        if (!(object->flags & 0x2000)) {
            if (TEST_NAME(object->transform.position,
                          object->definition->bounds->radius) == 0) {
                continue;
            }
        }
        offset[0] = object->transform.position[0] - camera.x;
        offset[1] = object->transform.position[1] - camera.y;
        offset[2] = object->transform.position[2] - camera.z;
        distance = (offset[0] * offset[0] + offset[1] * offset[1] +
                    offset[2] * offset[2]) * distanceScale;

        level = 0;
        while (model->upperDistances[level] < distance) {
            if (++level >= model->levelCount) {
                level = model->levelCount - 1;
                break;
            }
        }
        while (distance < model->lowerDistances[level]) {
            level--;
            if (level == 0) {
                break;
            }
        }

        SELECT_NAME(object, pose, -1);
        variant = 0;
        if (object->flags & 0x1000000) {
            variant = (model->segments[2] != 0) << 1;
        }
        if (useFirstLevelOnly) {
            DRAW_FIRST_NAME(object, level, currentPlayer + variant);
        } else if (level == 0) {
            DRAW_FIRST_NAME(object, 0, currentPlayer + variant);
        } else {
            DRAW_LEVEL_NAME(object, level, currentPlayer + variant);
        }
        if (model->levelCount >= 2 && level != model->levelCount - 1) {
            DRAW_LEVEL_NAME(object, model->levelCount - 1, currentPlayer + variant);
        }
        object->detailLevel |= 0x80 | level;
        if (object->flags & 0x2000000) {
            continue;
        }

        transform = object->transform;
        sx = shadowSlopeX;
        sz = shadowSlopeZ;
        height = transform.position[1]; height -= 1.0f;
        dx = sx * height;
        height = sz * height;
        transform.matrix[1][0] += sx;
        transform.matrix[1][2] += sz;
        transform.matrix[0][1] = 0.0f;
        transform.matrix[1][1] = 0.0f;
        transform.matrix[2][1] = 0.0f;
        transform.position[0] += dx;
        transform.position[1] = 1.0f;
        transform.position[2] += height;
        MATRIX_NAME(&commands, &transform, SCRATCH_NAME(), 2);

        {
            DisplayCommand *_g = (DisplayCommand *)(commands++);
            _g->word0 = 0xDB060014;
            _g->word1 = (u32)model->segments[currentPlayer + variant];
        }
        {
            DisplayCommand *_g = (DisplayCommand *)(commands++);
            _g->word0 = 0xDE000000;
            _g->word1 = (u32)model->displayLists[model->levelCount - 1];
        }
    }

    commands->word0 = 0xDF000000;
    commands->word1 = 0;
    for (index = 0;; index++) {
        RenderObject *render;
        float distance;
        float limit;

        if (index >= renderObjectCount) {
            break;
        }

        object = renderObjects[index];
        if (!(object->viewMask & (1 << view))) {
            continue;
        }
        if (object->flags & 0x2000000) {
            continue;
        }
        switch (object->type) {
        case 0x3C:
        case 0x48:
        case 0x49:
        case 0x51:
        case 0x52:
            render = object->model;
            offset[0] = object->transform.position[0] - camera.x;
            offset[1] = object->transform.position[1] - camera.y;
            offset[2] = object->transform.position[2] - camera.z;
            distance = offset[0] * offset[0] + offset[1] * offset[1] +
                       offset[2] * offset[2];
            limit = 0.0f;
            if (render->flags & 2) {
                UPDATE_NAME(render);
                limit = render->radius * render->radius;
            }
            if (!(distance < limit + 966308.5625f)) {
                break;
            }
            transform = object->transform;
            sx = shadowSlopeX;
            sz = shadowSlopeZ;
            height = transform.position[1]; height -= 1.0f;
            dx = sx * height;
            height = sz * height;
            transform.matrix[1][0] += sx;
            transform.matrix[1][2] += sz;
            transform.matrix[0][1] = 0.0f;
            transform.matrix[1][1] = 0.0f;
            transform.matrix[2][1] = 0.0f;
            transform.position[0] += dx;
            transform.position[1] = 1.0f;
            transform.position[2] += height;
            level = (render->secondaryFlags & 4) ? 4 : 1;
            if (render->flags & 8) {
                MATRIX_NAME(&displayListHead, &transform, SCRATCH_NAME(), 2);
            } else {
                MATRIX_NAME(&displayListHead, &transform, SCRATCH_NAME(), level);
            }
            if (render->flags & 1) {
                PREPARE_NAME();
                DRAW_NAME(render, -1, 0, view);
                FINISH_NAME(&displayListHead, 0);
            } else if (render->flags & 2) {
                if (TEST_NAME(object->transform.position, render->radius) != 0) {
                    APPLY_NAME(render, 0);
                    {
                        DisplayCommand *_g = (DisplayCommand *)(displayListHead++);
                        _g->word0 = 0xDE000000;
                        _g->word1 = (u32)render->displayLists[currentPlayer];
                    }
                }
            }
            break;
        }
    }
    detailObjectCount = 0;
    renderObjectCount = 0;
    {
        DisplayCommand *_g = (DisplayCommand *)(displayListHead++);
        _g->word0 = 0xDE000000;
        _g->word1 = (u32)shadowFinish;
    }
}
