#ifndef LEAF_NAME
#define LEAF_NAME drainStartupMessages
#endif

#ifndef START_NAME
#define START_NAME startMessageProcessing
#endif

#ifndef RECEIVE_NAME
#define RECEIVE_NAME receiveMessage
#endif

#ifndef CLEANUP_NAME
#define CLEANUP_NAME cleanupControllerMessages
#endif

#ifndef QUEUE_NAME
#define QUEUE_NAME startupMessageQueue
#endif

#ifndef MESSAGE_NAME
#define MESSAGE_NAME startupMessage
#endif

#ifndef PENDING_NAME
#define PENDING_NAME pendingControllerMessages
#endif

#ifndef COMPLETED_NAME
#define COMPLETED_NAME completedControllerMessages
#endif

typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

extern unsigned char QUEUE_NAME[];
extern void *MESSAGE_NAME;
extern u32 PENDING_NAME;
extern u32 COMPLETED_NAME;
extern s32 START_NAME(s32 index);
extern s32 RECEIVE_NAME(void *queue, void **message, s32 flags);
extern void CLEANUP_NAME(void);

void LEAF_NAME(void) {
    u32 active = START_NAME(-1) != 0;

    while (active == 1) {
        if (RECEIVE_NAME(QUEUE_NAME, &MESSAGE_NAME, 1) == 0 &&
            *(s16 *)MESSAGE_NAME != 1 && *(s16 *)MESSAGE_NAME == 2) {
            active = 0;
            PENDING_NAME--;
            COMPLETED_NAME++;
        }
    }
    CLEANUP_NAME();
}
