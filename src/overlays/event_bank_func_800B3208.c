/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800B3208\n.ent func_800B3208\n"
    "func_800B3208:\n"
    "addiu $4,$4,4688\n"
    "jal func_800BA2D0\n"
    "sw $2,22968($23)\n"
    ".end func_800B3208\n.set at\n.set reorder\n");
