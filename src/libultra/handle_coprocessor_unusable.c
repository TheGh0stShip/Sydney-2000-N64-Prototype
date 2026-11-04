#ifndef LEAF_NAME
#define LEAF_NAME handleCoprocessorUnusable
#endif
#define STRINGIFY_INNER(value) #value
#define STRINGIFY(value) STRINGIFY_INNER(value)

asm(
    ".text\n"
    ".align 2\n"
    ".globl " STRINGIFY(LEAF_NAME) "\n"
    STRINGIFY(LEAF_NAME) ":\n"
    ".set noreorder\n"
    "lui $1,0x3000\n"
    "and $9,$8,$1\n"
    "srl $9,$9,28\n"
    "li $10,1\n"
    ".word 0x152affc0\n"
    "nop\n"
    "li $9,1\n"
    "sw $9,24($26)\n"
    "lw $27,280($26)\n"
    "lui $1,0x2000\n"
    "or $27,$27,$1\n"
    ".word 0x1000ffb3\n"
    "sw $27,280($26)\n"
    ".set reorder\n");
