/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800722E8\n.ent func_800722E8\n"
    "func_800722E8:\n"
    "addiu $16,$19,4464\n"
    "jal func_8007E098\n"
    "nop\n"
    "lw $3,200($19)\n"
    "lw $2,180($3)\n"
    "lh $4,24($2)\n"
    "lw $2,28($2)\n"
    "jalr $2\n"
    ".end func_800722E8\n.set at\n.set reorder\n");
