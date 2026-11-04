#ifndef LEAF_NAME
#define LEAF_NAME updateDisplayRuntime
#endif
#ifndef STATE_NAME
#define STATE_NAME readDisplayState
#endif
#ifndef UPDATE_NAME
#define UPDATE_NAME updateDisplayRecords
#endif
#ifndef FIRST_MODE_NAME
#define FIRST_MODE_NAME runFirstDisplayMode
#endif
#ifndef SECOND_MODE_NAME
#define SECOND_MODE_NAME runSecondDisplayMode
#endif

typedef unsigned int u32;

extern u32 previousDisplayState __asm__("D_80043EF4");
extern u32 alternateDisplayState __asm__("D_80043EF8");
extern u32 displayResetState __asm__("D_80043E04");
extern volatile u32 *displayConfiguration __asm__("D_800F2774");
extern u32 selectedDisplayConfiguration __asm__("D_800F2778");
extern u32 displayConfigurationPending __asm__("D_800F2724");
extern u32 displayConfigurationReady __asm__("D_800F2728");
extern u32 displayMode __asm__("D_800F2C10");
extern u32 randomSeed __asm__("D_800F2C14");
extern u32 randomDisplayValue __asm__("D_800F3884");

extern u32 STATE_NAME(void);
extern void UPDATE_NAME(void);
extern void FIRST_MODE_NAME(void *configuration);
extern void SECOND_MODE_NAME(void);

void LEAF_NAME(void)
{
    u32 *configuration;
    u32 state;

    state = STATE_NAME();
    if (state != previousDisplayState) {
        if (STATE_NAME() != 0) {
            alternateDisplayState = 1;
            previousDisplayState = STATE_NAME();
        }
        if (STATE_NAME() == 0) {
            alternateDisplayState = 0;
            previousDisplayState = STATE_NAME();
        }
    }

    if (alternateDisplayState == 0) {
        (void)displayConfiguration;
        configuration = (u32 *)displayConfiguration + 64;
    } else {
        configuration = (u32 *)displayConfiguration;
    }

    if (displayConfigurationPending == 1) {
        selectedDisplayConfiguration = (u32)configuration;
        displayConfigurationReady = 1;
        displayConfigurationPending = 0;
        displayResetState = 0;
    }
    if (displayConfigurationReady == 0) {
        u32 seed = randomSeed;
        u32 reduced = (seed * 16807U) & 0x7FFFFFFFU;

        randomSeed = reduced;
        randomDisplayValue = ((reduced >> 15) * 0x00FFFFFFU) >> 16;
    }

    UPDATE_NAME();
    if (displayMode == 0) {
        FIRST_MODE_NAME(configuration);
    } else if (displayMode == 1) {
        SECOND_MODE_NAME();
    }
    displayConfiguration = configuration;
}
