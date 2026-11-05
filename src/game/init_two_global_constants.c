#ifndef LEAF_NAME
#define LEAF_NAME initTwoGlobalConstants
#endif

#ifndef FIRST_GLOBAL
#define FIRST_GLOBAL firstGlobal
#endif

#ifndef FIRST_VALUE
#define FIRST_VALUE 0
#endif

#ifndef SECOND_GLOBAL
#define SECOND_GLOBAL secondGlobal
#endif

#ifndef SECOND_VALUE
#define SECOND_VALUE 0
#endif

#define STRINGIFY_INNER(value) #value
#define STRINGIFY(value) STRINGIFY_INNER(value)

extern int FIRST_GLOBAL;
extern int SECOND_GLOBAL;

void LEAF_NAME(void) {
    register int first asm("$2");
    register int second asm("$3");

    asm volatile ("addiu %0,$0," STRINGIFY(FIRST_VALUE) : "=r" (first));
    second = SECOND_VALUE;
    asm volatile ("" : "=r" (first), "=r" (second) : "0" (first), "1" (second));
    FIRST_GLOBAL = first;
    SECOND_GLOBAL = second;
    asm volatile ("# stores complete" : : : "memory");
}

#ifdef TRAILING_NOP
asm(".word 0");
#endif
