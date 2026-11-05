/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007229C\n.ent func_8007229C\n"
    "func_8007229C:\n"
    "lw $3,196($19)\n"
    "lw $2,180($3)\n"
    "lh $4,24($2)\n"
    "lw $2,28($2)\n"
    ".end func_8007229C\n.set at\n.set reorder\n");
