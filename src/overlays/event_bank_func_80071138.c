/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071138\n.ent func_80071138\n"
    "func_80071138:\n"
    "li $6,10\n"
    "lw $4,200($21)\n"
    "jal func_8007E0D8\n"
    "li $7,1\n"
    "lw $3,200($21)\n"
    "lw $2,180($3)\n"
    "move $5,$21\n"
    "lh $4,16($2)\n"
    "lw $2,20($2)\n"
    "jalr $2\n"
    ".end func_80071138\n.set at\n.set reorder\n");
