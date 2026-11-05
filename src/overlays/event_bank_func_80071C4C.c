/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071C4C\n.ent func_80071C4C\n"
    "func_80071C4C:\n"
    "addu $4,$4,$2\n"
    "sll $4,$4,0x2\n"
    "addu $4,$4,$21\n"
    "addiu $4,$4,1724\n"
    "li $2,0x8000\n"
    "jal func_800B9AD0\n"
    "sw $2,224($4)\n"
    ".end func_80071C4C\n.set at\n.set reorder\n");
