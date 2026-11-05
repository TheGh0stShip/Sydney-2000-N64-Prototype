/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071820\n.ent func_80071820\n"
    "func_80071820:\n"
    "move $4,$22\n"
    "li $5,1\n"
    "lw $3,192($6)\n"
    "li $2,-1537\n"
    "and $3,$3,$2\n"
    "lui $2,0x200\n"
    "or $3,$3,$2\n"
    "jal func_800ADC54\n"
    "sw $3,192($6)\n"
    "addu $16,$16,$21\n"
    "lw $2,1904($16)\n"
    "lh $4,64($2)\n"
    "lw $2,68($2)\n"
    ".end func_80071820\n.set at\n.set reorder\n");
