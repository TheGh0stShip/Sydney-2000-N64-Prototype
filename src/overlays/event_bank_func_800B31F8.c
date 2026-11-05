/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800B31F8\n.ent func_800B31F8\n"
    "func_800B31F8:\n"
    "lui $4,0x8007\n"
    "jal func_800BA2D0\n"
    "addiu $4,$4,4656\n"
    "lui $4,0x8007\n"
    ".end func_800B31F8\n.set at\n.set reorder\n");
