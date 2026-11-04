#ifndef LEAF_NAME
#define LEAF_NAME tlbRuntime
#endif

#define STRINGIFY_INNER(value) #value
#define STRINGIFY(value) STRINGIFY_INNER(value)

#if defined(BUILD_MAP_RDB)
#define TLB_BODY \
    "mfc0 $8,$10\n" \
    "li $9,31\n" \
    "mtc0 $9,$0\n" \
    "mtc0 $0,$5\n" \
    "li $10,23\n" \
    "lui $9,0xc000\n" \
    "mtc0 $9,$10\n" \
    "lui $9,0x8000\n" \
    "srl $11,$9,6\n" \
    "or $11,$11,$10\n" \
    "mtc0 $11,$2\n" \
    "li $9,1\n" \
    "mtc0 $9,$3\n" \
    "nop\n" \
    "tlbwi\n" \
    "nop\n" \
    "nop\n" \
    "nop\n" \
    "nop\n" \
    "mtc0 $8,$10\n" \
    "jr $31\n" \
    "nop\n"
#else
#define TLB_BODY \
    "mfc0 $8,$10\n" \
    "li $9,30\n" \
    "lui $10,0x8000\n" \
    "mtc0 $10,$10\n" \
    "mtc0 $0,$2\n" \
    "mtc0 $0,$3\n" \
    "1:\n" \
    "mtc0 $9,$0\n" \
    "nop\n" \
    "tlbwi\n" \
    "nop\n" \
    "nop\n" \
    "addi $9,$9,-1\n" \
    "bgez $9,1b\n" \
    "nop\n" \
    "mtc0 $8,$10\n" \
    "jr $31\n" \
    "nop\n"
#endif

asm(
    ".text\n"
    ".align 2\n"
    ".globl " STRINGIFY(LEAF_NAME) "\n"
    STRINGIFY(LEAF_NAME) ":\n"
    ".set noreorder\n"
    TLB_BODY
    ".set reorder\n");
