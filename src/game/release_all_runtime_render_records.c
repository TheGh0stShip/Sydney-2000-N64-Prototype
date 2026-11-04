#ifndef LEAF_NAME
#define LEAF_NAME releaseAllRuntimeRenderRecords
#endif
#ifndef WRITEBACK_NAME
#define WRITEBACK_NAME writebackCache
#endif
#ifndef RECEIVE_NAME
#define RECEIVE_NAME receiveMessage
#endif
#ifndef STOP_EFFECTS_NAME
#define STOP_EFFECTS_NAME stopEffects
#endif
#ifndef RESET_FIRST_NAME
#define RESET_FIRST_NAME resetFirstSubsystem
#endif
#ifndef RESET_SECOND_NAME
#define RESET_SECOND_NAME resetSecondSubsystem
#endif
#ifndef RESET_THIRD_NAME
#define RESET_THIRD_NAME resetThirdSubsystem
#endif
#ifndef RESET_FOURTH_NAME
#define RESET_FOURTH_NAME resetFourthSubsystem
#endif
#ifndef RESET_FIFTH_NAME
#define RESET_FIFTH_NAME resetFifthSubsystem
#endif
#ifndef SELECT_MODE_NAME
#define SELECT_MODE_NAME selectMode
#endif
#ifndef RESET_SIXTH_NAME
#define RESET_SIXTH_NAME resetSixthSubsystem
#endif
#ifndef RESET_SEVENTH_NAME
#define RESET_SEVENTH_NAME resetSeventhSubsystem
#endif
#ifndef RELEASE_RESOURCE_NAME
#define RELEASE_RESOURCE_NAME releaseRenderResources
#endif
#ifndef RELEASE_HANDLE_NAME
#define RELEASE_HANDLE_NAME releaseHandle
#endif

typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    s16 type;
} RenderMessage;

typedef struct {
    u16 handleCount;
    u8 padding02[0x02];
    void *handle04;
    void *handle08;
    void *handle0C;
    void *handle10;
    u8 padding14[0x02];
    u16 flags;
    u8 padding18[0x2C];
    void *handles[1];
} RenderObject;

typedef struct {
    u32 type;
    RenderObject *object;
    u32 unused08;
    void *secondHandle;
    void *thirdHandle;
} RuntimeRenderRecord;

typedef struct {
    u32 active;
    u8 padding04[0x80];
} RuntimePlayerRecord;

extern u32 settingsDirty __asm__("D_800F1258");
extern u32 pendingRenderMessages __asm__("D_800661D4");
extern unsigned char renderMessageQueue[] __asm__("D_800392F8");
extern u32 activeEffectCount __asm__("D_8005A934");
extern RuntimePlayerRecord runtimePlayerRecords[] __asm__("D_8005AAF0");
extern u32 runtimeRenderRecordCount __asm__("D_8005AC7C");
extern RuntimeRenderRecord runtimeRenderRecords[] __asm__("D_8005ACD0");
extern void *memoryContext __asm__("D_8005A9E8");
extern void *specialObjects[] __asm__("D_8005AAC4");
extern u32 specialObjectCount __asm__("D_8005AAEC");

extern void WRITEBACK_NAME(void);
extern int RECEIVE_NAME(void *queue, RenderMessage **message, int flags);
extern void STOP_EFFECTS_NAME(void);
extern void RESET_FIRST_NAME(void);
extern void RESET_SECOND_NAME(void);
extern void RESET_THIRD_NAME(void);
extern void RESET_FOURTH_NAME(void);
extern void RESET_FIFTH_NAME(void);
extern void SELECT_MODE_NAME(u32 mode);
extern void RESET_SIXTH_NAME(void);
extern void RESET_SEVENTH_NAME(void);
extern void RELEASE_RESOURCE_NAME(RenderObject *object, u32 releaseRecord);
extern void RELEASE_HANDLE_NAME(void *context, void *handle);

int LEAF_NAME(void)
{
    RenderMessage *message;
    RenderObject *object;
    RuntimePlayerRecord *player;
    u32 index;

    if (settingsDirty == 1) {
        settingsDirty = 0;
    }
    message = 0;
    WRITEBACK_NAME();
    while (pendingRenderMessages != 0) {
        if (RECEIVE_NAME(renderMessageQueue, &message, 0) == 0 &&
            (message->type == 1 || message->type == 2)) {
            pendingRenderMessages--;
        }
    }
    WRITEBACK_NAME();
    STOP_EFFECTS_NAME();
    RESET_FIRST_NAME();
    RESET_SECOND_NAME();
    RESET_THIRD_NAME();
    RESET_FOURTH_NAME();
    RESET_FIFTH_NAME();
    activeEffectCount = 0;

    for (index = 0, player = runtimePlayerRecords; index < 3; index++, player++) {
        if (player->active != 0) {
            player->active = 0;
        }
    }

    SELECT_MODE_NAME(0);
    RESET_SIXTH_NAME();
    RESET_SEVENTH_NAME();

    while (runtimeRenderRecordCount-- != 0) {
        object = runtimeRenderRecords[runtimeRenderRecordCount].object;
        if (object == 0) {
            continue;
        }
        if (runtimeRenderRecords[runtimeRenderRecordCount].type == 60) {
            RELEASE_RESOURCE_NAME(object, 0);
            if (runtimeRenderRecords[runtimeRenderRecordCount].object != 0) {
                RELEASE_HANDLE_NAME(memoryContext,
                                    &runtimeRenderRecords[runtimeRenderRecordCount].object);
            }
            if (runtimeRenderRecords[runtimeRenderRecordCount].secondHandle != 0) {
                RELEASE_HANDLE_NAME(memoryContext,
                                    &runtimeRenderRecords[runtimeRenderRecordCount].secondHandle);
            }
            if (runtimeRenderRecords[runtimeRenderRecordCount].thirdHandle != 0) {
                RELEASE_HANDLE_NAME(memoryContext,
                                    &runtimeRenderRecords[runtimeRenderRecordCount].thirdHandle);
            }
        } else {
            for (index = 0; index < object->handleCount; index++) {
                if (object->handles[index] != 0) {
                    RELEASE_HANDLE_NAME(memoryContext, &object->handles[index]);
                }
            }
            if ((object->flags & 1) && object->handle04 != 0) {
                RELEASE_HANDLE_NAME(memoryContext, &object->handle04);
            }
            if ((object->flags & 2) && object->handle08 != 0) {
                RELEASE_HANDLE_NAME(memoryContext, &object->handle08);
            }
            if (object->flags & 0x10) {
                if (object->handle0C != 0) {
                    RELEASE_HANDLE_NAME(memoryContext, &object->handle0C);
                }
                if (object->handle10 != 0) {
                    RELEASE_HANDLE_NAME(memoryContext, &object->handle10);
                }
            }
            if (runtimeRenderRecords[runtimeRenderRecordCount].secondHandle != 0) {
                RELEASE_HANDLE_NAME(memoryContext,
                                    &runtimeRenderRecords[runtimeRenderRecordCount].secondHandle);
            }
            if (runtimeRenderRecords[runtimeRenderRecordCount].thirdHandle != 0) {
                RELEASE_HANDLE_NAME(memoryContext,
                                    &runtimeRenderRecords[runtimeRenderRecordCount].thirdHandle);
            }
            if (runtimeRenderRecords[runtimeRenderRecordCount].object != 0) {
                RELEASE_HANDLE_NAME(memoryContext,
                                    &runtimeRenderRecords[runtimeRenderRecordCount].object);
            }
        }
    }

    for (index = 0; index < 10; index++) {
        if (specialObjects[index] != 0) {
            specialObjects[index] = 0;
        }
    }
    specialObjectCount = 0;
    runtimeRenderRecordCount = 0;
    return 0;
}
