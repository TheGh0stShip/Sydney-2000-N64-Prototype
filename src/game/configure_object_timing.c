#ifndef LEAF_NAME
#define LEAF_NAME configureObjectTiming
#endif

#ifndef TIMER_BASE_NAME
#define TIMER_BASE_NAME objectTimerBase
#endif

#ifndef TIMER_VALUE_NAME
#define TIMER_VALUE_NAME objectTimerValue
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern u64 TIMER_BASE_NAME;
extern u32 TIMER_VALUE_NAME;
extern volatile const double objectDurationScale;
extern volatile const float objectDurationQuarter;
extern volatile const float objectDurationTriple;
extern volatile const float objectDurationFraction;

void LEAF_NAME(u8 **objectAddress, int count, u8 type, float duration) {
    u8 *object;
    float ticks;

    ticks = (float)((double)duration * objectDurationScale);
    __asm__ volatile ("" : : : "memory");
    object = *objectAddress;
    object[46] = type;
    object[44] = count - 1;
    ticks *= objectDurationQuarter;
    __asm__ volatile ("" : : : "memory");
    object[45] = 0;
    TIMER_BASE_NAME = 0;
    *(u16 *)(object + 40) = type;
    *(u32 *)(object + 128) |= 0x20;
    ticks *= objectDurationTriple;
    __asm__ volatile ("" : : : "memory");
    ticks *= objectDurationFraction;
    __asm__ volatile ("" : : : "memory");
    TIMER_VALUE_NAME = (u32)ticks;
}
