#ifndef LEAF_NAME
#define LEAF_NAME renderRuntimeObjectBatch
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
#ifndef SCRATCH_NAME
#define SCRATCH_NAME allocatePlayerScratch
#endif
#ifndef MATRIX_NAME
#define MATRIX_NAME buildFlaggedModelMatrix
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

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 word0;
    u32 word1;
} DisplayCommand;

typedef struct RenderObject {
    u32 flags;
    u8 padding04[0x24];
    u32 secondaryFlags;
    u8 padding2C[0x18];
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
    u8 padding48[0x14];
    void *displayLists[2];
    u8 padding64[0x14];
    void *planes;
} RenderObject;

typedef struct {
    u8 padding00[0x14];
    u8 matrix[0x40];
    u8 planeState[0x70];
    RenderObject *object;
} RuntimeObject;

extern RuntimeObject *runtimeObjects[] __asm__("D_8005FCCC");
extern u32 runtimeObjectCount __asm__("D_8005FEDC");
extern DisplayCommand *displayListHead __asm__("D_800663DC");
extern u32 currentPlayer __asm__("D_8005A93C");

extern void UPDATE_NAME(RenderObject *);
extern u32 TEST_NAME(void *, void *);
extern void APPLY_NAME(RenderObject *, u32);
extern void *SCRATCH_NAME(void);
extern void MATRIX_NAME(DisplayCommand **, void *, void *, u32);
extern void PREPARE_NAME(void);
extern void DRAW_NAME(RenderObject *, int, u32, u32);
extern void FINISH_NAME(DisplayCommand **, u32);

void LEAF_NAME(u32 unused, u32 renderArgument)
{
    u32 index;

    (void)unused;
    for (index = 0; index < runtimeObjectCount; index++) {
        RuntimeObject *runtime = runtimeObjects[index];
        RenderObject *object = runtime->object;

        if (object->flags & 2) {
            UPDATE_NAME(object);
            if (TEST_NAME(runtime->planeState, object->planes) == 0) {
                continue;
            }
            APPLY_NAME(object, 0);
            MATRIX_NAME(&displayListHead, runtime->matrix, SCRATCH_NAME(),
                        (object->flags & 8) ? 2 : 1);
            if (object->flags & 0x100) {
                DisplayCommand *command = displayListHead++;
                command->word0 = 0xFC119623;
                command->word1 = 0xFF2FFFFF;
                command = displayListHead++;
                command->word0 = 0xFA000000;
                command->word1 = ((u32)object->red << 24) |
                                 ((u32)object->green << 16) |
                                 ((u32)object->blue << 8) | object->alpha;
            }
            {
                DisplayCommand *command = displayListHead++;
                command->word0 = 0xDE000000;
                command->word1 = (u32)object->displayLists[currentPlayer];
                command = displayListHead++;
                command->word0 = 0xE7000000;
                command->word1 = 0;
            }
        } else {
            u32 mode = (object->secondaryFlags & 4) ? 4 : 1;
            MATRIX_NAME(&displayListHead, runtime->matrix, SCRATCH_NAME(), mode);
            PREPARE_NAME();
            DRAW_NAME(object, -1, 0, renderArgument);
            FINISH_NAME(&displayListHead, 0);
        }
    }
    runtimeObjectCount = 0;
}
