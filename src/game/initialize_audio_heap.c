#ifndef LEAF_NAME
#define LEAF_NAME initializeAudioHeap
#endif
#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocateMemory
#endif
#ifndef RESIZE_NAME
#define RESIZE_NAME resizeMemory
#endif
#ifndef REGISTER_NAME
#define REGISTER_NAME registerAudioPointer
#endif
#ifndef INITIALIZE_NAME
#define INITIALIZE_NAME initializeAudioLibrary
#endif
#ifndef CONTEXT_NAME
#define CONTEXT_NAME memoryContext
#endif
#ifndef AUDIO_STATE_NAME
#define AUDIO_STATE_NAME audioState
#endif
#ifndef SCHEDULER_NAME
#define SCHEDULER_NAME scheduler
#endif
#ifndef CALLBACK_NAME
#define CALLBACK_NAME audioAllocationCallback
#endif

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 controlFlags;
    u32 channels;
    void *scheduler;
    u32 threadPriority;
    void *heap;
    u32 heapLength;
    void *pointerBank;
    void *waveBank;
    void *defaultEffectBank;
    u32 fifoLength;
    u32 updates;
    u32 outputRate;
    u32 commandCount;
    u32 retraceCount;
    u32 dmaBufferCount;
    u32 dmaBufferSize;
} AudioConfiguration;

typedef struct {
    AudioConfiguration configuration;
    u32 padding[2];
    u8 pointerBank[48];
} AudioInitialization;

extern u8 CONTEXT_NAME[];
extern u8 AUDIO_STATE_NAME[];
extern u8 SCHEDULER_NAME[];
extern void CALLBACK_NAME(void);
extern void ALLOCATE_NAME(void *context, void **output, u32 size, void (*callback)(void));
extern void RESIZE_NAME(void *context, void **output, u32 size);
extern void REGISTER_NAME(void *pointer);
extern u32 INITIALIZE_NAME(AudioConfiguration *configuration);

void LEAF_NAME(void) {
    AudioInitialization initialization;
    u32 size;

    *(void **)(AUDIO_STATE_NAME + 0x51F4) = 0;
    ALLOCATE_NAME(CONTEXT_NAME, (void **)(AUDIO_STATE_NAME + 0x51F4), 0x32000,
                  CALLBACK_NAME);

    initialization.configuration.controlFlags = 0;
    initialization.configuration.channels = 20;
    initialization.configuration.scheduler = SCHEDULER_NAME;
    initialization.configuration.threadPriority = 127;
    initialization.configuration.heap = *(void **)(AUDIO_STATE_NAME + 0x51F4);
    initialization.configuration.heapLength = 0x32000;
    initialization.configuration.pointerBank = initialization.pointerBank;
    initialization.configuration.waveBank = 0;
    initialization.configuration.defaultEffectBank = 0;
    initialization.configuration.fifoLength = 64;
    initialization.configuration.updates = 256;
    initialization.configuration.outputRate = 44100;
    initialization.configuration.commandCount = 4096;
    initialization.configuration.retraceCount = 1;
    initialization.configuration.dmaBufferCount = 72;
    initialization.configuration.dmaBufferSize = 512;

    REGISTER_NAME(AUDIO_STATE_NAME + 0x51F8);
    size = INITIALIZE_NAME(&initialization.configuration);
    *(u32 *)(AUDIO_STATE_NAME + 0x5208) = size;
    *(u32 *)(AUDIO_STATE_NAME + 0x51F0) = size;
    RESIZE_NAME(CONTEXT_NAME, (void **)(AUDIO_STATE_NAME + 0x51F4), size + 0x2800);
}
