#ifndef LEAF_NAME
#define LEAF_NAME cacheRuntime
#endif

#define STRINGIFY_INNER(value) #value
#define STRINGIFY(value) STRINGIFY_INNER(value)

#if defined(BUILD_INVAL_DCACHE)
#define CACHE_BODY \
    "blez $5,3f\n" \
    "nop\n" \
    "li $11,0x2000\n" \
    "sltu $1,$5,$11\n" \
    "beqz $1,4f\n" \
    "nop\n" \
    "move $8,$4\n" \
    "addu $9,$4,$5\n" \
    "sltu $1,$8,$9\n" \
    "beqz $1,3f\n" \
    "nop\n" \
    "addiu $9,$9,-16\n" \
    "andi $10,$8,15\n" \
    "beqz $10,1f\n" \
    "nop\n" \
    "subu $8,$8,$10\n" \
    "cache 0x15,0($8)\n" \
    "sltu $1,$8,$9\n" \
    "beqz $1,3f\n" \
    "nop\n" \
    "addiu $8,$8,16\n" \
    "1:\n" \
    "andi $10,$9,15\n" \
    "beqz $10,2f\n" \
    "nop\n" \
    "subu $9,$9,$10\n" \
    "cache 0x15,16($9)\n" \
    "sltu $1,$9,$8\n" \
    "bnez $1,3f\n" \
    "nop\n" \
    "2:\n" \
    "cache 0x11,0($8)\n" \
    "sltu $1,$8,$9\n" \
    "bnez $1,2b\n" \
    "addiu $8,$8,16\n" \
    "3:\n" \
    "jr $31\n" \
    "nop\n" \
    "4:\n" \
    "lui $8,0x8000\n" \
    "addu $9,$8,$11\n" \
    "addiu $9,$9,-16\n" \
    "5:\n" \
    "cache 1,0($8)\n" \
    "sltu $1,$8,$9\n" \
    "bnez $1,5b\n" \
    "addiu $8,$8,16\n" \
    "jr $31\n" \
    "nop\n"
#elif defined(BUILD_INVAL_ICACHE)
#define CACHE_BODY \
    "blez $5,2f\n" \
    "nop\n" \
    "li $11,0x4000\n" \
    "sltu $1,$5,$11\n" \
    "beqz $1,3f\n" \
    "nop\n" \
    "move $8,$4\n" \
    "addu $9,$4,$5\n" \
    "sltu $1,$8,$9\n" \
    "beqz $1,2f\n" \
    "nop\n" \
    "addiu $9,$9,-32\n" \
    "andi $10,$8,31\n" \
    "subu $8,$8,$10\n" \
    "1:\n" \
    "cache 0x10,0($8)\n" \
    "sltu $1,$8,$9\n" \
    "bnez $1,1b\n" \
    "addiu $8,$8,32\n" \
    "2:\n" \
    "jr $31\n" \
    "nop\n" \
    "3:\n" \
    "lui $8,0x8000\n" \
    "addu $9,$8,$11\n" \
    "addiu $9,$9,-32\n" \
    "4:\n" \
    "cache 0,0($8)\n" \
    "sltu $1,$8,$9\n" \
    "bnez $1,4b\n" \
    "addiu $8,$8,32\n" \
    "jr $31\n" \
    "nop\n"
#else
#define CACHE_BODY \
    "lui $8,0x8000\n" \
    "li $10,0x2000\n" \
    "addu $9,$8,$10\n" \
    "addiu $9,$9,-16\n" \
    "1:\n" \
    "cache 1,0($8)\n" \
    "sltu $1,$8,$9\n" \
    "bnez $1,1b\n" \
    "addiu $8,$8,16\n" \
    "jr $31\n" \
    "nop\n"
#endif

asm(
    ".text\n"
    ".align 2\n"
    ".globl " STRINGIFY(LEAF_NAME) "\n"
    STRINGIFY(LEAF_NAME) ":\n"
    ".set noreorder\n"
    CACHE_BODY
    ".set reorder\n");
