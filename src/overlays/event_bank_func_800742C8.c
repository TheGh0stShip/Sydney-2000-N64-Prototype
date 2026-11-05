/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800742C8\n.ent func_800742C8\n"
    "func_800742C8:\n"
    "li $2,9\n"
    "jal func_80083174\n"
    "addiu $4,$18,1584\n"
    "addiu $4,$18,28608\n"
    "lw $2,736($4)\n"
    ".word 0x10400004\n"
    ".end func_800742C8\n.set at\n.set reorder\n");
