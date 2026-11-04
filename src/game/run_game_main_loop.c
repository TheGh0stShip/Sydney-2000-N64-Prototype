#ifndef LEAF_NAME
#define LEAF_NAME runGameMainLoop
#endif
#ifndef INIT_SYSTEM_NAME
#define INIT_SYSTEM_NAME initializeSystem
#endif
#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocateBuffer
#endif
#ifndef INIT_AUDIO_NAME
#define INIT_AUDIO_NAME initializeAudio
#endif
#ifndef CONFIGURE_WORK_NAME
#define CONFIGURE_WORK_NAME configureWorkBuffer
#endif
#ifndef INIT_VIDEO_NAME
#define INIT_VIDEO_NAME initializeVideo
#endif
#ifndef CREATE_QUEUE_NAME
#define CREATE_QUEUE_NAME createMessageQueue
#endif
#ifndef ADD_CLIENT_NAME
#define ADD_CLIENT_NAME addSchedulerClient
#endif
#ifndef GET_COMMAND_QUEUE_NAME
#define GET_COMMAND_QUEUE_NAME getSchedulerCommandQueue
#endif
#ifndef OPEN_ARCHIVE_NAME
#define OPEN_ARCHIVE_NAME openArchive
#endif
#ifndef LOAD_TABLE_NAME
#define LOAD_TABLE_NAME loadArchiveTable
#endif
#ifndef LOAD_FILE_NAME
#define LOAD_FILE_NAME loadArchiveFile
#endif
#ifndef FREE_NAME
#define FREE_NAME freeBuffer
#endif
#ifndef SET_LANGUAGE_NAME
#define SET_LANGUAGE_NAME setLanguage
#endif
#ifndef APPLY_LANGUAGE_NAME
#define APPLY_LANGUAGE_NAME applyLanguage
#endif
#ifndef START_RENDER_NAME
#define START_RENDER_NAME startRender
#endif
#ifndef INIT_OBJECTS_NAME
#define INIT_OBJECTS_NAME initializeObjects
#endif
#ifndef INIT_FONTS_NAME
#define INIT_FONTS_NAME initializeFonts
#endif
#ifndef INIT_CONTROLLERS_NAME
#define INIT_CONTROLLERS_NAME initializeControllers
#endif
#ifndef DRAIN_MOTORS_NAME
#define DRAIN_MOTORS_NAME drainControllerMotorMessages
#endif
#ifndef RECEIVE_NAME
#define RECEIVE_NAME receiveMessage
#endif
#ifndef BEGIN_FRAME_NAME
#define BEGIN_FRAME_NAME beginFrame
#endif
#ifndef UPDATE_STATE_NAME
#define UPDATE_STATE_NAME updateGameState
#endif
#ifndef START_FRAME_NAME
#define START_FRAME_NAME startFrame
#endif

typedef signed short s16;
typedef signed int s32;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;

extern u8 workContext[] __asm__("D_800F2758");
extern void *frameBuffers[2] __asm__("D_80039310");
extern void *depthBuffer __asm__("D_80038C64");
extern void *firstRenderBuffer __asm__("D_80038C68");
extern void *renderOutputBuffer __asm__("D_80038C6C");
extern char frameBufferTag[] __asm__("D_80000450");
extern char depthBufferTag[] __asm__("D_8000045C");
extern char renderBufferTag[] __asm__("D_80000468");
extern char outputBufferTag[] __asm__("D_80000474");
extern char archiveName[] __asm__("D_80000480");
extern char languageFileName[] __asm__("D_8000048C");
extern u8 messageQueue[] __asm__("D_800392F8");
extern u8 messageBuffer[] __asm__("D_80039428");
extern u8 scheduler[] __asm__("D_80038C78");
extern u8 schedulerClient[] __asm__("D_80039430");
extern void *schedulerCommandQueue __asm__("D_800663D8");
extern u8 archive[] __asm__("D_80038C4C");
extern u32 language __asm__("D_800F271C");
extern u8 languageCodes[] __asm__("D_800F2750");
extern u8 languageCode __asm__("D_800F274C");
extern u8 fontTable[] __asm__("D_80039318");
extern u8 controllerTable[] __asm__("D_80038C40");
extern u16 buttonState __asm__("D_8004462C");
extern u32 frameFlags __asm__("D_80044604");
extern u32 debugEnabled __asm__("D_800F2620");
extern void *message __asm__("D_80038C70");
extern u32 pendingMessages __asm__("D_800661D4");
extern u32 completedMessages __asm__("D_80038C50");
extern u8 gameState[] __asm__("D_800F1B84");
extern u32 gameStateArgument __asm__("D_800F2774");

extern void INIT_SYSTEM_NAME(void);
extern void ALLOCATE_NAME(void *context, void *output, u32 size, char *tag);
extern void INIT_AUDIO_NAME(void);
extern void CONFIGURE_WORK_NAME(void);
extern void INIT_VIDEO_NAME(s32 mode);
extern void CREATE_QUEUE_NAME(void *queue, void *buffer, s32 count);
extern void ADD_CLIENT_NAME(void *scheduler, void *client, void *queue);
extern void *GET_COMMAND_QUEUE_NAME(void *scheduler);
extern void OPEN_ARCHIVE_NAME(void *archive, u32 address, s32 flags);
extern void LOAD_TABLE_NAME(char *name, s32 count, void *context);
extern s32 LOAD_FILE_NAME(char *name, u8 **output, void *context, s32 flags);
extern void FREE_NAME(void *context, u8 **buffer);
extern void SET_LANGUAGE_NAME(void *context, s32 flags, u32 language);
extern void APPLY_LANGUAGE_NAME(void);
extern void START_RENDER_NAME(void);
extern void INIT_OBJECTS_NAME(void *table, s32 count);
extern void INIT_FONTS_NAME(void *table);
extern void INIT_CONTROLLERS_NAME(void);
extern void DRAIN_MOTORS_NAME(void);
extern s32 RECEIVE_NAME(void *queue, void **message, s32 flags);
extern void BEGIN_FRAME_NAME(s32 flags);
extern void UPDATE_STATE_NAME(void *state, u32 argument);
extern s32 START_FRAME_NAME(s32 index);

void LEAF_NAME(void) __attribute__((noreturn));

void LEAF_NAME(void) {
    u32 waiting = 0;
    u8 *languageData = 0;
    s32 index;

    INIT_SYSTEM_NAME();
    for (index = 0; index < 2; index++) {
        frameBuffers[index] = 0;
        ALLOCATE_NAME(workContext, &frameBuffers[index], 0xC000, frameBufferTag);
    }
    ALLOCATE_NAME(workContext, &depthBuffer, 0x14000, depthBufferTag);
    ALLOCATE_NAME(workContext, &firstRenderBuffer, 0x400, renderBufferTag);
    ALLOCATE_NAME(workContext, &renderOutputBuffer, 0xC00, outputBufferTag);
    INIT_AUDIO_NAME();
    CONFIGURE_WORK_NAME();
    INIT_VIDEO_NAME(2);
    CREATE_QUEUE_NAME(messageQueue, messageBuffer, 2);
    ADD_CLIENT_NAME(scheduler, schedulerClient, messageQueue);
    schedulerCommandQueue = GET_COMMAND_QUEUE_NAME(scheduler);
    OPEN_ARCHIVE_NAME(archive, 0xB01A3AB0, 0);
    LOAD_TABLE_NAME(archiveName, 16, workContext);
    if (LOAD_FILE_NAME(languageFileName, &languageData, workContext, 1) == 0) {
        language = 1;
    } else {
        language = *languageData;
        if (language >= 8) {
            language = 1;
        }
        FREE_NAME(workContext, &languageData);
    }
    SET_LANGUAGE_NAME(workContext, 0, language);
    languageCode = languageCodes[language];
    APPLY_LANGUAGE_NAME();
    START_RENDER_NAME();
    INIT_OBJECTS_NAME(fontTable, 12);
    INIT_FONTS_NAME(controllerTable);
    INIT_CONTROLLERS_NAME();
    DRAIN_MOTORS_NAME();

    for (;;) {
        frameFlags = 0;
        if (buttonState & 0x20) {
            debugEnabled = 1;
        } else {
            debugEnabled = 0;
        }
        while (waiting == 1) {
            if (RECEIVE_NAME(messageQueue, &message, 1) == 0 &&
                *(s16 *)message != 1 && *(s16 *)message == 2) {
                waiting = 0;
                pendingMessages--;
                completedMessages++;
            }
        }
        BEGIN_FRAME_NAME(1);
        UPDATE_STATE_NAME(gameState, gameStateArgument);
        waiting = START_FRAME_NAME(-1) != 0;
    }
}
