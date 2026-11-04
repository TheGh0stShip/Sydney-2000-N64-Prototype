#ifndef LEAF_NAME
#define LEAF_NAME enqueueThread
#endif

#define STRINGIFY_INNER(value) #value
#define STRINGIFY(value) STRINGIFY_INNER(value)

asm(
    ".text\n"
    ".align 2\n"
    ".globl " STRINGIFY(LEAF_NAME) "\n"
    STRINGIFY(LEAF_NAME) ":\n"
    ".set noreorder\n"
    "move $25,$4\n"
    "lw $24,0($4)\n"
    "lw $15,4($5)\n"
    "lw $14,4($24)\n"
    "slt $1,$14,$15\n"
    "bnez $1,2f\n"
    "nop\n"
    "1:\n"
    "move $25,$24\n"
    "lw $24,0($24)\n"
    "lw $14,4($24)\n"
    "slt $1,$14,$15\n"
    "beqz $1,1b\n"
    "nop\n"
    "2:\n"
    "lw $24,0($25)\n"
    "sw $24,0($5)\n"
    "sw $5,0($25)\n"
    "jr $31\n"
    "sw $4,8($5)\n"
    ".set reorder\n");
