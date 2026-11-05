/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074390\n.ent func_80074390\n"
    "func_80074390:\n"
    "addiu $4,$22,1584\n"
    "jal func_8008382C\n"
    "addu $4,$18,$4\n"
    ".end func_80074390\n.set at\n.set reorder\n");
