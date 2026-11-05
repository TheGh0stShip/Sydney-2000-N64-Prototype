/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800812D8\n.ent func_800812D8\n"
    "func_800812D8:\n"
    "jal func_800BC180\n"
    "addiu $4,$4,10968\n"
    "li $2,2\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,10968\n"
    ".end func_800812D8\n.set at\n.set reorder\n");
