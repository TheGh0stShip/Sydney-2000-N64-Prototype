typedef unsigned int u32;

#if defined(BUILD_GET_COUNT)

#ifndef GET_COUNT_NAME
#define GET_COUNT_NAME getCount
#endif

u32 GET_COUNT_NAME(void) {
    u32 value;
    asm volatile("mfc0 %0,$9" : "=r"(value));
    return value;
}

#elif defined(BUILD_SET_COMPARE)

#ifndef SET_COMPARE_NAME
#define SET_COMPARE_NAME setCompare
#endif

void SET_COMPARE_NAME(u32 value) {
    asm volatile("mtc0 %0,$11" : : "r"(value));
}

#else

#ifndef GET_CAUSE_NAME
#define GET_CAUSE_NAME getCause
#endif
#ifndef GET_STATUS_NAME
#define GET_STATUS_NAME getStatus
#endif
#ifndef SET_FPCSR_NAME
#define SET_FPCSR_NAME setFpcsr
#endif
#ifndef SET_STATUS_NAME
#define SET_STATUS_NAME setStatus
#endif
#ifndef SET_WATCH_NAME
#define SET_WATCH_NAME setWatch
#endif

u32 GET_CAUSE_NAME(void) {
    u32 value;
    asm volatile("mfc0 %0,$13" : "=r"(value));
    return value;
}

asm(".align 4");

u32 GET_STATUS_NAME(void) {
    u32 value;
    asm volatile("mfc0 %0,$12" : "=r"(value));
    return value;
}

asm(".align 4");

u32 SET_FPCSR_NAME(u32 value) {
    u32 previous;
    asm volatile("cfc1 %0,$31" : "=r"(previous));
    asm volatile("ctc1 %0,$31" : : "r"(value));
    return previous;
}

void SET_STATUS_NAME(u32 value) {
    asm volatile("mtc0 %0,$12\n\tnop" : : "r"(value));
}

void SET_WATCH_NAME(u32 value) {
    asm volatile("mtc0 %0,$18\n\tnop" : : "r"(value));
}

#endif
