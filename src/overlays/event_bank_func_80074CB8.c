/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074CB8\n.ent func_80074CB8\n"
    "func_80074CB8:\n"
    "addiu $2,$2,2792\n"
    "sll $3,$3,0x2\n"
    "addu $3,$3,$2\n"
    "lw $2,0($3)\n"
    "jr $2\n"
    "nop\n"
    ".end func_80074CB8\n.set at\n.set reorder\n");
