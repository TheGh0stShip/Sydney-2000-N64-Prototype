#ifndef LEAF_NAME
#define LEAF_NAME runShutdownSequence
#endif

#ifndef RECEIVE_NAME
#define RECEIVE_NAME receiveMessage
#endif

#ifndef SET_SCALE_NAME
#define SET_SCALE_NAME setVerticalScale
#endif

#ifndef SET_BLACK_NAME
#define SET_BLACK_NAME setBlack
#endif

#ifndef AFTER_PRENMI_NAME
#define AFTER_PRENMI_NAME afterPreNmi
#endif

#ifndef RESET_MOTORS_NAME
#define RESET_MOTORS_NAME resetMotors
#endif

typedef unsigned int u32;

extern void RECEIVE_NAME(void *queue, void **message, u32 flags);
extern void SET_SCALE_NAME(float scale);
extern void SET_BLACK_NAME(u32 active);
extern u32 AFTER_PRENMI_NAME(void);
extern void RESET_MOTORS_NAME(void *controllers);

extern u32 shutdownActive;
extern u32 controllerMotorState;
extern unsigned char controllerRecords[];

void LEAF_NAME(void *queue) {
    void *message = 0;

    do {
        RECEIVE_NAME(queue, &message, 1);
    } while ((u32)message != 669);

    shutdownActive = 1;
    SET_SCALE_NAME(1.0f);
    SET_BLACK_NAME(1);
    while (AFTER_PRENMI_NAME() != 0) {
    }

    controllerMotorState = 0;
    RESET_MOTORS_NAME(controllerRecords);
    for (;;) {
    }
}
