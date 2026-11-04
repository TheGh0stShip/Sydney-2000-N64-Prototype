#ifndef LEAF_NAME
#define LEAF_NAME initializeRuntimeMemory
#endif
#ifndef INITIALIZE_NAME
#define INITIALIZE_NAME initializeSystem
#endif
#ifndef MEMORY_SIZE_NAME
#define MEMORY_SIZE_NAME getMemorySize
#endif
#ifndef CLEAR_NAME
#define CLEAR_NAME clearMemory
#endif
#ifndef HEAP_NAME
#define HEAP_NAME initializeHeap
#endif
#ifndef CREATE_THREAD_NAME
#define CREATE_THREAD_NAME createThread
#endif
#ifndef START_THREAD_NAME
#define START_THREAD_NAME startThread
#endif
#ifndef EXPANSION_NAME
#define EXPANSION_NAME expansionMemoryAvailable
#endif
#ifndef HEAP_START_NAME
#define HEAP_START_NAME runtimeHeapStart
#endif
#ifndef HEAP_SIZE_NAME
#define HEAP_SIZE_NAME runtimeHeapSize
#endif
#ifndef THREAD_NAME
#define THREAD_NAME runtimeThread
#endif
#ifndef STACK_NAME
#define STACK_NAME runtimeStackTop
#endif
#ifndef ENTRY_NAME
#define ENTRY_NAME runtimeThreadEntry
#endif

typedef unsigned int u32;

extern u32 EXPANSION_NAME;
extern void *HEAP_START_NAME;
extern u32 HEAP_SIZE_NAME;
extern unsigned char THREAD_NAME[];
extern unsigned char STACK_NAME[];
extern void ENTRY_NAME(void *argument);
extern void INITIALIZE_NAME(void);
extern u32 MEMORY_SIZE_NAME(void);
extern void CLEAR_NAME(void *address, u32 value, u32 size);
extern void HEAP_NAME(void *address, u32 size);
extern void CREATE_THREAD_NAME(void *thread, u32 id, void (*entry)(void *),
                               void *argument, void *stack, u32 priority);
extern void START_THREAD_NAME(void *thread);

void LEAF_NAME(void) {
    u32 memorySize;
    u32 heapStart;
    u32 heapSize;

    INITIALIZE_NAME();
    memorySize = MEMORY_SIZE_NAME();
    if (memorySize == 0x800000) {
        EXPANSION_NAME = 1;
    }

    heapStart = (0xB01A7680 - 0xB0127640) + 0x80083D50;
    heapSize = memorySize - (heapStart & 0x7FFFFFFF);
    HEAP_START_NAME = (void *)heapStart;
    HEAP_SIZE_NAME = heapSize;
    CLEAR_NAME((void *)heapStart, 0, heapSize);
    HEAP_NAME((void *)HEAP_START_NAME, HEAP_SIZE_NAME);

    CREATE_THREAD_NAME(THREAD_NAME, 1, ENTRY_NAME, 0, STACK_NAME, 1);
    START_THREAD_NAME(THREAD_NAME);
}
