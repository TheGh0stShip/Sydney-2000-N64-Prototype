#ifndef LEAF_NAME
#define LEAF_NAME drainControllerMotorMessages
#endif

#ifndef WRITEBACK_NAME
#define WRITEBACK_NAME writebackDataCache
#endif

#ifndef RECEIVE_NAME
#define RECEIVE_NAME receiveMessage
#endif

typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

extern void WRITEBACK_NAME(void);
extern s32 RECEIVE_NAME(void *queue, void **message, s32 flags);

extern unsigned char controllerMotorQueue[];
extern u32 controllerMotorState;

void LEAF_NAME(void) {
    void *message = 0;

    WRITEBACK_NAME();
    while (controllerMotorState != 0) {
        if (RECEIVE_NAME(controllerMotorQueue, &message, 0) == 0 &&
            *(s16 *)message != 1 && *(s16 *)message == 2) {
            controllerMotorState--;
        }
    }
    WRITEBACK_NAME();
}
