#ifndef LEAF_NAME
#define LEAF_NAME callHelperThenGlobalHalfword
#endif
#ifndef FIRST_HELPER_NAME
#define FIRST_HELPER_NAME firstHelper
#endif
#ifndef SECOND_HELPER_NAME
#define SECOND_HELPER_NAME secondHelper
#endif
#ifndef GLOBAL_HI
#define GLOBAL_HI 0x8006
#endif
#ifndef GLOBAL_LO
#define GLOBAL_LO 0x5002
#endif

#define STRINGIFY_INNER(value) #value
#define STRINGIFY(value) STRINGIFY_INNER(value)

extern void FIRST_HELPER_NAME(void);
extern void SECOND_HELPER_NAME(unsigned int value);

void LEAF_NAME(void) {
    register unsigned int value asm("$4");

    FIRST_HELPER_NAME();
    asm volatile(
        ".set noreorder\n\t"
        "lui $2," STRINGIFY(GLOBAL_HI) "\n\t"
        "lhu %0," STRINGIFY(GLOBAL_LO) "($2)\n\t"
        ".set reorder"
        : "=r"(value));
    SECOND_HELPER_NAME(value);
}
