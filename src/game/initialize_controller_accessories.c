#ifndef LEAF_NAME
#define LEAF_NAME initializeControllerAccessories
#endif
#ifndef CREATE_QUEUE_NAME
#define CREATE_QUEUE_NAME createMessageQueue
#endif
#ifndef SET_EVENT_NAME
#define SET_EVENT_NAME setEventMessage
#endif
#ifndef CONT_INIT_NAME
#define CONT_INIT_NAME initializeControllers
#endif
#ifndef RESET_FIRST_NAME
#define RESET_FIRST_NAME resetFirstControllerState
#endif
#ifndef RESET_SECOND_NAME
#define RESET_SECOND_NAME resetSecondControllerState
#endif
#ifndef CLEAR_NAME
#define CLEAR_NAME clearBytes
#endif
#ifndef PFS_INIT_NAME
#define PFS_INIT_NAME initializeControllerPak
#endif
#ifndef MOTOR_INIT_NAME
#define MOTOR_INIT_NAME initializeControllerMotor
#endif
#ifndef PFS_REPAIR_NAME
#define PFS_REPAIR_NAME repairControllerPakId
#endif
#ifndef EEPROM_PROBE_NAME
#define EEPROM_PROBE_NAME probeEeprom
#endif

typedef signed int s32;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u8 bytes[24]; } MessageQueue;
typedef struct { u16 type; u8 status; u8 error; } ControllerStatus;
typedef struct { u8 bytes[104]; } PakState;
typedef struct {
    u32 active;
    u32 motorPresent;
    u32 reserved;
} ControllerAccessory;

extern MessageQueue siQueue __asm__("D_80044804");
extern void *siMessage __asm__("D_8004481C");
extern u8 controllerPattern __asm__("D_80044650");
extern ControllerStatus controllerStatuses[] __asm__("D_80044654");
extern u8 controllerState[] __asm__("D_800445F0");
extern PakState pakStates[] __asm__("D_80044664");
extern ControllerAccessory controllerAccessories[] __asm__("D_80044820");
extern u32 accessoryCount __asm__("D_80044600");
extern s16 eepromType __asm__("D_8004460C");
extern u32 eepromSize __asm__("D_80044608");

extern void CREATE_QUEUE_NAME(MessageQueue *, void **, s32);
extern void SET_EVENT_NAME(s32, MessageQueue *, void *);
extern void CONT_INIT_NAME(MessageQueue *, u8 *, ControllerStatus *);
extern void RESET_FIRST_NAME(void *);
extern void RESET_SECOND_NAME(void *);
extern void CLEAR_NAME(void *, s32, u32);
extern s32 PFS_INIT_NAME(MessageQueue *, PakState *, s32);
extern s32 MOTOR_INIT_NAME(MessageQueue *, PakState *, s32);
extern void PFS_REPAIR_NAME(PakState *);
extern s32 EEPROM_PROBE_NAME(MessageQueue *);

u32 LEAF_NAME(s32 controllerLimit)
{
    s32 index;

    CREATE_QUEUE_NAME(&siQueue, &siMessage, 1);
    SET_EVENT_NAME(5, &siQueue, (void *)1);
    CONT_INIT_NAME(&siQueue, &controllerPattern, controllerStatuses);
    RESET_FIRST_NAME(controllerState);
    RESET_SECOND_NAME(controllerState);

    for (index = 0; index < controllerLimit; index++) {
        ControllerAccessory *accessory = &controllerAccessories[index];
        s32 result;

        if (((controllerPattern >> index) & 1) == 0) {
            continue;
        }
        CLEAR_NAME(accessory, 0, sizeof(*accessory));
        if ((controllerStatuses[index].type & 0x1F07) != 5) {
            continue;
        }
        accessory->active = 1;
        accessoryCount++;
        result = PFS_INIT_NAME(&siQueue, &pakStates[index], index);
        if (result == 10) {
            PFS_REPAIR_NAME(&pakStates[index]);
        } else if (result == 11 &&
                   MOTOR_INIT_NAME(&siQueue, &pakStates[index], index) == 0) {
            accessory->motorPresent = 1;
        }
    }

    eepromType = EEPROM_PROBE_NAME(&siQueue);
    if (eepromType == 1) {
        eepromSize = 0x200;
    } else if (eepromType == 2) {
        eepromSize = 0x800;
    } else {
        eepromSize = 0;
    }
    return accessoryCount;
}
