#ifndef LEAF_NAME
#define LEAF_NAME installExceptionVectors
#endif
#ifndef CACHE_NAME
#define CACHE_NAME sweepCaches
#endif
#ifndef STATUS_NAME
#define STATUS_NAME configureStatus
#endif

typedef unsigned int u32;

extern u32 errorVectorSource[] __asm__("func_80029150");
extern u32 errorVectorBackup[] __asm__("D_80029164");
extern u32 generalVectorSource[] __asm__("D_80029188");
extern u32 generalVectorBackup[] __asm__("D_8002919C");
extern u32 runtimeClockRate __asm__("D_8006D3B8");
extern u32 runtimeStatus __asm__("D_8006D3C0");

extern void CACHE_NAME(void);
extern void STATUS_NAME(void);

void LEAF_NAME(void)
{
    volatile u32 *destination;
    u32 *source;
    u32 *backup;
    u32 i;

    source = errorVectorSource;
    backup = errorVectorBackup;
    destination = (volatile u32 *)0x80000180;
    for (i = 0; i < 5; i++) {
        u32 old = *destination;
        *backup++ = old;
        *destination++ = *source++;
    }

    source = generalVectorSource;
    backup = generalVectorBackup;
    destination = (volatile u32 *)0x80000000;
    for (i = 0; i < 5; i++) {
        u32 old = *destination;
        *backup++ = old;
        *destination++ = *source++;
    }

    CACHE_NAME();
    STATUS_NAME();
    runtimeClockRate = 0xFFFFF7FE;
    runtimeStatus = 0;
}
