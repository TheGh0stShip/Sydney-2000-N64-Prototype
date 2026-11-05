/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800742E0\n.ent func_800742E0\n"
    "func_800742E0:\n"
    "move $3,$0\n"
    "lbu $2,426($4)\n"
    "xori $2,$2,0x4\n"
    "sltu $3,$3,$2\n"
    ".word 0x10600004\n"
    "li $2,9\n"
    "jal func_80083174\n"
    "nop\n"
    ".end func_800742E0\n.set at\n.set reorder\n");
