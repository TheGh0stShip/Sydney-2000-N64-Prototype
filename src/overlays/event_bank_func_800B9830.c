/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800B9830\n.ent func_800B9830\n"
    "func_800B9830:\n"
    "addiu $2,$2,3864\n"
    "sll $3,$3,0x2\n"
    "addu $3,$3,$2\n"
    "lw $2,0($3)\n"
    "jr $2\n"
    "nop\n"
    ".end func_800B9830\n.set at\n.set reorder\n");
