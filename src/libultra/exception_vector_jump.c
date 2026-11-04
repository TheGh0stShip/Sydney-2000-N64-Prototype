#ifndef LEAF_NAME
#define LEAF_NAME exceptionVectorJump
#endif
#ifndef TARGET_HI
#define TARGET_HI 0x8000
#endif
#ifndef TARGET_LO
#define TARGET_LO 0
#endif

#define STRINGIFY_INNER(value) #value
#define STRINGIFY(value) STRINGIFY_INNER(value)

asm(
    ".text\n"
    ".align 2\n"
    ".globl " STRINGIFY(LEAF_NAME) "\n"
    STRINGIFY(LEAF_NAME) ":\n"
    ".set noreorder\n"
    "lui $26," STRINGIFY(TARGET_HI) "\n"
#if defined(USE_ADDIU)
    "addiu $26,$26," STRINGIFY(TARGET_LO) "\n"
#else
    "ori $26,$26," STRINGIFY(TARGET_LO) "\n"
#endif
    "jr $26\n"
    "nop\n"
    ".set reorder\n");
