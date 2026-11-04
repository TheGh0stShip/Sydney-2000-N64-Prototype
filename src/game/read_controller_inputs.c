#ifndef LEAF_NAME
#define LEAF_NAME readControllerInputs
#endif
#ifndef START_READ_NAME
#define START_READ_NAME startControllerRead
#endif
#ifndef RECEIVE_NAME
#define RECEIVE_NAME receiveMessage
#endif
#ifndef GET_READ_NAME
#define GET_READ_NAME getControllerReadData
#endif
#ifndef MOTOR_ACCESS_NAME
#define MOTOR_ACCESS_NAME motorAccess
#endif
#ifndef NOTIFY_NAME
#define NOTIFY_NAME notifyControllerError
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;

typedef struct {
    u16 buttons;
    signed char stickX;
    signed char stickY;
    u8 error;
    u8 unused;
} ControllerPad;

typedef struct {
    s32 enabled;
    s32 active;
    s32 timer;
} MotorRecord;

extern unsigned char controllerQueue[] __asm__("D_80044804");
extern u16 controllerMask __asm__("D_80044606");
extern ControllerPad controllerPads[4] __asm__("D_80044614");
extern ControllerPad controllerTemplates[4] __asm__("D_8004462C");
extern ControllerPad *controllerPointers[4] __asm__("D_80044644");
extern unsigned char controllerPorts[4][104] __asm__("D_80044664");
extern MotorRecord motorRecords[4] __asm__("D_80044820");
extern u16 previousButtons[4] __asm__("D_80068910");

extern void START_READ_NAME(void *queue);
extern void RECEIVE_NAME(void *queue, void *message, s32 flags);
extern void GET_READ_NAME(ControllerPad *pads);
extern s32 MOTOR_ACCESS_NAME(void *port, s32 operation);
extern void NOTIFY_NAME(s32 error);

void LEAF_NAME(void)
{
    s32 index;

    START_READ_NAME(controllerQueue);
    RECEIVE_NAME(controllerQueue, 0, 1);
    GET_READ_NAME(controllerPads);
    for (index = 0; index < 4; index++) {
        MotorRecord *record = &motorRecords[index];
        ControllerPad *pad = &controllerPads[index];
        u16 buttons;

        if (record->active != 0 && record->timer > 0) {
            if (MOTOR_ACCESS_NAME(controllerPorts[index], 1) == 4) {
                NOTIFY_NAME(4);
            }
            record->timer--;
            if (record->timer <= 0) {
                if (MOTOR_ACCESS_NAME(controllerPorts[index], 0) == 4) {
                    NOTIFY_NAME(4);
                }
            }
        }
        controllerPointers[index] = pad;
        buttons = pad->buttons;
        controllerTemplates[index].buttons =
            buttons & ~(controllerMask & previousButtons[index]);
        previousButtons[index] = buttons;
    }
}
