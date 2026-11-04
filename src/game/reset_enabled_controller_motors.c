#ifndef LEAF_NAME
#define LEAF_NAME resetEnabledControllerMotors
#endif
#ifndef PREPARE_NAME
#define PREPARE_NAME prepareControllers
#endif
#ifndef MOTOR_ACCESS_NAME
#define MOTOR_ACCESS_NAME motorAccess
#endif
#ifndef CONTROLLERS_NAME
#define CONTROLLERS_NAME controllers
#endif
#ifndef RECORDS_NAME
#define RECORDS_NAME records
#endif

typedef struct {
    int enabled;
    int active;
    int value;
} Record;

extern unsigned char CONTROLLERS_NAME[];
extern Record RECORDS_NAME[];

void PREPARE_NAME(void);
int MOTOR_ACCESS_NAME(void *controller, int operation);

void LEAF_NAME(void) {
    Record *record;
    Record *end;
    unsigned char *controllerBase;
    int enabledValue;
    int controllerOffset;
    int accessOffset;
    int motorIndex;

    PREPARE_NAME();
    enabledValue = 1;
    controllerBase = CONTROLLERS_NAME;
    controllerOffset = 0;
    record = RECORDS_NAME;
    end = &RECORDS_NAME[4];
    do {
        record->value = 0;
        if (record->enabled == enabledValue) {
            motorIndex = 0;
            accessOffset = controllerOffset;
            do {
                MOTOR_ACCESS_NAME(
                    &controllerBase[accessOffset],
                    0
                );
                motorIndex++;
            } while (motorIndex < 3);
        }
        record++;
        controllerOffset += 104;
    } while ((int)record < (int)end);
}
