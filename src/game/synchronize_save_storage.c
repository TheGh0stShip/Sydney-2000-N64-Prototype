#ifndef LEAF_NAME
#define LEAF_NAME synchronizeSaveStorage
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
#ifndef WRITE_NAME
#define WRITE_NAME writeSaveStorage
#endif

typedef unsigned int u32;
typedef unsigned char u8;

extern u32 saveSize __asm__("D_80044608");
extern u32 saveBusy __asm__("D_80043724");
extern u8 saveQueue[] __asm__("D_80044804");
extern u8 saveBuffer[] __asm__("D_80044850");
extern u8 gameContext[] __asm__("D_800FC270");

extern u32 DISABLE_NAME(void);
extern u32 MASK_NAME(u32 mask);
extern void READ_NAME(void *queue, u32 address, void *buffer, u32 size);
extern void WRITE_NAME(void *queue, u32 address, void *buffer, u32 size);

void LEAF_NAME(void)
{
    u32 oldMask;
    u32 index;

    if (saveSize != 2048) {
        return;
    }
    saveBusy = 1;
    oldMask = DISABLE_NAME();
    MASK_NAME(1);
    MASK_NAME(0x20401);
    for (index = 0; index <= 99999; index += 2) {
    }
    READ_NAME(saveQueue, 0, saveBuffer, 2032);
    MASK_NAME(oldMask);
    saveBusy = 0;

    if (*(u32 *)(saveBuffer + 28) == 73) {
        for (index = 0; index < 2000; index++) {
            gameContext[0x20C + index] = saveBuffer[32 + index];
        }
        return;
    }

    if (saveSize != 2048) {
        return;
    }
    saveBusy = 1;
    oldMask = DISABLE_NAME();
    MASK_NAME(1);
    MASK_NAME(0x20401);
    for (index = 0; index < 2000; index++) {
        saveBuffer[32 + index] = gameContext[0x20C + index];
    }
    *(u32 *)(saveBuffer + 28) = 73;
    for (index = 0; index <= 99999; index += 2) {
    }
    WRITE_NAME(saveQueue, 0, saveBuffer, 2032);
    MASK_NAME(oldMask);
    saveBusy = 0;
}
