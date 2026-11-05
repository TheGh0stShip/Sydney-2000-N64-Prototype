/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800763D4\n.ent func_800763D4\n"
    "func_800763D4:\n"
    "addiu $16,$18,1224\n"
    "lui $4,0x8007\n"
    "jal func_800AEFA0\n"
    "addiu $4,$4,25904\n"
    "lui $4,0x8007\n"
    "jal func_800AEFA0\n"
    "addiu $4,$4,25920\n"
    ".end func_800763D4\n.set at\n.set reorder\n");
