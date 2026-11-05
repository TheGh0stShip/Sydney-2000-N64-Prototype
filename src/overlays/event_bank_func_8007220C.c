/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007220C\n.ent func_8007220C\n"
    "func_8007220C:\n"
    "li $5,2\n"
    "lh $4,8($2)\n"
    "lw $2,12($2)\n"
    "jalr $2\n"
    ".end func_8007220C\n.set at\n.set reorder\n");
