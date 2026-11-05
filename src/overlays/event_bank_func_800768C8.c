/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800768C8\n.ent func_800768C8\n"
    "func_800768C8:\n"
    "jal func_800AACB0\n"
    "move $6,$0\n"
    "addu $2,$17,$19\n"
    "lw $2,1764($2)\n"
    "lh $4,24($2)\n"
    "lw $2,28($2)\n"
    "jalr $2\n"
    "addu $4,$16,$4\n"
    "j func_80073504\n"
    ".end func_800768C8\n.set at\n.set reorder\n");
