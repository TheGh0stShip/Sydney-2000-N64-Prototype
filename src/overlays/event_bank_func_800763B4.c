/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800763B4\n.ent func_800763B4\n"
    "func_800763B4:\n"
    "lh $4,24($2)\n"
    "lw $2,28($2)\n"
    "jalr $2\n"
    "addu $4,$3,$4\n"
    ".end func_800763B4\n.set at\n.set reorder\n");
