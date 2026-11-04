#ifndef LEAF_NAME
#define LEAF_NAME destroyRunningThread
#endif

#define STRINGIFY_INNER(value) #value
#define STRINGIFY(value) STRINGIFY_INNER(value)

asm(
    ".text\n"
    ".align 2\n"
    ".globl " STRINGIFY(LEAF_NAME) "\n"
    STRINGIFY(LEAF_NAME) ":\n"
    ".set noreorder\n"
    "move $4,$0\n"
    ".word 0x0c00cf98\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "nop\n"
    ".set reorder\n");
