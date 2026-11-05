/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007E3B0\n.ent func_8007E3B0\n"
    "func_8007E3B0:\n"
    "lw $2,21356($19)\n"
    "sll $6,$21,0x18\n"
    "sb $0,427($2)\n"
    "lw $4,21356($19)\n"
    "sra $6,$6,0x18\n"
    "jal func_8009A828\n"
    "addiu $4,$4,404\n"
    "lui $2,0x8010\n"
    "lw $2,-15760($2)\n"
    "lw $2,2564($2)\n"
    ".word 0x14400003\n"
    "nop\n"
    "lw $2,21356($19)\n"
    ".end func_8007E3B0\n.set at\n.set reorder\n");
