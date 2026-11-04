#ifndef LEAF_NAME
#define LEAF_NAME selectRandomAudioId
#endif

#ifndef RANDOM_NAME
#define RANDOM_NAME randomValue
#endif

#ifndef INVALIDATE_NAME
#define INVALIDATE_NAME invalidateId
#endif

#ifndef CREATE_NAME
#define CREATE_NAME createId
#endif

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 RANDOM_NAME(void);
extern void INVALIDATE_NAME(u16 id);
extern u32 CREATE_NAME(u32 source, u32 limit, u16 configuration);

extern u32 audioSelection;
extern u16 audioSelectionId;
extern u32 audioChoiceCount;
extern u32 audioUpdatePending;
extern u32 *audioIdTable;
extern volatile u32 audioIdConfiguration;

void LEAF_NAME(void) {
    register u32 randomIndex __asm__("$16");
    register unsigned char *selectionBase __asm__("$17") =
        (unsigned char *)0x80060000;

    randomIndex = RANDOM_NAME() % audioChoiceCount;
    __asm__("" : "=r"(randomIndex), "=r"(selectionBase)
            : "0"(randomIndex), "1"(selectionBase));
    randomIndex--;
    INVALIDATE_NAME(*(u16 *)(selectionBase + 0x5002));

    if (audioUpdatePending == 0) {
        *(u32 *)(selectionBase + 0x5000) = (u16)CREATE_NAME(
            audioIdTable[(u16)randomIndex], 64, (u16)audioIdConfiguration
        );
    }
}
