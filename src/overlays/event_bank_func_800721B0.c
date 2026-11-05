/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800721B0\n.ent func_800721B0\n"
    "func_800721B0:\n"
    "lw $2,180($3)\n"
    "li $5,2\n"
    "lh $4,8($2)\n"
    ".end func_800721B0\n.set at\n.set reorder\n");
