#ifndef LEAF_NAME
#define LEAF_NAME storePendingSettingsToEeprom
#endif
#ifndef NOTIFY_NAME
#define NOTIFY_NAME notifyObject
#endif
#ifndef PREPARE_NAME
#define PREPARE_NAME prepareControllers
#endif
#ifndef DISABLE_NAME
#define DISABLE_NAME disableInterrupts
#endif
#ifndef MASK_NAME
#define MASK_NAME setInterruptMask
#endif
#ifndef WRITE_NAME
#define WRITE_NAME writeSaveStorage
#endif

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u8 padding000[0xD50];
    u16 flags;
    u8 settingA;
    u8 settingB;
    u8 padding0D54[6];
    u8 settingC;
    u8 settingD;
    u8 settingE;
    u8 names[8];
} GameContext;

typedef struct {
    u8 marker;
    u8 version[3];
    u8 settingA;
    u8 padding05;
    u8 settingB;
    u8 settingC;
    u8 settingD;
    u8 settingE;
    u8 names[8];
    u16 flags;
    u8 padding14[4];
} SettingsRecord;

extern u32 saveSize __asm__("D_80044608");
extern u32 saveBusy __asm__("D_80043724");
extern u8 saveQueue[] __asm__("D_80044804");
extern SettingsRecord settingsBuffer __asm__("D_80044850");
extern u8 versionBytes[] __asm__("D_800445FC");
extern u8 notifyTarget[] __asm__("D_80039318");
extern u32 appNmiBuffer __asm__("D_8000031C");
extern GameContext *gameContext __asm__("D_800FC270");

extern void NOTIFY_NAME(void *target, u32 message);
extern void PREPARE_NAME(void);
extern u32 DISABLE_NAME(void);
extern u32 MASK_NAME(u32 mask);
extern void WRITE_NAME(void *queue, u32 address, void *buffer, u32 size);

void LEAF_NAME(void)
{
    u32 oldMask;
    int index;

    if (gameContext->flags & 0x20) {
        appNmiBuffer = 0x16;
        gameContext->flags &= ~0x20;
        NOTIFY_NAME(notifyTarget, 0xDC);
    }
    if (gameContext->flags & 0x40) {
        appNmiBuffer = 0x17;
        gameContext->flags &= ~0x40;
        NOTIFY_NAME(notifyTarget, 0xDC);
    }
    if (gameContext->flags & 0x80) {
        appNmiBuffer = 0x18;
        gameContext->flags &= ~0x80;
        NOTIFY_NAME(notifyTarget, 0xDC);
    }
    if (gameContext->flags & 0x100) {
        appNmiBuffer = 0x19;
        gameContext->flags &= ~0x100;
        NOTIFY_NAME(notifyTarget, 0xDC);
    }
    if (gameContext->flags & 0x8) {
        appNmiBuffer = 0x1A;
        gameContext->flags &= ~0x8;
        NOTIFY_NAME(notifyTarget, 0xDC);
    }

    if (saveSize != 2048) {
        return;
    }
    PREPARE_NAME();
    settingsBuffer.marker = 'H';
    settingsBuffer.version[0] = versionBytes[0];
    settingsBuffer.version[1] = versionBytes[1];
    settingsBuffer.version[2] = versionBytes[2];
    settingsBuffer.settingA = gameContext->settingA;
    settingsBuffer.settingB = gameContext->settingB;
    settingsBuffer.settingC = gameContext->settingC;
    settingsBuffer.settingD = gameContext->settingD;
    settingsBuffer.settingE = gameContext->settingE;
    settingsBuffer.flags = gameContext->flags;
    for (index = 0; index < 8; index++) {
        settingsBuffer.names[index] = gameContext->names[index];
    }
    saveBusy = 1;
    oldMask = DISABLE_NAME();
    MASK_NAME(1);
    MASK_NAME(0x20401);
    for (index = 0; index <= 99999; index += 2) {
    }
    WRITE_NAME(saveQueue, 0, &settingsBuffer, sizeof(SettingsRecord));
    MASK_NAME(oldMask);
    saveBusy = 0;
}
