#ifndef LEAF_NAME
#define LEAF_NAME freeParam
#endif

#ifndef GLOBALS_NAME
#define GLOBALS_NAME audioGlobals
#endif

typedef struct AudioParam {
    struct AudioParam *next;
} AudioParam;

typedef struct AudioSynth {
    char reserved[0x2C];
    AudioParam *parameterList;
} AudioSynth;

extern AudioSynth *GLOBALS_NAME;

void LEAF_NAME(AudioParam *parameter) {
    parameter->next = GLOBALS_NAME->parameterList;
    GLOBALS_NAME->parameterList = parameter;
}
