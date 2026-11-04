#ifndef LEAF_NAME
#define LEAF_NAME loadEepromSettings
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
#ifndef READ_NAME
#define READ_NAME readSaveStorage
#endif
#ifndef APPLY_NAME
#define APPLY_NAME applySettings
#endif

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u32 header;
    u16 option12;
    u8 option04;
    u8 option06;
    u8 padding08[6];
    u8 option07;
    u8 option08;
    u8 option09;
    u8 values[8];
    u8 padding19[3];
    u32 words[0x528 / 4];
} SettingsBlock;

typedef struct {
    u8 padding000[0xD4C];
    SettingsBlock settings;
} GameContext;

typedef struct {
    u8 tag;
    u8 signature[3];
    u8 option04;
    u8 padding05;
    u8 option06;
    u8 option07;
    u8 option08;
    u8 option09;
    u8 values[8];
    u16 option12;
    u8 padding14[4];
} SettingsRecord;

extern u32 saveSize __asm__("D_80044608");
extern u32 settingsBackedUp __asm__("D_80044610");
extern u32 saveBusy __asm__("D_80043724");
extern u8 saveQueue[] __asm__("D_80044804");
extern SettingsRecord settingsRecord __asm__("D_80044850");
extern u8 settingsSignature[] __asm__("D_800445FC");
extern SettingsBlock settingsBackup __asm__("D_80045040");
extern GameContext *gameContext __asm__("D_800FC270");

extern void PREPARE_NAME(void);
extern u32 DISABLE_NAME(void);
extern u32 MASK_NAME(u32 mask);
extern void READ_NAME(void *queue, u32 address, void *buffer, u32 size);
extern void APPLY_NAME(int a, int b, int c);

void LEAF_NAME(void)
{
    u32 oldMask;
    int delay;
    int index;

    if (saveSize != 2048) {
        return;
    }
    if (settingsBackedUp == 0) {
        settingsBackup = gameContext->settings;
        settingsBackedUp++;
    }
    PREPARE_NAME();
    saveBusy = 1;
    oldMask = DISABLE_NAME();
    MASK_NAME(1);
    MASK_NAME(0x20401);
    for (delay = 0; delay <= 99999; delay++) {
    }
    READ_NAME(saveQueue, 0, &settingsRecord, sizeof(SettingsRecord));
    MASK_NAME(oldMask);
    saveBusy = 0;

    if (settingsRecord.tag != 'H'
        || settingsRecord.signature[0] != settingsSignature[0]
        || settingsRecord.signature[1] != settingsSignature[1]
        || settingsRecord.signature[2] != settingsSignature[2]) {
        gameContext->settings = settingsBackup;
        APPLY_NAME(0, 0, 0);
        return;
    }

    gameContext->settings.option04 = settingsRecord.option04;
    gameContext->settings.option06 = settingsRecord.option06;
    gameContext->settings.option07 = settingsRecord.option07;
    gameContext->settings.option08 = settingsRecord.option08;
    gameContext->settings.option09 = settingsRecord.option09;
    gameContext->settings.option12 = settingsRecord.option12;
    for (index = 0; index < 8; index++) {
        gameContext->settings.values[index] = settingsRecord.values[index];
    }
}
