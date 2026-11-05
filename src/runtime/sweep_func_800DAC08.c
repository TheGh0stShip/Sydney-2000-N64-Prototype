/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800DAC08\n.ent func_800DAC08\n"
    "func_800DAC08:\n"
    "lui $2,0x8010\n"
    "addiu $2,$2,-13608\n"
    "andi $4,$4,0xff\n"
    "sll $4,$4,0x2\n"
    "addu $4,$4,$2\n"
    "lw $2,0($4)\n"
    "jr $31\n"
    "nop\n"
    ".end func_800DAC08\n.set at\n.set reorder\n");
