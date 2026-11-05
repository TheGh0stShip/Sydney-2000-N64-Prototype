/*
 * Select one of two closing-screen resource bases, add the resource offset,
 * and submit it to the common loader.  This short unit retains symbolic MIPS
 * because SN GCC schedules the final adjustment into the call delay slot when
 * the same control flow is expressed as C.
 */
__asm__(
    ".set noreorder\n"
    ".text\n"
    ".globl func_800725C4\n"
    ".ent func_800725C4\n"
    "func_800725C4:\n"
    "addiu $sp,$sp,-24\n"
    "andi $5,$5,0xff\n"
    "beq $5,$0,1f\n"
    "sw $31,16($sp)\n"
    "lui $4,0x8007\n"
    "j 2f\n"
    "addiu $4,$4,0xc2c\n"
    "1:\n"
    "lui $4,0x8007\n"
    "2:\n"
    "addiu $4,$4,0xc3c\n"
    "jal func_8001CBA8\n"
    "nop\n"
    "lw $31,16($sp)\n"
    "jr $31\n"
    "addiu $sp,$sp,24\n"
    ".end func_800725C4\n"
    ".set reorder\n");
