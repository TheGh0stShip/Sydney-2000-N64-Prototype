#ifndef LEAF_NAME
#define LEAF_NAME interruptRuntime
#endif

#define STRINGIFY_INNER(value) #value
#define STRINGIFY(value) STRINGIFY_INNER(value)

#if defined(BUILD_GET_MASK)
#define INTERRUPT_BODY \
    "mfc0 $2,$12\n" \
    "andi $2,$2,0xff01\n" \
    "lui $8,0x8007\n" \
    "addiu $8,$8,-31664\n" \
    "lw $9,0($8)\n" \
    "li $1,-1\n" \
    "xor $8,$9,$1\n" \
    "andi $8,$8,0xff00\n" \
    "or $2,$2,$8\n" \
    "lui $9,0xa430\n" \
    "lw $9,12($9)\n" \
    "beqz $9,1f\n" \
    "lui $8,0x8007\n" \
    "addiu $8,$8,-31664\n" \
    "lw $8,0($8)\n" \
    "srl $8,$8,16\n" \
    "li $1,-1\n" \
    "xor $8,$8,$1\n" \
    "andi $8,$8,0x3f\n" \
    "or $9,$9,$8\n" \
    "1:\n" \
    "sll $10,$9,16\n" \
    "or $2,$2,$10\n" \
    "jr $31\n" \
    "nop\n"
#else
#define INTERRUPT_BODY \
    "mfc0 $8,$12\n" \
    "or $8,$8,$4\n" \
    "mtc0 $8,$12\n" \
    "nop\n" \
    "nop\n" \
    "jr $31\n" \
    "nop\n"
#endif

asm(
    ".text\n"
    ".align 2\n"
    ".globl " STRINGIFY(LEAF_NAME) "\n"
    STRINGIFY(LEAF_NAME) ":\n"
    ".set noreorder\n"
    INTERRUPT_BODY
    ".set reorder\n");
