/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075C6C\n.ent func_80075C6C\n"
    "func_80075C6C:\n"
    "sll $3,$3,0x2\n"
    "addu $3,$3,$2\n"
    "lw $2,0($3)\n"
    "jr $2\n"
    "nop\n"
    ".end func_80075C6C\n.set at\n.set reorder\n");
