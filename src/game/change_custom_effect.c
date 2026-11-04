#ifndef LEAF_NAME
#define LEAF_NAME changeCustomEffect
#endif
#ifndef REINITIALIZE_NAME
#define REINITIALIZE_NAME reinitializeEffect
#endif
#ifndef SET_PARAMETER_NAME
#define SET_PARAMETER_NAME setFilterParameter
#endif

typedef struct AudioState {
    char reserved[0x34];
    void *auxiliaryBus;
} AudioState;

extern int effectCount;
extern void *effects[];
extern AudioState *audioState;
extern void REINITIALIZE_NAME(void *effect);
extern void SET_PARAMETER_NAME(void *filter, int parameter, void *value);

int LEAF_NAME(int type)
{
    char *auxiliaryBus;

    if (type >= effectCount) {
        return 1;
    }
    REINITIALIZE_NAME(effects[type]);
    auxiliaryBus = audioState->auxiliaryBus;
    SET_PARAMETER_NAME(*(void **)(auxiliaryBus + 0x20), 1, auxiliaryBus);
    return 0;
}
