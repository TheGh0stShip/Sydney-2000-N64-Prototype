/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800794B0\n.ent func_800794B0\n"
    "func_800794B0:\n"
    "addu $2,$2,$8\n"
    "lw $7,3368($2)\n"
    "jal func_80074794\n"
    "nop\n"
    ".end func_800794B0\n.set at\n.set reorder\n");
