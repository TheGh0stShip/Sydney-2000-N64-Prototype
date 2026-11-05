/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800721EC\n.ent func_800721EC\n"
    "func_800721EC:\n"
    "lw $3,188($19)\n"
    "lw $2,180($3)\n"
    "lh $4,24($2)\n"
    "lw $2,28($2)\n"
    "jalr $2\n"
    "addu $4,$3,$4\n"
    "lw $3,188($19)\n"
    ".end func_800721EC\n.set at\n.set reorder\n");
