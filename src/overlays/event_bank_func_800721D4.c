/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800721D4\n.ent func_800721D4\n"
    "func_800721D4:\n"
    "addiu $5,$19,184\n"
    "lw $4,188($19)\n"
    ".word 0x10800014\n"
    "nop\n"
    "jal func_8007E230\n"
    "nop\n"
    ".end func_800721D4\n.set at\n.set reorder\n");
