#ifndef LEAF_NAME
#define LEAF_NAME writebackDCache
#endif

#define STRINGIFY_INNER(value) #value
#define STRINGIFY(value) STRINGIFY_INNER(value)

asm(
    ".text\n"
    ".align 2\n"
    ".globl " STRINGIFY(LEAF_NAME) "\n"
    STRINGIFY(LEAF_NAME) ":\n"
    ".set noreorder\n"
    "blez $5,2f\n"
    "nop\n"
    "li $11,0x2000\n"
    "sltu $1,$5,$11\n"
    "beqz $1,3f\n"
    "nop\n"
    "move $8,$4\n"
    "addu $9,$4,$5\n"
    "sltu $1,$8,$9\n"
    "beqz $1,2f\n"
    "nop\n"
    "addiu $9,$9,-16\n"
    "andi $10,$8,15\n"
    "subu $8,$8,$10\n"
    "1:\n"
    "cache 0x19,0($8)\n"
    "sltu $1,$8,$9\n"
    "bnez $1,1b\n"
    "addiu $8,$8,16\n"
    "2:\n"
    "jr $31\n"
    "nop\n"
    "3:\n"
    "lui $8,0x8000\n"
    "addu $9,$8,$11\n"
    "addiu $9,$9,-16\n"
    "4:\n"
    "cache 1,0($8)\n"
    "sltu $1,$8,$9\n"
    "bnez $1,4b\n"
    "addiu $8,$8,16\n"
    "jr $31\n"
    "nop\n"
    ".set reorder\n");
